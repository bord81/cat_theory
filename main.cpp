#include "either.h"
#include "optional.h"

#include <iostream>

optional<double> safe_root(double x);
optional<double> safe_reciprocal(double x);
optional<double> safe_root_reciprocal(double x);
int m_int_bool_int(Either<int, bool> const &e);
int m_int_bool_int_2(Either<int, bool> const &e);
Either<int, bool> m_int_bool_either_1(int v);
Either<int, bool> m_int_bool_either_2(int v);

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

    // Coproduct
    Either<int, bool> number{7};
    Either<int, bool> true_val{true};
    Either<int, bool> false_val{false};
    assert(m_int_bool_int(number) == 7);
    assert(m_int_bool_int(true_val) == 0);
    assert(m_int_bool_int(false_val) == 1);

    constexpr int proof_coproduct_value = -1;
    Either<int, bool> proof_coproduct_unique_1 = m_int_bool_either_1(proof_coproduct_value);
    Either<int, bool> proof_coproduct_unique_2 = m_int_bool_either_2(proof_coproduct_value);
    assert(proof_coproduct_unique_1.getLeft() == 0);
    assert(proof_coproduct_unique_2.getLeft() == -1);
    assert(m_int_bool_int_2(proof_coproduct_unique_1) == m_int_bool_int_2(proof_coproduct_unique_2));

    std::cout << "All tests passed." << "\n";
    return 0;
}
