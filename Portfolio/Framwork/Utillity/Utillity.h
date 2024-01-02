#pragma once

// 멀티바이트 -> 유니코드
// string -> wstring

static string WstringToString(wstring wstr)
{
	string str;
	str.reserve(wstr.length() + 1); // L
	for(auto a : wstr)
	{
		str.push_back(a);
	}
	return str;
}

