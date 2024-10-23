#include "main.h"
#include "lemlib/api.hpp" 

extern pros::Motor IntakeMotor; // Declaration
extern pros::Motor ConveyorMotor;
extern int intakeB;

class Intake
{
    public:
    void run(void* param);
    void reverse();
    void intakeUntil();
    void intakeIn();
    void runAutonIn(int second);
    void runAutonOut(int second);
    void stopAuton();
};

extern Intake intake;