#include <iostream>
using namespace std;
#include "I_Icon.h"
class Spinner_Icon : public Icon
{
    public:
    bool clockwise; // need for spinner
    bool expand; // need for spinner
    void spin()
    {

    }
    void move()
    {
        cout<<"Spinner move function";
    }
    void flair()
    {
        cout<<"Spinner flair function";
    }
};
