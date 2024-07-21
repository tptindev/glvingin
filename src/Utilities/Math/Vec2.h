#ifndef VEC2_H
#define VEC2_H

#include <math.h>
#include <bits/move.h>

template<typename T>
class Vec2
{
public:
    Vec2(): m_x{static_cast<T>(0)},  m_y{static_cast<T>(0)}{}
    Vec2(T x, T y) : m_x(x), m_y(y) {}
    Vec2(const Vec2<T> &copy): m_x{copy.m_x}, m_y{copy.m_y}{}
    Vec2(Vec2<T> &&move): m_x{std::move(move.m_x)}, m_y{std::move(move.m_y)}{}
    Vec2<T> &operator=(const Vec2<T> &copy)
    {
        m_x = copy.m_x;
        m_y = copy.m_y;
    }
    Vec2<T> &operator=(Vec2<T> &&move)
    {
        m_x = std::move(move.m_x);
        m_y = std::move(move.m_y);
    }

    inline Vec2<T>& Zero()
    {
        m_x = static_cast<T>(0);
        m_y = static_cast<T>(0);
        return (*this);
    }

    inline Vec2<T>& One()
    {
        m_x = static_cast<T>(1);
        m_y = static_cast<T>(1);
        return (*this);
    }

    inline T x() const
    {
        return m_x;
    }

    inline void setX(const T &newX)
    {
        m_x = newX;
    }

    inline T y() const
    {
        return m_y;
    }

    inline void setY(const T &newY)
    {
        m_y = newY;
    }

    inline Vec2<T> operator+(const Vec2<T>& other)
    {
        return Vec2<T>(m_x + other.m_x, m_y + other.m_y);
    }

    inline Vec2<T>& operator+=(const Vec2<T>& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
        return (*this);
    }

    inline Vec2<T> operator-(const Vec2<T>& other)
    {
        return Vec2<T>(m_x - other.m_x, m_y - other.m_y);
    }

    inline Vec2<T>& operator-=(const Vec2<T>& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;
        return (*this);
    }

    inline bool operator==(const Vec2<T>& other)
    {
        return (m_x == other.m_x && m_y == other.m_y);
    }

    inline Vec2<T>& Scale(T n)
    {
        m_x *= n;
        m_y *= n;
        return (*this);
    }

    inline float Magnitude()
    {
        return std::sqrt(static_cast<float>(m_x * m_x + m_y * m_y));
    }

    inline Vec2<float> Normalize()
    {
        return Vec2<T>(static_cast<float>(m_x) / (Magnitude(), static_cast<float>(m_y) / Magnitude()));
    }

    inline float Distance(const Vec2<T>& other)
    {
        Vec2 vec(other.m_x - m_x, other.m_y - m_y);
        return vec.Magnitude();
    }

    inline float DotProduct(const Vec2<T>& other)
    {
        return (m_x * other.m_x + m_y * other.m_y);
    }

    inline float CrossProduct(const Vec2<T>& other)
    {
        return (m_x * other.m_x - m_y * other.m_y);
    }

    inline Vec2 Perp() //Perpendicular
    {
        return Vec2(-m_y, m_x);
    }


private:
    T m_x;
    T m_y;

};


#endif // VEC2_H
