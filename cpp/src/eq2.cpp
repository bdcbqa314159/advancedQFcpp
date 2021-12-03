#include "../include/advancedQFcpp_bits/random.hpp"
#include "../include/advancedQFcpp_bits/eq2.hpp"

#include <algorithm>
#include <cmath>
#include <vector>

double EQ2::find_premium() const
{

    std::vector<double> S1(N + 1);
    std::vector<double> S2(N + 1);

    double sumPayOff = 0.;
    double premium = 0.;
    double dt = T / N;

    SampleBoxMuller normal;

    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            S1[0] = S10;
            S2[0] = S20;

            static double epsilon1, epsilon2;
            epsilon1 = normal();
            epsilon2 = normal();

            S1[i + 1] = S1[i] * (1 + r * dt + sigma1 * sqrt(dt) * epsilon1);
            S2[i + 1] = S2[i] * (1 + r * dt + sigma2 * sqrt(dt) * (epsilon1 * rho + sqrt(1 - rho) * epsilon2));
        }

        sumPayOff += std::max(S1[N], S2[N]);
    }

    premium = exp(-r * T) * (sumPayOff / M);

    return premium;
}