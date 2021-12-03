#ifndef EQ1_H
#define EQ1_H

class EQ1
{

    double T;
    double K;
    double S0;
    double sigma;
    double r;
    int N; //no. of steps;
    int M; //no. of simulations;
    double find_premium() const;

public:
    EQ1() : T(1), K(100), S0(100), sigma(0.1), N(500), M(1000)
    {
    }

    EQ1(double T, double K, double S0, double sigma, double r, int N, int M) : T(T), K(K), S0(S0), sigma(sigma), r(r), N(N), M(M)
    {
    }

    double get_premium() const
    {
        return find_premium();
    }
};

#endif