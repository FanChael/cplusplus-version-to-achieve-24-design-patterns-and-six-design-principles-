#ifndef _SIGLE_H_
#define _SIGLE_H_

/**
 * @brief 单例模式
 */
class Sigle
{
private:
    Sigle()
    {
    }
public:
    static Sigle * getInstance();   /// < Sigle()为私有了，因此不再可能去创建一个实例！因此我们需要静态，使之不依赖类!
    void sound();
private:
    static Sigle * sig;     /// < 同样静态，不依赖于类，所以不能在类中进行初始化!
};

#endif
