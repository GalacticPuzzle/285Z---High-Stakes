#pragma once

class Lift {
public:  // Ensure methods are accessible outside the class
    void liftUp();
    void liftDown();
    void liftToggle();
};

// Declare the external Lift object
extern Lift Arm;
