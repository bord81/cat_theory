#ifndef CAT_THEORY_SUM_TYPE_H
#define CAT_THEORY_SUM_TYPE_H

class Shape {
public:
    [[nodiscard]] virtual double area() const = 0;

    [[nodiscard]] virtual double circ() const = 0;
};

class Circle : public Shape {
public:
    Circle(float r);

    [[nodiscard]] double area() const override;

    [[nodiscard]] double circ() const override;

private:
    double _radius;
};

class Rect : public Shape {
public:
    Rect(double w, double h);

    [[nodiscard]] double area() const override;

    [[nodiscard]] double circ() const override;

private:
    double _width;
    double _height;
};

class Square : public Shape {
public:
    Square(double s);

    [[nodiscard]] double area() const override;

    [[nodiscard]] double circ() const override;

private:
    double _side;
};

#endif //CAT_THEORY_SUM_TYPE_H
