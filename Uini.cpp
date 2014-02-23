#include "StdAfx.h"
#include "Uini.h"

CUini::CUini(const CString sIniPath)
{
	m_sIniPath = sIniPath;
}

CUini::~CUini(void)
{
}

int CUini::GetInt(const CString sAppName, const CString sKeyName)
{
	return GetPrivateProfileInt(sAppName, sKeyName, 0, m_sIniPath);
}

int CUini::GetHexInt(const CString sAppName, const CString sKeyName)
{
	char s[MAX_PATH];
	GetPrivateProfileString(sAppName, sKeyName, "0", s, MAX_PATH, m_sIniPath);
	int i;
	sscanf(s, "%x",&i);
	return i;
}

long long CUini::GetHexLongLong(const CString sAppName, const CString sKeyName)
{
	char s[MAX_PATH];
	GetPrivateProfileString(sAppName, sKeyName, "0", s, MAX_PATH, m_sIniPath);
	long long ll;
	sscanf(s, "%l64x",&ll);
	return ll;
}

double CUini::GetDouble(const CString sAppName, const CString sKeyName)
{
	char s[MAX_PATH];
	GetPrivateProfileString(sAppName, sKeyName, "0", s, MAX_PATH, m_sIniPath);
	return atof(s);
}

float CUini::GetFloat(const CString sAppName, const CString sKeyName)
{
	return (float)GetDouble(sAppName, sKeyName);
}

CString CUini::GetCString(const CString sAppName, const CString sKeyName)
{
	char temp[MAX_PATH];
	GetPrivateProfileString(sAppName, sKeyName, "", temp, MAX_PATH, m_sIniPath);
	CString str;
	str.Format("%s", temp);
	return str;
}