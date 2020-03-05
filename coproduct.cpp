#include "either.h"

int injection_int_1(int n) { return n; }

int injection_int_2(int n) {
    if (n < 0) return n;
    return n - 1;
}

int injection_bool(bool b) { return b ? 0 : 1; }

int m_int_bool_int(Either<int, bool> const &e) {
    if (e.isLeft()) {
        return injection_int_1(e.getLeft());
    } else {
        return injection_bool(e.getRight());
    }
}

int m_int_bool_int_2(Either<int, bool> const &e) {
    if (e.isLeft()) {
        return injection_int_2(e.getLeft());
    } else {
        return injection_bool(e.getRight());
    }
}


// Inferior morphisms for m_int_bool_int_2
Either<int, bool> m_int_bool_either_1(int v) {
    if (v == 0) {
        return Either<int, bool>(true);
    } else if (v == 1) {
        return Either<int, bool>(false);
    } else if (v == -1) {
        return Either<int, bool>(0);
    } else if (v < 0) {
        return Either<int, bool>(v);
    } else {
        return Either<int, bool>(v + 1);
    }
}

Either<int, bool> m_int_bool_either_2(int v) {
    if (v == 0) {
        return Either<int, bool>(true);
    } else if (v == 1) {
        return Either<int, bool>(false);
    } else if (v == -1) {
        return Either<int, bool>(-1);
    } else if (v < 0) {
        return Either<int, bool>(v);
    } else {
        return Either<int, bool>(v + 1);
    }
}