/*
 * responsibility.h
 *
 *  Created on: Sep 29, 2012
 *      Author: hl
 */

#ifndef _RESPONSIBILITY_H_
#define _RESPONSIBILITY_H_
#include <string>
using namespace std;

class IWomen
{
public:
	virtual int getType() = 0;
	virtual string getRequest() = 0;
};

class Women : public IWomen
{
public:
	Women(int type, string req);
public:
	int getType();
	string getRequest();
private:
	int _type;
	string _req;
};

/**
 * @责任链处理 - 实现最好都放到.cpp中，不给别人看见！这里我方便学习...
 */
class Handle
{
public:
	Handle(int level)
	{
		this->_level = level;
	}
	~Handle()
	{
		if (_pHandle)
			delete _pHandle;
	}
public:
	void HandleMessage(IWomen * pIWomen)
	{
		if (this->_level == pIWomen->getType())
			this->response(pIWomen);
		else
		{
			if (this->_pHandle != NULL)
				this->_pHandle->HandleMessage(pIWomen);
		}
	}
public:
	void setNext(Handle * pHandle)
	{
		this->_pHandle = pHandle;
	}
public:
	virtual void response(IWomen * pIWomen) = 0;
private:
	int _level;
	Handle * _pHandle;
};

/**
 * 父亲响应女儿(Women)的请求
 */
class Father : public Handle
{
public:
	Father() : Handle(1)	/// < 基类初始化变量，解决基类和子类的构造函数参数不同问题
	{

	}
	void response(IWomen * pIWomen);
};

/**
 * 父亲响应女儿(Women)的请求
 */
class Son : public Handle
{
public:
	Son() : Handle(2)	/// < 基类初始化变量，解决基类和子类的构造函数参数不同问题
	{

	}
	void response(IWomen * pIWomen);
};

#endif /* _RESPONSIBILITY_H_ */
