#ifndef FILTERS_DOUBLEEXPSMOOTHING_HPP
#define FILTERS_DOUBLEEXPSMOOTHING_HPP

#include <vector>

/**
 * Double exponential smoothing class
 * Recursion:
 *              st = alpha.xt + (1 - alpha)(st-1 + bt-1)
 *              bt = beta.(st - st-1) + (1 - beta).bt-1
 * Initialization:
 *              s0 = x0
 *              b0 = x1 - x0
 * Forecast:
 *              Ft+m = st + m.bt
 */
class DoubleExpSmoothing {
public:

    DoubleExpSmoothing(double alpha, double beta, double x0, double x1) : alpha_(alpha), beta_(beta) {
        limit(alpha_);
        limit(beta_);
        init(x0, x1);
    }

    DoubleExpSmoothing(double alpha, double beta) : DoubleExpSmoothing(alpha, beta, 0, 0) {}

    void init(double x0, double x1) {
        st1 = x0;
        bt1 = x1 - x0;
    }

    void update(double xt) {
        st = alpha_ * xt + (1 - alpha_) * (st1 + bt1);
        bt = beta_ * (st - st1) + (1 - beta_) * bt1;

        st1 = st;
        bt1 = bt;
    }

    double forecast(int m) const {
        return st + m * bt;
    }

protected:
    double alpha_, beta_, st1{}, st{}, bt1{}, bt{};

    static inline void limit(double &val) {
        if (val > 1) {
            val = 1;
        } else if (val < 0) {
            val = 0;
        }
    }
};

#endif //FILTERS_DOUBLEEXPSMOOTHING_HPP
