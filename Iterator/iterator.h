/*
 * iterator.h
 *
 *  Created on: Sep 29, 2012
 *      Author: hl
 */

#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 迭代器模式
 */
class IProject
{
public:
	virtual void show() = 0;
};

class Project : public IProject
{
public:
	Project(string proName, double money, string time);
public:
	void show();
private:
	string _proName;
	double _money;
	string _time;
};

class ProIterator;

/**
 * @brief 项目管理器
 */
class ProManager
{
public:
	ProManager();
	~ProManager();
public:
	void proAdd(string proName, double money, string time);
	ProIterator * getIterator();			/// < 得到对象的遍历器
private:
	vector<Project * >  * vec;
};

/**
 * @brief 项目遍历器
 */
class ProIterator
{
public:
	ProIterator(vector<Project * > *vec);
	~ProIterator();
public:
	bool hasNext();			/// < 是否有下一个！
	Project * next();		/// < 下一个!
	void erase();			/// < 遍历一个，释放一个，并且重新组织新的遍历器！
private:
	vector<Project * > * _vec;
	vector<Project * >::iterator iter;
};

#endif /* _ITERATOR_H_ */
