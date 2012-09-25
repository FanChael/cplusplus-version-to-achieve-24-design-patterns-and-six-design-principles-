/*
 * string.h
 *
 *  Created on: Sep 24, 2012
 *      Author: hl
 */

#ifndef _STRING_H_
#define _STRING_H_

/**
 * @brief 字符串操作符重载 - 实现+、
 * 注意：
 * 	s大小128，针对具体的硬件平台可适当修改！
 * 使用示例:
 * 	String  a = "hello";
 * 	String  b = "kitty";
 * 	String  c;
 * 	c = a + b + " " + "$" + f + ".com";
 */
class String
{
public:
	String();
	String(char * str);
public:
	char * getStr();
	void display();
	String operator+(String b);
private:
	char s[128];
};

#endif /* _STRING_H_ */
