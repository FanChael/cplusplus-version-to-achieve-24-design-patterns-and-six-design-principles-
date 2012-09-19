#include "factory.h"
#include <iostream>
using namespace std;

void WhiteHuman::laguage()
{
    cout << "我说英语" << endl;
}

void BlackHuman::laguage()
{
    cout << "我说外语" << endl; 
}

void YellowHuman::laguage()
{
    cout << "我说汉语" << endl;
}

Human * Factory::hum = NULL;

Human * Factory::getHum(Human * hu)
{
    if (NULL == hu)
        return NULL;  
    hum = hu;
    
    return hum;
}
