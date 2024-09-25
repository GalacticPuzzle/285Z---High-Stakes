#include "main.h"
#include "lemlib/api.hpp" 

extern pros::Motor IntakeMotor; // Declaration

class Intake
{
    public:
    void run(void* param);
    void reverse();
    void intakeUntil();
};

extern Intake in;