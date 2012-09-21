//============================================================================
// Name        : tmplate.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : Tmplatein Model in C++, Ansi-style
//============================================================================

#include <iostream>
#include "template.h"
using namespace std;

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
	pTemplate->DoFood();
	delete pTemplate;

	return 0;
}
