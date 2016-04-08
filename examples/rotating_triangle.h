#ifndef ROTATING_TRIANGLE
#define ROTATING_TRIANGLE

class RotatingTriangle
{
    public:
        bool init();
        void prepare(float dt);
        void render();
        void shutdown();

        void on_resize(int width, int height);
    protected:
    private:
        float m_rotating_angle;
};

#endif //ROTATING_TRIANGLE
