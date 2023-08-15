#include "BaseGame.h"

using namespace baseEngine;

int main(void)
{
    BaseGame engine;

    engine.initEngine();

    engine.updateEngine();

    engine.closeEngine();

    return 0;
}