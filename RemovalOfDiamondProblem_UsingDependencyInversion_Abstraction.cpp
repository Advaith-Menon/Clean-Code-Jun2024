#include <iostream>

//contract, interface, abstraction
class IPrintableDevice
{
    public:
    virtual void print() = 0;
};
class IScanner
{
    public:
    virtual void scan() = 0;
};
class D
{
    private:
        int val;
    protected: // protected constructor to ensure abstract class
        D(int x) { val = x; std::cout << "D Constructor, val = " << val << std::endl;}
    public:
        ~D() { std::cout << "D destructor called " << std::endl;}
        void printVal() { std::cout << "Val in D = " << val << std::endl;}
    
};


class P : public D, public IPrintableDevice // here class D is an example of inheritance, and interface IPrintableDevice is an example of abstraction adn runtime polymorphism
{
    public:
        P() : D(1) { std::cout << "P Constructor" << std::endl;} // we must pass D(1) as the constructor for D requires an integer argument
        ~P() { std::cout << "P destructor called " << std::endl;}
        void print() { std::cout << "Printing..." << std::endl;}
};
 
class S : public D, public IScanner
{
    public:
        S() : D(2)
        { std::cout << "S Constructor" << std::endl;}
        ~S() { std::cout << "S destructor called " << std::endl;}
        void scan() { std::cout << "Scanning..." << std::endl;}
};
 
class PS: public D, public IPrintableDevice, public IScanner
{
    public:
        IPrintableDevice* pobj; // since it is an interface, we cannot make an object, we make a pointer
        IScanner* sobj;
        PS(int x,IScanner *sAddress,IPrintableDevice *pAddress) : D(x),sobj{sAddress},pobj{pAddress} // example of constructor injection, a way to perform Dependency Injection
        { 
            std::cout << "PS Constructor" << std::endl;  // if we separately create objects of P and S, it would result in tightly coupled code between two concrete implementations. To avoid this, we use Dependency Injection
        }
        ~PS() { std::cout << "PS destructor called " << std::endl;}
        
        void print()
        {
            //delegation
            pobj->print();
        }
        void scan()
        {
            sobj->scan();
        }
};
 
void printTask(IPrintableDevice* ptr)
{
    ptr->print();
}
 
void scanTask(IScanner* ptr)
{
    ptr->scan();
}
 
int main()
{
    P pObj;
    S sObj;
    PS psObj{10,&sObj,&pObj};
 
    printTask(&pObj);
    printTask(&psObj);
 
    scanTask(&sObj);
    scanTask(&psObj);
    
    return 0;
}
