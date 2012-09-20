//============================================================================
// Name        : adapter.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : adapter in C++, Ansi-style
//============================================================================
#include "adapter.h"

map<int, string> * OtherInfo::getBasicInfo()
{
	map<int ,string> * mp = new map<int ,string>;
	mp->insert(pair<int, string>(0, "hl"));
	mp->insert(pair<int, string>(1, "110"));

	return mp;
}

string UserInfo::getName()
{
	cout << "得到员工姓名" << endl;
	return NULL;
}

string UserInfo::getMobile()
{
	cout << "得到手机号" << endl;
	return NULL;
}

string Adapter::getName()
{
	return fun.getOName();
}
string Adapter::getMobile()
{
	return fun.getOMobile();
}

int main()
{
	CommonUser * puser = new Adapter();
	cout << puser->getMobile() << endl;
	cout << puser->getName() << endl;
	delete puser;

	return 0;
}
