#ifndef MAIN_COMPONENT
#define MAIN_COMPONENT

class MainComponent
{
public:
    MainComponent();
    void start();
    void stop();
protected:
private:
    void run();
    void render();
    void cleanUp();
    
    bool m_is_running;
    
};

#endif //MAIN_COMPONENT
