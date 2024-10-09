#include "main.h"
#include "lemlib/api.hpp" 

extern pros::ADIDigitalOut pistonSolenoid; // Replace 'A' with your actual port


class Tilter
{
    public:
    void grab(void* param);
    void release();
    void tilterToggle();
};

// Make the Tilter object available globally
extern Tilter tilter;
