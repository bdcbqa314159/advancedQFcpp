#ifndef CR1_H
#define CR1_H

struct CR1_results
{

    double equity_payoff;
    double percentage_defaults;

    CR1_results() : equity_payoff(0), percentage_defaults(0)
    {
    }
};

struct CR2_results
{

    double pv_premium_leg;
    double pv_default_leg;
    double cds_spread_in_bps;

    CR2_results() : pv_premium_leg(0), pv_default_leg(0), cds_spread_in_bps(0)
    {
    }
};

class CR1
{
    double T;
    double D;
    double V0;
    double sigma;
    double r;
    int N;
    int M;

    CR1_results find_payoff_and_defaults() const;

public:
    CR1() : T(4), D(70), V0(100), sigma(0.2), r(0.05), N(500), M(1000)
    {
    }

    CR1(double T, double D, double V0, double sigma, double r, int N, int M) : T(T), D(D), V0(V0), sigma(sigma), r(r), N(N), M(M)
    {
    }

    CR1_results get_payoff_and_defaults() const
    {

        return find_payoff_and_defaults();
    }
};

class CR2
{
    double T;
    int N;
    double notional;
    double r;
    double h;
    double rr;

    CR2_results find_pv_premium_and_default_legs_and_spread() const;

public:
    CR2() : T(1), N(4), notional(100), r(0.05), h(0.01), rr(0.5)
    {
    }

    CR2(double T, int N, double notional, double r, double h, double rr) : T(T), N(N), notional(notional), r(r), h(h), rr(rr)
    {
    }

    CR2_results get_pv_premium_and_default_legs_and_spread() const
    {

        return find_pv_premium_and_default_legs_and_spread();
    }
};

#endif