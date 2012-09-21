/*
 * template.h
 *
 *  Created on: Sep 20, 2012
 *      Author: hl
 */

#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

/**
 * @brief 模板方法，定义一系列过程，由派生类去实现；同时自己提供一个该一系列过程的结果...
 * 自己调用自己，同时调用的实现由派生类去做；就像父类调用派生类....
 */
class Template
{
protected:
	virtual void OpenFire() = 0;
	virtual void Cleanpan() = 0;
	virtual void Cook() = 0;
public:
	void DoFood()
	{
		OpenFire();
		Cleanpan();
		Cook();
	}
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

#endif /* _TEMPLATE_H_ */
