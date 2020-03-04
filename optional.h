#ifndef CAT_THEORY_OPTIONAL_H
#define CAT_THEORY_OPTIONAL_H

template<class A>
class optional {
    bool _isValid;
    A _value;
public:
    optional() : _isValid(false) {}

    optional(A v) : _isValid(true), _value(v) {}

    bool isValid() const { return _isValid; }

    A value() const { return _value; }
};

#endif //CAT_THEORY_OPTIONAL_H
