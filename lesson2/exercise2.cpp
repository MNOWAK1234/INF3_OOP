#include <iostream>

using namespace std;

class toothbrush
{
public:
    string owner;
    double original_price;
    double discount;
    string colour;
    string manufacturer;
    toothbrush()
    {
        owner="me";
        original_price=1.6;
        discount=0;
        colour="red";
        manufacturer="teect";
    }
    toothbrush(double p, double d)
    {
        original_price=p;
        discount=d;
    }
    toothbrush(string own, string c)
    {
        owner=own;
        colour=c;
    }
    double price_after_reduction()
    {
        return original_price*(1-discount);
    }
    string opinion()
    {
        if(colour=="blue" && manufacturer.size()<6 && price_after_reduction()<5)return "good product";
        else return "bad product";
    }
    bool comp(toothbrush &one, toothbrush &two)
    {
        return one.discount>two.discount;
    }
};

int main()
{
    toothbrush myfriend();
    toothbrush bought(3.24, 0.5);
    cout<<bought.price_after_reduction()<<endl;
    toothbrush mine();
    //cout<<mine.opinion()<<endl;
    //one more method added to exercise1
}

