#ifndef RANDOM_H
#define RANDOM_H

class SampleBoxMuller
{

    double result;
    double x;
    double y;
    double xysquare;

public:
    double operator()();
};

#endif