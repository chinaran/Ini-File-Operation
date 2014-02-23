// English
This is a class for operating *.ini configure file.
It's very convenient to get or set data from ini files (by using CString).
There are just some simple method, and you can change and add your own methods.
The class only can be used in Visual C++.
File Map:
	Ini.h: the declare of CIni class.
	Ini.h: define methods of CIni class
	Demo.h: show how to ues the class

//// If you have any problem, please contect Aran (gchinaran@gmail.com)


// 中文
这是一个操作ini配置文件的类,其实是对VC中的GetPrivateProfileString和WritePrivateProfileString的重新封装（Aran对CString过于喜爱），
注重的是方便和简洁，没有做到严密性（如有此要求，可自行修改）。
该类应应用在Visual C++ 环境中

操作方法请参看Ini.h文件，
方法的实现为Ini.cpp文件（这个文件几乎没有注释）。
使用示例见Demo.cpp文件

//// 如有问题，请联系阿然 gchinaran@gmail.com


///////// Demo.h
/*
* show how to used the ini operate methods
*/

#include "Ini.h"
#include <iostream>
using namespace std;

int main(void)
{
	CIni cIni("D:/iniTest.ini");

	// set values
	CString sNode = "TestNode"; // node name
	cIni.SetInt(sNode, "IntKey", -123);
	cIni.SetDouble(sNode, "DoubleKey", 123.0987);
	cIni.SetFloat(sNode, "FloatKey", -56.2f);
	cIni.SetCstring(sNode, "CStringKey", CString("hello, ini!"));
	cIni.SetPchar(sNode, "PcharKey", "Can you feel me?");

	// get key values
	cout << "show key values:" << endl;
	cout << "IntKey = " << cIni.GetInt(sNode, "IntKey") << endl;
	cout << "DoubleKey = " << cIni.GetDouble(sNode, "DoubleKey") << endl;
	cout << "FloatKey = " << cIni.GetFloat(sNode, "FloatKey") << endl;
	cout << "CStringKey = " << cIni.GetCString(sNode, "CStringKey") << endl;
	CString str = cIni.GetCString(sNode, "PcharKey");
	char *pch = (LPSTR)(LPCTSTR)str;
	cout << "PcharKey = " << pch << endl;

	return 0;
}