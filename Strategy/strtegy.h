#ifndef _STRTEGY_H_
#define _STRTEGY_H_

/**
 * @brief 锦囊妙计（抽象类）
 */
class Strategy
{
public:
    virtual void operate() = 0;
};

/**
 * @brief 开后门（找乔国老帮忙，免杀刘备）
 */
class Backdoor : public Strategy
{
public:
    void operate();
};

/**
 * @brief 开绿灯（找吴国太帮忙，放行）
 */
class Greelight : public Strategy
{
public:
    void operate();
};

/**
 * @brief 断后（孙夫人断后）
 */
class BlockEnemy : public Strategy
{
public:
    void operate();
};

/**
 * 锦囊（存放妙计）
 */
class Content
{
public:
    Content()
    {

    }
    Content(Strategy * stra)
    {
        strat = stra;
    }
    ~Content()
    {
        delete strat;
    }
public:
    void operate()
    {
        strat->operate();
    }
private:
    Strategy * strat;
};

#endif // _STRTEGY_H_




