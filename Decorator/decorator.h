/*
 * decorator.h
 *
 *  Created on: Sep 21, 2012
 *      Author: hl
 *  又是虚函数的力量，调用方法和接口不变，只需要改变调用对象！
 */

#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include <iostream>
using namespace std;

/**
 * @brief 成绩单
 */
class SchoolReport
{
public:
	virtual void reaport() = 0;
	virtual void sign(string name) = 0;
};

/**
 * @brief 第四学期成绩单
 */
class FouthGradeSchoolReport : public SchoolReport
{
public:
	void reaport();
	void sign(string name);
};

/**
 * @brief 装饰器 - 包装下成绩单，增加排名之类的！
 */
class Decorator : public SchoolReport
{
public:
	void reaport()
	{
		fouth.reaport();
		rank();
	}
	void rank()
	{
		cout << "排名 32" << endl;
	}
	void sign(string name)
	{
		fouth.sign(name);
	}
private:
	FouthGradeSchoolReport fouth;
};

#endif /* _DECORATOR_H_ */
