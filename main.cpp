#include <iostream>

#include "Game.hpp"

using namespace std;

int main()
{
    Game incoming;

    if(!incoming.initialize())
        return -1;

    incoming.run();

    return 0;
}
