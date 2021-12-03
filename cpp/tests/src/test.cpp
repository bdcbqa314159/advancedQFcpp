#include <advancedQFcpp>
#include <iostream>
#include <string>

void testingEQ1()
{
    std::cout << "======EQ1: MC EuroCall======" << std::endl;

    double T = 1.;
    double K = 100.;
    double S0 = 100.;
    double sigma = 0.1;

    double r = 0.05;

    int N = 500;
    int M = 10000;

    EQ1 eq1(T, K, S0, sigma, r, N, M);

    double premium = eq1.get_premium();

    std::cout << "premium = " << premium << std::endl;
}

void testingEQ2()
{
    std::cout << "======EQ2: MC Equity Basket======" << std::endl;

    double T = 1.;
    double K = 100.;
    double S10 = 120.;
    double S20 = 100.;
    double sigma1 = 0.1;
    double sigma2 = 0.15;

    double r = 0.05;
    double rho = 0.5;

    int N = 300;
    int M = 10000;

    EQ2 eq(T, r, S10, S20, sigma1, sigma2, rho, N, M);

    double premium = eq.get_premium();

    std::cout << "premium = " << premium << std::endl;
}

void testingFX1()
{
    std::cout << "======FX1: Finite Difference European Call======" << std::endl;

    double T = .5;
    double K = 75.;
    double S0 = 75.;
    double sigma = 0.3;

    double r = 0.05;
    double dx = 0.5;
    double dt = 0.1;
    int N = 5;
    int M = 6;

    FX1 fx(T, K, S0, sigma, r, dt, dx, N, M, false);

    result_data result = fx.get_data_and_premium();
    std::cout << result << std::endl;
}

void testingFX2()
{

    std::cout << "======FX2: Finite Difference European European Up-and Out Barrier Call======" << std::endl;

    double T = .5;
    double K = 75.;
    double S0 = 75.;
    double sigma = 0.3;

    double r = 0.05;
    double dx = 0.5;
    double dt = 0.1;
    int N = 5;
    int M = 6;

    FX1 fx(T, K, S0, sigma, r, dt, dx, N, M, true);

    result_data result = fx.get_data_and_premium();
    std::cout << result << std::endl;
}

void testingIR1()
{

    std::cout << "======IR1: IRS MC Floating Rate MM 1F======" << std::endl;

    double notional = 1000000;
    double K = 0.04;
    double alpha = 0.25;
    double sigma = 0.15;
    double dT = 0.25;
    int N = 3;
    int M = 1000;

    IR ir(notional, K, alpha, sigma, dT, N, M);

    IR_results results = ir.get_simulation_data();

    size_t sz = results.datapoints.size();

    // for (int nsim = 0; nsim < sz; nsim++)
    // {
    //     std::cout << "simIRS[" << nsim << "] = " << results.datapoints[nsim] << std::endl;
    // }

    std::cout << "IRS PV = " << results.Value << std::endl;
}

void testingIR2()
{
    std::cout << "======IR2: CAP MC Floating Rate MM 1F======" << std::endl;

    double K = 0.05;
    double alpha = 0.5;
    double sigma = 0.15;
    double dT = 0.5;
    int N = 4;
    int M = 1000;

    IR ir(K, alpha, sigma, dT, N, M, true);

    IR_results results = ir.get_simulation_data();

    size_t sz = results.datapoints.size();

    // for (int nsim = 0; nsim < sz; nsim++)
    // {
    //     std::cout << "simIRS[" << nsim << "] = " << results.datapoints[nsim] << std::endl;
    // }

    std::cout << "IRS cap = " << results.Value << std::endl;
}

void testingCR1()
{
    std::cout << "======CR1: MC Merton Model======" << std::endl;

    double T = 4.0;
    double D = 70.;
    double V0 = 100.;
    double sigma = 0.2;
    double r = 0.05;
    int N = 500;
    int M = 10000;

    CR1 cr(T, D, V0, sigma, r, N, M);

    CR1_results cr1_results = cr.get_payoff_and_defaults();

    std::cout << "Equity payoff E(0) = " << cr1_results.equity_payoff << std::endl;

    std::cout << "Percentage defaults = " << cr1_results.percentage_defaults << "%" << std::endl;
}

int main()
{
    std::cout << "Moving to Credit :)!" << std::endl;

    std::cout << "======CR2: CDS======" << std::endl;

    double T = 1.0;
    double rr = 0.5;
    double notional = 100.;
    double h = 0.01;
    double r = 0.05;
    int N = 4;

    CR2 cr(T, N, notional, r, h, rr);

    CR2_results cr2_results = cr.get_pv_premium_and_default_legs_and_spread();

    std::cout << "PV premium leg = " << cr2_results.pv_premium_leg << std::endl;

    std::cout << "PV default leg = " << cr2_results.pv_default_leg << std::endl;

    std::cout << "cds_spread = " << cr2_results.cds_spread_in_bps << std::endl;

    return 0;
}
