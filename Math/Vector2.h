//
// Created by kufuk on 23.01.2023.
//

#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

template<class ValueType>
struct Vector2
{
    ValueType x{0};
    ValueType y{0};

    Vector2(ValueType _x, ValueType _y) : x(_x), y(_y) {}
    explicit Vector2(ValueType value) : x(value), y(value) {}

    Vector2 operator+(const Vector2& other) const {return {this->x + other.x, this->y + other.y};}
    Vector2 operator+(ValueType value) const {return {this->x + value, this->y + value};}
    Vector2 operator-(const Vector2& other) const {return {this->x - other.x, this->y - other.y};}
    Vector2 operator-(ValueType value) const {return {this->x - value, this->y - value};}

    Vector2 operator*(const Vector2& other) const {return {this->x * other.x, this->y * other.y};}
    Vector2 operator*(ValueType value) const {return {this->x * value, this->y * value};}
    Vector2 operator/(const Vector2& other) const {return {this->x / other.x, this->y / other.y};}
    Vector2 operator/(ValueType value) const {return {this->x / value, this->y / value};}

    Vector2& operator=(ValueType value)
    {
        this->x = value;
        this->y = value;
        return  *this;
    }

    Vector2 operator+=(const Vector2& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    bool operator==(Vector2& other) const { return this->x == other.x && this->y == other.y; }

    explicit operator std::string()
    {
        return "Vector2(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    }

    [[nodiscard]]
    ValueType len() const { return sqrt(x*x + y*y); }

    [[nodiscard]]
    ValueType sqLen() const { return x*x + y*y; }
};

#endif //VECTOR2_H
