//============================================================================
// Name        : iterator.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : Iterator Pattern in C++, Ansi-style
//============================================================================

#include "iterator.h"
#include <iostream>
using namespace std;


Project::Project(string proName, double money, string time)
{
	this->_proName = proName;
	this->_money = money;
	this->_time = time;
}

void Project::show()
{
	cout << "项目名称: " << this->_proName << " 项目资金: "
			<< this->_money << " 项目启动时间: " << this->_time;
}

ProManager::ProManager()
{
	this->vec = new vector<Project * >;
	if (!this->vec)
		return ;
}

ProManager::~ProManager()
{
	//TODO
}

void ProManager::proAdd(string proName, double money, string time)
{
	Project * pro = new Project(proName, money, time);
	this->vec->push_back(pro);
}

ProIterator * ProManager::getIterator()
{
	return (new ProIterator(this->vec));
}

ProIterator::ProIterator(vector<Project * > *vec)
{
	if (!vec)
		return ;
	this->_vec = vec;
	this->iter = this->_vec->begin();
}

ProIterator::~ProIterator()
{
	//TODO
}

bool ProIterator::hasNext()
{
	if (0 == this->_vec->size())
		return false;
	return true;
}

Project * ProIterator::next()
{
	if ( 0 == this->_vec->size())
		return NULL;
	return *(this->iter);
}

void ProIterator::erase()
{
	this->_vec->erase(this->iter);
	this->iter  = this->_vec->begin();	/// < 释放之后重新调整迭代器
}

string getTimeStr()
{
	time_t timep;

	time(&timep); /*获取time_t类型的当前时间*/
	/*用gmtime将time_t类型的时间转换为struct tm类型的时间按，／／没有经过时区转换的UTC时间
	 然后再用asctime转换为我们常见的格式 Fri Jan 11 17:25:24 2012
	  1> asctime(gmtime(&timep))
	  2> ctime(&timep) //经过时区转换的
	 */
	return ctime(&timep);
}

int main()
{
	ProManager pro;
	pro.proAdd("计划书", 300000.00, getTimeStr());
	pro.proAdd("分布式", 400000.00, getTimeStr());
	pro.proAdd("ERP", 600000.00, getTimeStr());

	ProIterator * pProIterator = pro.getIterator();
	while (pProIterator->hasNext())
	{
		Project * tp = pProIterator->next();
		tp->show();
		pProIterator->erase();
	}
	delete pProIterator;

	return 0;
}
