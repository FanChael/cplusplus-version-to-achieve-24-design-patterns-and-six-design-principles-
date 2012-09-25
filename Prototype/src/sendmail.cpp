/*
 * sendmail.cpp
 *
 *  Created on: Sep 24, 2012
 *      Author: hl
 */
#include "sendmail.h"
#include <iostream>
using namespace std;

void SendMail::sendMail(Mail mal)
{
	cout << "姓名 " << mal.getAppe() << "\n内容 " << mal.getContext() << "\n收信人 " << mal.getRec()
			<< "\n主题 " << mal.getSub() << "\n结尾 " << mal.getTail() << endl;
}
