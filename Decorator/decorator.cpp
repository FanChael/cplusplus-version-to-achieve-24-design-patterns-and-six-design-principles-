//============================================================================
// Name        : decorator.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : decorator pattern in C++, Ansi-style
//============================================================================

#include <iostream>
#include "decorator.h"
using namespace std;

void FouthGradeSchoolReport::reaport()
{
	cout << "语文 45  数学 54" << endl;
}

void FouthGradeSchoolReport::sign(string name)
{
	cout << "家长请签名: " + name << endl;
}

int main()
{
	SchoolReport * pSchoolReport = new Decorator();
	pSchoolReport->reaport();
	/// < 家长一看排名还不错，就签名了！(作者说)
	pSchoolReport->sign("小五");

	return 0;
}
