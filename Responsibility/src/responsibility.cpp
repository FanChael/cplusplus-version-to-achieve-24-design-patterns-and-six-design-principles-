//============================================================================
// Name        : responsibility.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : Responsibility Patternin C++, Ansi-style
//============================================================================

#include "responsibility.h"
#include <iostream>
using namespace std;

Women::Women(int type, string req)
{
	this->_type = type;
	switch (this->_type)
	{
	case 1:
		this->_req = "女儿的请求: " + req;
		break;
	case 2:
		this->_req = "母亲的要求: " + req;
		break;
	case 3:
		break;
	default:
		break;
	}
}

int Women::getType()
{
	return this->_type;
}


string Women::getRequest()
{
	return this->_req;
}


void Father::response(IWomen * pIWomen)
{
	cout << "女儿向父亲请求！" << endl;
	cout << pIWomen->getRequest() << endl;
	cout << "同意" << endl;
}

void Son::response(IWomen * pIWomen)
{
	cout << "母亲向儿子要求！" << endl;
	cout << pIWomen->getRequest() << endl;
	cout << "同意" << endl;
}


int main()
{
	IWomen * wom1 = new Women(1, "父亲大人，我要出去happy");
	IWomen * wom2 = new Women(2, "儿子，我们去吃肯德基");

	Father fath;
	Son son;
	fath.setNext(&son);

	fath.HandleMessage(wom1);
	fath.HandleMessage(wom2);

	return 0;
}
