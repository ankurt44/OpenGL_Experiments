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
        
        //operator overloading for vector addition, mult, div, sub
        //if not "friend", take only one vector as arguement
        friend Vector2f operator+(const Vector2f& v1, const Vector2f& v2);
        friend Vector2f operator+(const Vector2f& v1, float val);
        friend Vector2f operator-(const Vector2f& v1, const Vector2f& v2);
        friend Vector2f operator-(const Vector2f& v1, float val);
        friend Vector2f operator*(const Vector2f& v1, const Vector2f& v2);
        friend Vector2f operator*(const Vector2f& v1, float val);
        friend Vector2f operator/(const Vector2f& v1, const Vector2f& v2);
        friend Vector2f operator/(const Vector2f& v1, float val);
        
        //getter and setter
        float getX() const;
        void setX(float x);
        float getY() const;
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
        
        //add sub mult div of vectors
        friend Vector3f operator+(const Vector3f& v1, const Vector3f& v2);
        friend Vector3f operator+(const Vector3f& v1, float val);
        friend Vector3f operator-(const Vector3f& v1, const Vector3f& v2);
        friend Vector3f operator-(const Vector3f& v1, float val);
        friend Vector3f operator*(const Vector3f& v1, const Vector3f& v2);
        friend Vector3f operator*(const Vector3f& v1, float val);
        friend Vector3f operator/(const Vector3f& v1, const Vector3f& v2);
        friend Vector3f operator/(const Vector3f& v1, float val);
        
        //getter and setter
        float getX() const;
        void setX(float);
        float getY() const;
        void setY(float);
        float getZ() const;
        void setZ(float);
    protected:
    private:
        float x;
        float y;
        float z;
};

#endif //VECTOR_H
