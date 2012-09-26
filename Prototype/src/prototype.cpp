//============================================================================
// Name        : prototype.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : Prototype Model in C++, Ansi-style
//============================================================================
#include "prototype.h"
#include "sendmail.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define random(x) (rand()%x + 123)

AdvTemplate::AdvTemplate()
{

}
AdvTemplate::AdvTemplate(string sub, string adv)
{
	advSubject = sub;
	advContext = adv;
}

/**
 * @brief 获得广告内容
 */
string AdvTemplate::getAdvMsg()
{
	return this->advContext;
}

/**
 * @brief 获得广告主题
 */
string AdvTemplate::getAdvSub()
{
	return this->advSubject;
}

/**
 * 邮件类
 */
Mail::Mail(AdvTemplate adv)
{
	subject = adv.getAdvSub();
	context = adv.getAdvMsg();
}

void Mail::setRec(string rec)
{
	receiver = rec;
}

void Mail::setAppe(string appe)
{
	appellation = appe;
}

void Mail::setTail(string tai)
{
	tail = tai;
}

string Mail::getSub()
{
	return subject;

}

string Mail::getContext()
{
	return context;
}

string Mail::getRec()
{
	return receiver;
}

string Mail::getAppe()
{
	return appellation;
}

string Mail::getTail()
{
	return tail;
}

Mail * Mail::getClone()
{
	Mail * pMail = new Mail(*this);

	return pMail;
}

/**
 * @brief 整数转换为字符串
 */
char *myitoa(int num, char *str, int radix)
{
	/* 索引表 */
	char index[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	unsigned unum;
	int i = 0, j, k;
	if (radix == 10 && num < 0) /* 十进制负数 */
	{
		unum = (unsigned) -num;
		str[i++] = '-';
	}
	else
		unum = (unsigned) num; /* 其他情况 */
	/* 逆序 */
	do
	{
		str[i++] = index[unum % (unsigned) radix];
		unum /= radix;
	} while (unum);
	str[i] = '\0';
	/* 转换 */
	if (str[0] == '-')
		k = 1; /* 十进制负数 */
	else
		k = 0;
	return str;
}

int main()
{
	/// < 创建邮件
	Mail mal(*(new AdvTemplate("幸运大奖", "犬友头像征集活动开始了,欢迎到家踊跃报名！")));

	char buf[128];
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		memset(buf, 0, 128);
		myitoa(random(123456), buf, 10);

		/// < 自己封装了一个String函数，这样省去了以上的字符串操作！不过需要將string函数替换！不过我再修改
		/// < 下库，提供一个获取字符串的函数！
		String b = "@qq.com";
		String d = buf;
		String c = d + b;

		char * abc = c.getStr();

		Mail * pMail = mal.getClone();	/// < 得到clone版本，这样再执行多线程操作才不会影响结果！省去了我们自己控制线程pthread_create！
		cout << "address1 ---------- "<< pMail << endl;	/// < 每次地址都不同，因此成功拷贝!
		pMail->setRec(abc);
		delete abc;
		pMail->setAppe("xiaodou");
		pMail->setTail("lego公司");

		SendMail::sendMail(*pMail);
		delete pMail;	/// < 执行了delete之后，可能每次分配的地址都相同！所以每次你看到address结果都可能相同！
	}


	return 0;
}
