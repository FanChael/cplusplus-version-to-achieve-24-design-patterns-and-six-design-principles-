/*
 * prototype.h
 *
 *  Created on: Sep 24, 2012
 *      Author: hl
 */

#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_
#include <string>
using namespace std;

class Mail;

/**
 * @brief 广告模板
 */
class AdvTemplate
{
public:
	AdvTemplate();
	AdvTemplate(string sub, string adv);
public:
	string getAdvSub();	/// < 获得广告主题
	string getAdvMsg();	/// < 获得广告内容
private:
	string advSubject;	/// < 广告主题
	string advContext;	/// < 广告内容
};

/**
 * @brief 对象克隆
 */
class Clone
{
public:
	virtual Mail * getClone() = 0;
};

/**
 * 邮件类
 */
class Mail : public Clone
{
public:
	Mail(AdvTemplate adv);	/// < 获取邮件主题和内容
public:
	void setRec(string rec);	/// < 设置收件人
	void setAppe(string appe);	/// < 设置名称
	void setTail(string tai);	/// < 设置结尾

	string getSub();
	string getContext();
	string getRec();
	string getAppe();
	string getTail();

	Mail * getClone();
private:
	string receiver;	/// < 接收者
	string appellation;	/// < 名称
	string tail;		/// < 结尾

	string subject;		/// < 主题
	string context;		/// < 内容
};

#endif /* _PROTOTYPE_H_ */
