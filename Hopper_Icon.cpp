#include <iostream>
using namespace std;
#include "I_Icon.h"
class Hopper_Icon : public Icon
{
    public:
    bool visible; // need for hopper
    int xcoord, ycoord; // need for hopper
    void hop()
    {

    }
    void move()
    {
        cout<<"Hopper move function";
    }
    void flair()
    {
        cout<<"Hopper flair function";
    }
};
