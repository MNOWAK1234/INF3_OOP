#include <iostream>

using namespace std;

class TwoArgumentsOperators
{
private:
    int a,b;
public:
    parameters(int a, int b)
    {
        this->a=a;
        this->b=b;
    }
    int maximum()
    {
        return max(a,b);
    }
    int minimum()
    {
        return min(a,b);
    }
    double average()
    {
        return ((double)a+(double)b)/2;
    }
};

int main()
{
    TwoArgumentsOperators numberOneAndTwo;
    numberOneAndTwo.parameters(3,2);
    cout<<numberOneAndTwo.maximum()<<endl;
    cout<<numberOneAndTwo.minimum()<<endl;
    cout<<numberOneAndTwo.average()<<endl;
}

