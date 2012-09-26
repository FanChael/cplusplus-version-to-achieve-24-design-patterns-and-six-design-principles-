//============================================================================
// Name        : vistor.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : Vistor Patter in C++, Ansi-style
//============================================================================

#include "vistor.h"
#include <iostream>
using namespace std;


string Employee::baseInfo()
{
	return "员工号: 120\n工资: 1200";
}

string Manager::baseInfo()
{
	return "员工号: 110\n工资: 5000";
}

void ShowVistor::Export(Vistor * vis)
{
	cout << vis->info << endl;
}

int main()
{
	ShowVistor show;
	show.Export(new Vistor(new Employee()));
	show.Export(new Vistor(new Manager()));

	return 0;
}
