#include "../include/advancedQFcpp_bits/random.hpp"
#include "../include/advancedQFcpp_bits/eq1.hpp"

#include <algorithm>
#include <cmath>
#include <vector>

double EQ1::find_premium() const
{

    double sumPayOff = 0.;
    double premium = 0.;

    double dt = T / N;

    std::vector<double> S(N + 1);

    SampleBoxMuller normal;

    for (int j = 0; j < M; j++)
    {
        S[0] = S0;

        for (int i = 0; i < N; i++)
        {

            double epsilon = normal();

            S[i + 1] = S[i] * (1 + r * dt + sigma * sqrt(dt) * epsilon);
        }

        static double diff = 0.;
        diff = S[N] - K;
        sumPayOff += std::max(diff, 0.);
    }

    premium = exp(-r * T) * (sumPayOff / M);

    return premium;
}