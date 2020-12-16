#pragma once

#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class CountTime
{
public:
	CountTime();

    Clock timegame;
    float runTime;
    bool timepause;

    void Reset();
    void Start();
    void Pause();

    float GetElapsedSeconds() 
    {
        if (!timepause) {
            return runTime + timegame.getElapsedTime().asSeconds();
        }
        return runTime;
    }
};

