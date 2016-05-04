#ifndef VECTOR_H
#define VECTOR_H

class Vector2f
{
    public:
        Vector2f(int x, int y);
        float length();
        float dotProduct(const Vector2f other);
        Vector2f& normalize();
        Vector2f rotate(float angle);  //rotate vector
        Vector2f add(Vector2f& other);
        Vector2f add(float scalar);
        Vector2f sub(Vector2f& other);
        Vector2f sub(float scalar);
        Vector2f mul(Vector2f& other);
        Vector2f mul(float scalar);
        Vector2f div(Vector2f& other);
        Vector2f div(float scalar);
        float getX();
        void setX(float x);
        float getY();
        void setY(float y);
        static double toRadians(double angle);
    protected:
    private:
        float x;
        float y;
};

class Vector3f
{
    public:
        Vector3f(int x, int y, int z);
        float length();
        float dotProduct(const Vector3f other);
        Vector3f& normalize();
        Vector3f cross_product(Vector3f other);
        Vector3f add(Vector3f& other);
        Vector3f add(float scalar);
        Vector3f sub(Vector3f& other);
        Vector3f sub(float scalar);
        Vector3f mul(Vector3f& other);
        Vector3f mul(float scalar);
        Vector3f div(Vector3f& other);
        Vector3f div(float scalar);
        float getX();
        void setX(float);
        float getY();
        void setY(float);
        float getZ();
        void setZ(float);
    protected:
    private:
        float x;
        float y;
        float z;
};

#endif //VECTOR_H
