#include "main.h"
#include "lemlib/api.hpp"




class Drive {
    public:
    void run();
    void override();
    bool done();
    void moveLinear(float disp, float speed);
    void IMUTurn(float degrees);
    void moveTurn(float disp, float endAngle, float speed);
};

extern Drive d;

extern void tankDrive();
extern void arcadeDrive();