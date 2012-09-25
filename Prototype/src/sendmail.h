/*
 * sendmail.h
 *
 *  Created on: Sep 24, 2012
 *      Author: hl
 */

#ifndef _SENDMAIL_H_
#define _SENDMAIL_H_
#include "prototype.h"
/**
 * @brief 写信的过程 - 写信的内容、把信放到信封、把信送到邮局、邮局送信
 */
class SendMail
{
public:
	static void sendMail(Mail mal);
};

#endif /* _SENDMAIL_H_ */
