#ifndef __GQUEST_MISSION_STATE_H__
#define __GQUEST_MISSION_STATE_H__

//////////////////////////////////////////////////////////////////////////////
// Helpers for GQuestMission::saveState() / loadState() (KAN-13).
//
// An accepted quest survives logout: each of its missions is written to
// GQuestMissionSave, and the element-specific part of a mission (a flag, a
// counter, the monsters picked for a kill quest, a travel route) goes into
// the State column as a short text field built with these helpers.
//////////////////////////////////////////////////////////////////////////////

#include "Types.h"

#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

namespace GQuestMissionState
{
	inline string fromBool(bool b) { return b ? "1" : "0"; }
	inline bool toBool(const string& s) { return !s.empty() && s[0] == '1'; }

	inline string fromDWORD(DWORD v)
	{
		char buf[16];
		sprintf(buf, "%lu", (unsigned long)v);
		return buf;
	}
	inline DWORD toDWORD(const string& s) { return (DWORD)strtoul(s.c_str(), (char**)NULL, 10); }

	// "3,17,42"
	template<class T>
	inline string fromList(const vector<T>& v)
	{
		string ret;
		for ( size_t i = 0; i < v.size(); ++i )
		{
			if ( i ) ret += ",";
			ret += fromDWORD((DWORD)v[i]);
		}
		return ret;
	}

	template<class T>
	inline void toList(const string& s, vector<T>& out)
	{
		out.clear();
		size_t pos = 0;
		while ( pos < s.size() )
		{
			size_t comma = s.find(',', pos);
			if ( comma == string::npos ) comma = s.size();
			if ( comma > pos ) out.push_back((T)toDWORD(s.substr(pos, comma - pos)));
			pos = comma + 1;
		}
	}

	// "a;b" -> a, b  (b is empty when there is no ';')
	inline void split2(const string& s, string& a, string& b)
	{
		size_t semi = s.find(';');
		if ( semi == string::npos )
		{
			a = s;
			b = "";
		}
		else
		{
			a = s.substr(0, semi);
			b = s.substr(semi + 1);
		}
	}
}

#endif
