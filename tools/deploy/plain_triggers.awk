# Rewrite mysqldump's triggers as plain SQL, for deploy_on_vps.sh.
#
#   /*!50003 CREATE*/ /*!50017 DEFINER=`u`@`h`*/ /*!50003 TRIGGER ... body ... */;;
# becomes
#   CREATE TRIGGER ... body ;;
#
# The VPS's triggers were loaded by a tool that kept the end of each statement,
# so their stored text ends in CR LF ";" (0D 0A 3B). Dumped, that is
#   ... 0)^M
#   ; */;;
# and the extra ";" runs into the ";;" delimiter, cutting the statement in the
# wrong place (errors "near ' */'" and "near ';  DELIMITER ;'"). Trailing
# semicolons, blanks and CRs are empty statements, so the body is cut back to
# its last real character; the copy's triggers do exactly what the originals do.
# Dropping the version comments and the DEFINER makes the triggers plain SQL
# that belongs to whoever loads the dump.
#
# Run with LC_ALL=C: the dump's rows are CP949 bytes and must pass untouched.

function trim_end(s) { sub(/[ \t\r;]+$/, "", s); return s }

BEGIN { intrig = 0; have = 0 }
{
    line = $0
    if (!intrig && line ~ /^\/\*!50003 CREATE\*\/ \/\*!50017 DEFINER=[^*]*\*\/ \/\*!50003 TRIGGER /) {
        sub(/^\/\*!50003 CREATE\*\/ \/\*!50017 DEFINER=[^*]*\*\/ \/\*!50003 /, "CREATE ", line)
        intrig = 1
    }
    if (!intrig) { print line; next }

    # inside a trigger: hold one line back, so the end of the body can be trimmed
    if (line ~ /\*\/;;\r?$/) {
        sub(/[ \t\r;]*\*\/;;\r?$/, "", line)
        if (line ~ /^[ \t\r]*$/) {
            # the closing line held nothing else: the body ended on the line before
            if (have) print trim_end(held)
            print ";;"
        } else {
            if (have) print held
            print trim_end(line) ";;"
        }
        have = 0; intrig = 0
        next
    }
    if (have) print held
    held = line; have = 1
}
END { if (have) print held }
