#include <iostream>
#include <cmath>

using namespace std;

class Number
{
public:
    virtual double doubleValue()=0;
};

class Logarithm : public Number
{
private:
    double base,argument;
public:
    parameters(double base, double argument)
    {
        this->base=base;
        this->argument=argument;
    }
    double doubleValue()
    {
        if(this->base<=0)throw(1);
        else if(this->base==1)throw(2);
        else if(this->argument<=0)throw(3);
        else return log(this->argument)/log(this->base);
    }
};

int main()
{
    double testBase,testArgument;
    cin>>testBase>>testArgument;
    try
    {
        Logarithm numbersOneAndTwo;
        numbersOneAndTwo.parameters(testBase,testArgument);
        cout<<numbersOneAndTwo.doubleValue()<<endl;
    }
    catch(int i)
    {
        cout<<"Logarithm of a positive number x to the positive base b!=1 is the exponent to which b must be raised, to produce x."<<endl;
        cout<<endl;
        cout<<"Error: ";
        if(i==1)cout<<"Base must be positive."<<endl;
        else if(i==2)cout<<"Base must not be equal to 1."<<endl;
        else if(i==3)cout<<"Argument must be positive."<<endl;
    }
}
