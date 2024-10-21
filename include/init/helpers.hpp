#include "main.h"
#include "lemlib/api.hpp" 
#include "../../init/auton.hpp"


extern int aut; // Autonomous index


extern void intakeIn(int seconds);  // Declare the intakeIn function
extern void clampOn();
extern void clampOff();
extern void move(double distance);
extern void cycleAutonMode();
extern void setAutonMode();


