#include "sigle.h"
#include <iostream>
using namespace std;

Sigle * Sigle::sig = NULL;

/**
 * @brief 获得实例
 */
Sigle * Sigle::getInstance()
{
    if (NULL == sig)
        sig = new Sigle();
    return sig;
}

/**
 * @brief 简短宣传
 */
void Sigle::sound()
{
   cout << "我得到单例了！" << endl; 
}
