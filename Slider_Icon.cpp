#include <iostream>
using namespace std;
#include "I_Icon.h"
class Slider_Icon : public Icon
{
    public:
    Slider_Icon(){}
    bool vertical; // need for slider
    int distance; // need for slider
    void slide()
    {

    }
    void move()
    {
        cout<<"Slider move function";
    }
    void flair()
    {
        cout<<"Slider flair function";
    }
}; 
