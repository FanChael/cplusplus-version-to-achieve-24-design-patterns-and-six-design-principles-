#ifndef _AGENT_H_
#define _AGENT_H_

/**
 * @brief 代理人（可以抛媚眼，可以Happy）
 */
class AgentWomen
{
public:
    virtual void makeEyesWithMan()
    {
        //TODO? 
    }
    virtual void happyWithMan()
    {
        //TODO?
    }
};

/**
 * @brief 潘金莲的抚媚
 */
class PanJinlian : public AgentWomen
{
public:
    void makeEyesWithMan();
    void happyWithMan();
};

/**
 * @brief 贾氏的多情
 */
class JiaShi : public AgentWomen
{
public:
    void makeEyesWithMan();
    void happyWithMan();
};

/**
 * @brief 王婆的多能
 */
class WangPo : public AgentWomen
{
public:
    WangPo()                    /// < 默认潘金莲代理
    {
        agent = new PanJinlian(); 
    }
    WangPo(AgentWomen * agen)  /// < 代理
    {
        agent = agen; 
    }
    ~WangPo()
    {
        delete agent; 
    }
public:
    void makeEyesWithMan()
    {
        agent->makeEyesWithMan();
    }
    void happyWithMan()
    {
        agent->happyWithMan(); 
    }
private:
    AgentWomen * agent;
};

#endif
