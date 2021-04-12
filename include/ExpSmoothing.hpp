#ifndef FILTERS_EXPSMOOTHING_HPP
#define FILTERS_EXPSMOOTHING_HPP

/**
 * Implementation of a exponential smoothing filter.
 * Recursion        : st = alpha.xt + (1 - alpha).st-1
 * Initialization   : s0 = x0
 */
class ExpSmoothing {
public:

    /**
     * @brief Initialize the filter with the given parameter. The first term s0 = 0;
     * @param alpha Should be a number between [0;1] if not the number is squeezed to 0 or 1.
     * @param x0    The initial value of the filter.
     */
    ExpSmoothing(double alpha, double x0) : init_flag_(false) {
        // Limit the alpha parameter to the interval [0;1]
        if (alpha > 1) {
            alpha_ = 1;
        } else if (alpha < 0) {
            alpha_ = 0;
        } else {
            alpha_ = alpha;
        }
        // Initialize the filter.
        init(x0);
    }

    /**
     * @brief Initialize the filter with the given parameter. The first term s0 = 0;
     * @param alpha Should be a number between [0;1] if not the number is squeezed to 0 or 1.
     */
    explicit ExpSmoothing(double alpha) : ExpSmoothing(alpha, 0) {}

    /**
     * @brief Set the initial value of the filter.
     * @param s0
     */
    void init(double x0) {
        if (!init_flag_) {
            st1_ = x0;
            init_flag_ = true;
        }
    }

    /**
     * @brief Apply the filter whithout updating the value.
     * @param xt The input value.
     * @return Filtered value.
     */
    double eval(double xt) const {
        return st1_ + alpha_ * (xt - st1_);;
    }

    /**
     * @brief Apply the filter and update the smoothed data in the class.
     * @param xt Input value.
     * @return Filtered data.
     */
    double update(double xt) {
        double st;
        st = eval(xt);
        st1_ = st;
        return st;
    }

    /**
     * @brief Return the current filtered value.
     * @return The filtered value.
     */
    double get() const {
        return st1_;
    }

protected:
    double alpha_, st1_{};
    bool init_flag_;
};

#endif //FILTERS_EXPSMOOTHING_HPP
