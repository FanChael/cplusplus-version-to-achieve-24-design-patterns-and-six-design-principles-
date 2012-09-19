#include "sigle.h"
//#include <iostream>
//using namespace std;

int main(int argc, const char *argv[])
{
    /// < 调用静态函数获得单例
    Sigle * psig = Sigle::getInstance();
    psig->sound();
    delete psig;

    return 0;
}
