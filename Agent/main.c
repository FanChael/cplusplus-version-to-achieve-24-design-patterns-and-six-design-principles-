#include "agent.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    /// < 潘金莲找西门庆由王婆代理
    WangPo wpo;
    wpo.makeEyesWithMan();
    wpo.happyWithMan();

    cout << "\n------------" << endl;

    /// < 贾氏找西门庆由王婆代理 - 编造的！
    WangPo wpod(new JiaShi());
    wpod.makeEyesWithMan();
    wpod.happyWithMan();
    
    return 0;
}
