# Rewrite mysqldump's triggers as plain SQL, for deploy_on_vps.sh.
#
#   /*!50003 CREATE*/ /*!50017 DEFINER=`u`@`h`*/ /*!50003 TRIGGER ... body ... */;;
# becomes
#   CREATE TRIGGER ... body ... ;;
#
# mysqldump wraps every trigger in version comments. A trigger whose body ends
# in a line break (or spans lines) leaves the closing */ on a later line, and
# the MySQL 8.0.46 client sends that as a stray " */" ("near ' */' at line 2").
# Plain CREATE TRIGGER parses the same on every version. Dropping the DEFINER
# makes the trigger belong to whoever loads the dump.
#
# Run with LC_ALL=C: the dump's rows are CP949 bytes and must pass untouched.
BEGIN { intrig = 0 }
{
    line = $0
    if (!intrig && line ~ /^\/\*!50003 CREATE\*\/ \/\*!50017 DEFINER=[^*]*\*\/ \/\*!50003 TRIGGER /) {
        sub(/^\/\*!50003 CREATE\*\/ \/\*!50017 DEFINER=[^*]*\*\/ \/\*!50003 /, "CREATE ", line)
        intrig = 1
    }
    if (intrig && line ~ /\*\/;;\r?$/) {
        sub(/ ?\*\/;;\r?$/, ";;", line)
        intrig = 0
    }
    print line
}
