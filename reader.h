#ifndef CAT_THEORY_READER_H
#define CAT_THEORY_READER_H

#include <functional>

template<class T>
struct AsFunction : public AsFunction<decltype(&T::operator())> {
};

template<class ReturnType, class... Args>
struct AsFunction<ReturnType(Args...)> {
    using type = std::function<ReturnType(Args...)>;
};

template<class ReturnType, class... Args>
struct AsFunction<ReturnType(*)(Args...)> {
    using type = std::function<ReturnType(Args...)>;
};


template<class Class, class ReturnType, class... Args>
struct AsFunction<ReturnType(Class::*)(Args...) const> {
    using type = std::function<ReturnType(Args...)>;
};

template<class F>
auto toFunction(F f) -> typename AsFunction<F>::type {
    return {f};
}

template<class A, class B, class R>
B fmap(const std::function<B(A)> &funcA, const std::function<A(R)> &funcR, R value) {
    return funcA(funcR(value));
}

template<class T>
auto ToFunction(T t) {
    return t;
}

#endif //CAT_THEORY_READER_H
