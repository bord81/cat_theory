#include "optional.h"

#include <iostream>

optional<double> safe_root(double x);
optional<double> safe_reciprocal(double x);
optional<double> safe_root_reciprocal(double x);

int main() {
    // Safe functions
    constexpr double four = 4.0;
    constexpr double zero = 0.0;
    constexpr double minus_one = -1.0;

    optional<double> safe_root_4 = safe_root(four);
    optional<double> safe_root_0 = safe_root(zero);
    optional<double> safe_root__1 = safe_root(minus_one);
    assert(safe_root_4.isValid());
    assert(safe_root_0.isValid());
    assert(!safe_root__1.isValid());

    optional<double> safe_recip_4 = safe_reciprocal(four);
    optional<double> safe_recip_0 = safe_reciprocal(zero);
    optional<double> safe_recip__1 = safe_reciprocal(minus_one);
    assert(safe_recip_4.isValid());
    assert(!safe_recip_0.isValid());
    assert(safe_recip__1.isValid());

    optional<double> safe_root_recip_4 = safe_root_reciprocal(four);
    optional<double> safe_root_recip_0 = safe_root_reciprocal(zero);
    optional<double> safe_root_recip__1 = safe_root_reciprocal(minus_one);
    assert(safe_root_recip_4.isValid());
    assert(!safe_root_recip_0.isValid());
    assert(!safe_root_recip__1.isValid());

    std::cout << "All tests passed." << "\n";
    return 0;
}
