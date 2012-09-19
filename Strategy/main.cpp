#include <iostream>
#include "strtegy.h"

using namespace std;

/**
 * @brief 模板锦囊(放妙计)
 */
template <typename T>
class ContentT
{
public:
    void operate()
    {
       strat.operate(); 
    }
private:
    T strat;
};

int main()
{
#if 1
    Content * cont;     /// < 得到锦囊
    
    cont = new Content(new Backdoor());
    cont->operate();    /// < 开后门
    delete cont;

    cont = new Content(new Greelight());
    cont->operate();    /// < 开绿灯
    delete cont;

    cont = new Content(new BlockEnemy());
    cont->operate();    /// < 段后 
    delete cont;
#endif

    cout << "\n------------" << endl;

#if 1
    /// < 模板方式
    ContentT<Backdoor> contBck;
    contBck.operate();
    
    ContentT<Greelight> contGrl;
    contGrl.operate();
    
    ContentT<BlockEnemy> contBlk;
    contBlk.operate();
#endif

    return 0;
}
