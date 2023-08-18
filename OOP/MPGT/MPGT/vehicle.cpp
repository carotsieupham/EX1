#include "vehicle.h"

vehicle::vehicle(float vtri, float vtoc):x(vtri),v(vtoc)
{}

float vehicle::capNhapVitri(float dt)
{   
    x = x + v * dt;
    return x;
}

float vehicle::dieuChinhTocDo()
{
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<float> distribution(-1.0f, 1.0f);
    float randomValue = distribution(generator);
    while (v+randomValue<0)
    {
         randomValue = distribution(generator);
    }

    v = v + randomValue;
    return v;
}

float vehicle::getposition()
{
    return x;
}

float vehicle::getspeed()
{
    return v;
}




