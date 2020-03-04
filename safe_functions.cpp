#include <cmath>
#include "optional.h"

optional<double> safe_root(double x) {
    if (x >= 0) return optional<double>{sqrt(x)};
    else return optional<double>{};
}

optional<double> safe_reciprocal(double x) {
    if (x != 0) return optional<double>{1 / x};
    else return optional<double>{};
}

optional<double> safe_root_reciprocal(double x) {
    optional<double> recip_x = safe_reciprocal(x);
    if (recip_x.isValid()) return safe_root(recip_x.value());
    else return recip_x;
}