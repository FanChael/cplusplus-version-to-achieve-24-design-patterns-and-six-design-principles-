#include "factory.h" 

int main(int argc, const char *argv[])
{
    Human * white = Factory::getHum(new WhiteHuman()); 
    white->laguage();
    delete white;

    Human * black = Factory::getHum(new BlackHuman()); 
    black->laguage();
    delete black; 

    Human * yellow = Factory::getHum(new YellowHuman()); 
    yellow->laguage();
    delete yellow;

    return 0;
}
