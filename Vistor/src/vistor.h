/*
 * vistor.h
 * brief 我的初步理解：定义了一个访问者去访问各个不同职能的类；去获取他们的信息，加以修改后去显示信息！这就是
 * 我的目的。这样可以不同动原先拥有的代码。只需要加以包装就可以完成改造！不知的对不对，等以后水平高了，就...
 *  Created on: Sep 25, 2012
 *      Author: hl
 */

#ifndef _VISTOR_H_
#define _VISTOR_H_
#include <string>
using namespace std;

/**
 * @brief 报表
 */
class Form
{
public:
	virtual string baseInfo() = 0;
};

/**
 * @brief 普通员工类
 */
class Employee : public Form
{
public:
	string baseInfo();
};

/**
 * @brief 经理类
 */
class Manager
{
public:
	string baseInfo();
};

/**
 * @brief 访问者
 */
class Vistor
{
public:
	Vistor(Employee * pEmployee)
	{
		info = pEmployee->baseInfo() + "\n我是普通员工";
	}
	Vistor(Manager * pManager)
	{
		info = pManager->baseInfo() + "\n我是经理";
	}
public:
	string info;
};

/**
 * @brief 显示报表
 */
class ShowVistor
{
public:
	void Export(Vistor * vis);
};


#endif /* _VISTOR_H_ */
