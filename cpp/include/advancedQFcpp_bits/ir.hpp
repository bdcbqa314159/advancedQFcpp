#ifndef IR_H
#define IR_H

#include <vector>

struct IR_results
{

    std::vector<double> datapoints;
    double Value;

    IR_results()
    {
    }

    IR_results(std::vector<double> datapoints, double Value) : datapoints(datapoints), Value(Value)
    {
    }
};

class IR
{

    double notional;
    double K;
    double alpha;
    double sigma;

    double dT;
    int N;
    int M;
    bool cap;

    IR_results run_FloatingRate_simulations() const;

public:
    IR() : notional(0), K(0.05), alpha(0.5), sigma(0.15), dT(0.5), N(4), M(10000), cap(false)
    {
    }

    IR(double notional, double K, double alpha, double sigma, double dT, int N, int M) : notional(notional), K(K), alpha(alpha), sigma(sigma), dT(dT), N(N), M(M), cap(false)
    {
    }

    IR(double K, double alpha, double sigma, double dT, int N, int M, bool cap) : notional(0), K(K), alpha(alpha), sigma(sigma), dT(dT), N(N), M(M), cap(cap)
    {
    }

    IR_results get_simulation_data() const
    {
        return run_FloatingRate_simulations();
    }
};

#endif