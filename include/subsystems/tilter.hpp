#include "main.h"
#include "lemlib/api.hpp" 

class Tilter
{
    public:
    void grab();
    void release();
    void tilterToggle();
};

extern Tilter tilter;