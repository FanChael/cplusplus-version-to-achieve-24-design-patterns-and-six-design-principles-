/*
 * construct.h
 *
 *  Created on: Sep 20, 2012
 *      Author: hl
 */

#ifndef _CONSTRUCT_H_
#define _CONSTRUCT_H_
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 建造者模式，定义一系列过程，由派生类去实现；同时自己提供一个该一系列过程的结果...
 * 自己调用自己，同时调用的实现由派生类去做；就像父类调用派生类....
 * 然后实现一个定义调用动作顺序的向量。
 */
class Template
{
public:
	Template()
	{
		vecs.empty();
	}
	~Template()
	{
		vecs.empty();
	}
protected:
	virtual void OpenFire() = 0;
	virtual void Cleanpan() = 0;
	virtual void Cook() = 0;
public:
	void Sequence(string nowDo);	/// < 可以多次调用，实现多种组合；记得如果连续使用，最后清空下！
	void DoFood();
private:
	vector<string> vecs;
};

/**
 * @brief 男孩做饭 - 独家秘方
 */
class Boy : public Template
{
private:
	void OpenFire();
	void Cleanpan();
	void Cook();
};

#endif /* _CONSTRUCT_H_ */
