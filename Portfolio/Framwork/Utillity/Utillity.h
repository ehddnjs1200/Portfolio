#pragma once

// ��Ƽ����Ʈ -> �����ڵ�
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

