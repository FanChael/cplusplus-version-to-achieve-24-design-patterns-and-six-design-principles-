//============================================================================
// Name        : facadepattern.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "facadepattern.h"

using namespace std;

void LettersProcess::writeLetter(string context)
{
	cout << context << endl;
}

void LettersProcess::fillEvelope(string address)
{
	cout << address << endl;
}

void LettersProcess::letterInotoEnvelope()
{
	cout << "把信放到信封里面..." << endl;
}

void LettersProcess::sendLetter()
{
	cout << "送信...." << endl;
}

int main() {
	SendLetter send;
	send.sendLetter("你好，小额！", "127.0.0.1");

	return 0;
}
