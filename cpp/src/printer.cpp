#include "../include/advancedQFcpp_bits/fx1.hpp"

#include <iostream>
#include <iomanip>

std::ostream &operator<<(std::ostream &os, const result_data &rs)
{

    int M(0), N(0);

    N = rs.u.size();

    if (N)
    {
        M = rs.u[0].size();
    }

    os << std::setw(10) << " dtau = " << rs.dtau << std::endl;

    os << std::setw(10) << " alpha = " << rs.alpha << std::endl;

    os << std::setw(10) << " k = " << rs.k << std::endl;

    os << "\n.......x and and tau grids.......\n\n";

    for (int j = 0; j < M; j++)
    {
        os << std::setw(5) << "t " << rs.t[j] << std::endl;
        os << std::setw(5) << "tau " << rs.tau[j] << std::endl;
    }

    os << "\n.......init cond.......\n\n";

    for (int i = 0; i < N; i++)
    {
        os << std::setw(5) << "i " << i << std::setw(5) << "u " << rs.u[i][0] << std::endl;
    }

    os << "\n.......bcs.......\n\n";

    for (int j = 1; j < M; j++)
    {

        os << std::setw(5) << "j " << j << std::setw(12) << "u[0][j] " << rs.u[0][j] << std::endl;
        os << std::setw(5) << "j " << j << std::setw(12) << "u[N-1][j] " << rs.u[N - 1][j] << std::endl;
    }

    os << "\n.......u and v.......\n\n";

    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            os << std::setw(5) << "i = " << i << ", j = " << j << std::setw(11) << " v[i][j] " << rs.v[i][j] << std::endl;
        }
    }

    os << "\n premium = " << rs.v[N / 2][M - 1] << std::endl;

    return os;
}