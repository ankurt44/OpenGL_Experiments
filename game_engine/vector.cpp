#include<math.h>

#include"vector.h"

Vector2f::Vector2f(int x, int y):x(x), y(y){}

float Vector2f::length()
{
    return sqrt(x*x + y*y);
}

float Vector2f::dotProduct(Vector2f other)
{
    return x*other.getX() + y*other.getY();
}

Vector2f& Vector2f::normalize()
{
    float len = length();
    x = x/len;
    y = y/len;

    return *this;
}

Vector2f Vector2f::rotate(float angle)
{
    double rad = toRadians(angle);
    double cos_val = cos(rad);
    double sin_val = sin(rad);
    Vector2f result((float)x*cos_val - y*sin_val, (float) x*sin_val - y*cos_val);
    return result;
}

Vector2f Vector2f::add(Vector2f& other)
{
    Vector2f result(x+other.getX(), y+other.getY());
    return result;
}

Vector2f Vector2f::add(float scalar)
{
    Vector2f result(x+scalar, y+scalar);
        return result;
}

Vector2f Vector2f::sub(Vector2f& other)
{
    Vector2f result(x-other.getX(), y-other.getY());
    return result;
}

Vector2f Vector2f::sub(float scalar)
{
    Vector2f result(x-scalar, y-scalar);
    return result;
}

Vector2f Vector2f::mul(Vector2f& other)
{
    Vector2f result(x*other.getX(), y*other.getY());
    return result;
}

Vector2f Vector2f::mul(float scalar)
{
    Vector2f result(x*scalar, y*scalar);
        return result;
}

Vector2f Vector2f::div(Vector2f& other)
{
    Vector2f result(x/other.getX(), y/other.getY());
    return result;
}

Vector2f Vector2f::div(float scalar)
{
    Vector2f result(x/scalar, y/scalar);
        return result;
}

float Vector2f::getX()
{
    return x;
}

void Vector2f::setX(float x)
{
    this->x = x;
}

float Vector2f::getY()
{
    return y;
}

void Vector2f::setY(float y)
{
    this->y = y;
}

double Vector2f::toRadians(double angle)
{
    return angle*M_PI/180;
}

Vector3f::Vector3f(int x, int y, int z):x(x), y(y), z(z){}

float Vector3f::length()
{
    return sqrt(x*x + y*y + z*z);
}

float Vector3f::dotProduct(Vector3f other)
{
    return x*other.getX() + y*other.getY() + z*other.getZ();
}

Vector3f& Vector3f::normalize()
{
    float len = length();
    x = x/len;
    y = y/len;
    z = z/len;

    return *this;
}

Vector3f Vector3f::cross_product(Vector3f other)
{
    float x_ = y*other.getZ() - z*other.getY();
    float y_ = z*other.getX() - x*other.getZ();
    float z_ = x*other.getY() - y*other.getX();
    return *(new Vector3f(x_, y_, z_));
}

Vector3f Vector3f::add(Vector3f& other)
{
    Vector3f result(x+other.getX(), y+other.getY(), z+other.getZ());
    return result;
}

Vector3f Vector3f::add(float scalar)
{
    Vector3f result(x+scalar, y+scalar, z+scalar);
        return result;
}

Vector3f Vector3f::sub(Vector3f& other)
{
    Vector3f result(x-other.getX(), y-other.getY(), z-other.getZ());
    return result;
}

Vector3f Vector3f::sub(float scalar)
{
    Vector3f result(x-scalar, y-scalar, z-scalar);
        return result;
}

Vector3f Vector3f::mul(Vector3f& other)
{
    Vector3f result(x*other.getX(), y*other.getY(), z*other.getZ());
    return result;
}

Vector3f Vector3f::mul(float scalar)
{
    Vector3f result(x*scalar, y*scalar, z*scalar);
        return result;
}

Vector3f Vector3f::div(Vector3f& other)
{
    Vector3f result(x/other.getX(), y/other.getY(), z/other.getZ());
    return result;
}

Vector3f Vector3f::div(float scalar)
{
    Vector3f result(x/scalar, y/scalar, z/scalar);
        return result;
}

float Vector3f::getX()
{
    return x;
}

void Vector3f::setX(float x)
{
    this->x = x;
}

float Vector3f::getY()
{
    return y;
}

void Vector3f::setY(float y)
{
    this->y = y;
}

float Vector3f::getZ()
{
    return z;
}

void Vector3f::setZ(float z)
{
    this->z = z;
}
