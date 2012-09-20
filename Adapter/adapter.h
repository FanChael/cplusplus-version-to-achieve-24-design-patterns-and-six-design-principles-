/*
 * adapter.h
 *
 *  Created on: Sep 20, 2012
 *      Author: hl
 *  感觉改了这么多，最终就是封装了一个包含所有的方法的common类，类中实现了所有情况的方法，然后根据情况去调用相应
 *  的方法来实现适配！好麻烦啊，不过这样可以不用去动本公司的代码和其他公司的代码！
 */

#ifndef _ADAPTER_H_
#define _ADAPTER_H_
#include <iostream>
#include <string>
#include <map>

using namespace std;

class CommonUser
{
public:
	virtual string getName() = 0;
	virtual string getMobile() = 0;
};

//----------------该部分可以不用动！就这点好处---------------------------
/**
 * @brief 本公司员工管理
 */
class UserInfo
{
public:
	string getName();
	string getMobile();
};

/**
 * @brief 其他公司员工管理
 */
class OtherInfo
{
public:
	map<int, string> * getBasicInfo();
};
//------------------------------------------

/**
 * brief 为了实现适配器
 */
class Function
{
public:
	Function()
	{
		pmp = oinf.getBasicInfo();
	}
	~Function()
	{
		delete pmp;
	}
public:
	string getName()
	{
		cout << "得到员工姓名" << endl;
		return NULL;
	}
	string getMobile()
	{
		cout << "得到手机号" << endl;
		return NULL;
	}
	string getOName()
	{
		map<int ,string>::iterator l_it;
		l_it = pmp->find(0);

		return l_it->second;
	}
	string getOMobile()
	{
		map<int ,string>::iterator l_it;
		l_it = pmp->find(1);

		return l_it->second;
	}
private:
	OtherInfo oinf;
	map<int ,string> * pmp;
};

/**
 * @brief 适配器，为了本公司能够搞到其他公司的员工信息！
 * 感觉就是在原来的基础上封了一层???
 */
class Adapter : public CommonUser
{
public:
	string getName();
	string getMobile();
private:
	Function fun;
};


#endif /* _ADAPTER_H_ */
