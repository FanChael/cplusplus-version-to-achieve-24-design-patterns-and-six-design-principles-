#ifndef _FACTORY_H_
#define _FACTORY_H_

class Human
{
public:
    virtual void laguage() = 0;
};


class WhiteHuman : public Human
{
public:
    void laguage();
};

class BlackHuman : public Human
{
public:
    void laguage();
};

class YellowHuman : public Human
{
public:
    void laguage();
};

class Factory
{
public:
    Factory()
    {
    }
    ~Factory()
    {
    }
public:
    static Human * getHum(Human * hu);
private:
    static Human * hum; /// < 不是静态的getHum不能直接调用；原因...
};

#endif
