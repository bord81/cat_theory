#ifndef CAT_THEORY_EITHER_H
#define CAT_THEORY_EITHER_H

template<class A, class B>
class Either {
    bool _isLeft;
    A _valueLeft;
    B _valueRight;
public:

    Either(A v) : _isLeft(true), _valueLeft(v) {}

    Either(B v) : _isLeft(false), _valueRight(v) {}

    bool isLeft() const { return _isLeft; }

    A getLeft() const { return _valueLeft; }

    B getRight() const { return _valueRight; }
};

#endif //CAT_THEORY_EITHER_H
