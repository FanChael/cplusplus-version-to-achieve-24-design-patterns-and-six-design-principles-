/*
 * facadepattern.h
 *
 *  Created on: Sep 19, 2012
 *      Author: hl
 */

#ifndef _FACADEPATTERN_H_
#define _FACADEPATTERN_H_
#include <string>
using namespace std;

/**
 * @brief 写信的过程 - 写信的内容、把信放到信封、把信送到邮局、邮局送信
 */
class LettersProcess
{
public:
	void writeLetter(string context);
	void fillEvelope(string address);
	void letterInotoEnvelope();
	void sendLetter();
};

/**
 * @brief 整个过程由门面进行操作！
 */
class SendLetter
{
public:
	SendLetter()
	{
		ltt = new LettersProcess();
		if (!ltt)
			ltt = NULL;
	}
	~SendLetter()
	{
		if (ltt)
			delete ltt;
	}
public:
	void sendLetter(const string context, const string address)
	{
		if (context.empty() || address.empty())
			return ;
		ltt->writeLetter(context);
		ltt->fillEvelope(address);
		ltt->letterInotoEnvelope();
		ltt->sendLetter();
	}
private:
	LettersProcess  * ltt;
};

/* 原来一开是用静态 static LettersProcess ltt; 但是没必要！而且在类中定义对象，需要将private放在前面，不是找不到！
 * 这编译器！！！
class Test
{
public:
    Test(): a(0){}
       enum {size1=100, size2 = 200 };
private:
    const int a;  // 只能在构造函数初始化列表中初始化，这个似乎很少用到？？？
    static int b；
    const static int c; // 与static const int c;相同,可以在这里定义(如果以后在类中需要使用该变量的话).
}
int Test：：b = 0;  // 不能以成员列表初始化，不能在定义处促使化，因为不属于某个对象。
const int Test：： c ＝ 0；//注意：给静态成员变量赋值时，不在需要加static修饰。但const要加。
*/

#endif /* _FACADEPATTERN_H_ */
