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

Vector2f operator+(const Vector2f& v1, const Vector2f& v2)
{
    return *(new Vector2f(v1.getX()+v2.getX(), v1.getY()+v2.getY()));
}

Vector2f operator+(const Vector2f& v1, float val)
{
    return *(new Vector2f(v1.getX()+val, v1.getY()+val));
}

Vector2f operator-(const Vector2f& v1, const Vector2f& v2)
{
    return *(new Vector2f(v1.getX()-v2.getX(), v1.getY()-v2.getY()));
}
             
Vector2f operator-(const Vector2f& v1, float val)
{
    return *(new Vector2f(v1.getX()-val, v1.getY()-val));
}

Vector2f operator*(const Vector2f& v1, const Vector2f& v2)
{
    return *(new Vector2f(v1.getX()*v2.getX(), v1.getY()*v2.getY()));
}

Vector2f operator*(const Vector2f& v1, float val)
{
    return *(new Vector2f(v1.getX()*val, v1.getY()*val));
}

Vector2f operator/(const Vector2f& v1, const Vector2f& v2)
{
    return *(new Vector2f(v1.getX()/v2.getX(), v1.getY()/v2.getY()));
}

Vector2f operator/(const Vector2f& v1, float val)
{
    return *(new Vector2f(v1.getX()/val, v1.getY()/val));
}


//getter and setter
float Vector2f::getX() const
{
    return x;
}

void Vector2f::setX(float x)
{
    this->x = x;
}

float Vector2f::getY() const
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

Vector3f operator+(const Vector3f& v1, const Vector3f& v2)
{
    return *(new Vector3f(v1.getX()+v2.getX(), v1.getY()+v2.getY(), v1.getZ()+v2.getZ()));
}

Vector3f operator+(const Vector3f& v1, float val)
{
    return *(new Vector3f(v1.getX()+val, v1.getY()+val, v1.getZ()+val));
}

Vector3f operator-(const Vector3f& v1, const Vector3f& v2)
{
    return *(new Vector3f(v1.getX()-v2.getX(), v1.getY()-v2.getY(), v1.getZ()-v2.getZ()));
}

Vector3f operator-(const Vector3f& v1, float val)
{
    return *(new Vector3f(v1.getX()-val, v1.getY()-val, v1.getZ()-val));
}

Vector3f operator*(const Vector3f& v1, const Vector3f& v2)
{
    return *(new Vector3f(v1.getX()*v2.getX(), v1.getY()*v2.getY(), v1.getZ()*v2.getZ()));
}

Vector3f operator*(const Vector3f& v1, float val)
{
    return *(new Vector3f(v1.getX()*val, v1.getY()*val, v1.getZ()*val));
}

Vector3f operator/(const Vector3f& v1, const Vector3f& v2)
{
    return *(new Vector3f(v1.getX()/v2.getX(), v1.getY()/v2.getY(), v1.getZ()/v2.getZ()));
}

Vector3f operator/(const Vector3f& v1, float val)
{
    return *(new Vector3f(v1.getX()/val, v1.getY()/val, v1.getZ()/val));
}

float Vector3f::getX() const
{
    return x;
}

void Vector3f::setX(float x)
{
    this->x = x;
}

float Vector3f::getY() const
{
    return y;
}

void Vector3f::setY(float y)
{
    this->y = y;
}

float Vector3f::getZ() const
{
    return z;
}

void Vector3f::setZ(float z)
{
    this->z = z;
}
