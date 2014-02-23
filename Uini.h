#pragma once

class CUini
{
public:
	CUini(const CString sIniPath);
	~CUini(void);
	
	int GetInt(const CString sAppName, const CString sKeyName);
	// 获取字符串为16进制的int
	int GetHexInt(const CString sAppName, const CString sKeyName);
	// 获取字符串为16进制的long long
	long long GetHexLongLong(const CString sAppName, const CString sKeyName);
	double GetDouble(const CString sAppName, const CString sKeyName);
	float GetFloat(const CString sAppName, const CString sKeyName);
	CString GetCString(const CString sAppName, const CString sKeyName);

private:
	CString m_sIniPath;
};
