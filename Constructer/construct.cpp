//============================================================================
// Name        : construct.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : Constructer Model in C++, Ansi-style
//============================================================================

#include <iostream>
#include "construct.h"
using namespace std;

#define FIRE "Fire"
#define CLEAN "Clean"
#define COOK "Cook"

void Template::Sequence(string nowDo)
{
	if (nowDo.empty())
		return ;
	vecs.push_back(nowDo);
}

void Template::DoFood()
{
	vector<string>::iterator iter = vecs.begin();
	for(; iter != vecs.end(); iter++)
	{
		if (FIRE == *iter)	/// < C++字符串的比较
			OpenFire();
		if (CLEAN == *iter)
			Cleanpan();
		if (COOK == *iter)
			Cook();
	}
}

void Boy::OpenFire()
{
	cout << "打开火" << endl;
}

void Boy::Cleanpan()
{
	cout << "洗锅" << endl;
}

void Boy::Cook()
{
	cout << "烧饭" << endl;
}

int main()
{
	Template * pTemplate = new Boy();
	pTemplate->Sequence(FIRE);
	pTemplate->Sequence(COOK);
	pTemplate->Sequence(CLEAN);
	pTemplate->DoFood();
	delete pTemplate;

	return 0;
}
