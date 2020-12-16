#include "CountTime.h"

CountTime::CountTime()
{
    timepause = false;
    runTime = 0;
    timegame.restart();
}

void CountTime::Reset()
{
    timegame.restart();
    runTime = 0;
    timepause = false;
}

void CountTime::Start()
{
    if (timepause) {
        timegame.restart();
    }
    timepause = false;
}

void CountTime::Pause()
{
    if (!timepause) {
        runTime += timegame.getElapsedTime().asSeconds();
    }
    timepause = true;
}
