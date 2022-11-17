#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class Car
{
private:
    double recommendedPerformance;
public:
    virtual string state()=0;
    Car tuning(double addedPerformance)return Car(this.recommendedPerformance+addedPerformance)
};
class Steering: public Car{
private:
    double angle;
    double velocity;
    double thresholdPerformance;
public:
    Steering brake(double distanceToObject)
    {
        return Steering(0,velocity*distanceToObject/10.0, thresholdPerformance);
    }
    string state()
    {
        string relation;
        if(velocity/angle>thresholdPerformance)relation=" above ";
        else relation=" below ";
        return to_string(abs(velocity/angle-thresholdPerformance))+relation+"threshold performance.";
    }
    Steering(double angle, double velocity, double thresholdPerformance)
    {
        this->angle=angle;
        this->velocity=velocity;
        this->thresholdPerformance=thresholdPerformance;
    }

};

int main()
{
    Steering Tesla(2.67,56,10);
    cout<<Tesla.state()<<endl;
    Steering Mercedes(3.43,66,14);
    Car MercedesUpgrade=Mercedes.tuning(4);
}
