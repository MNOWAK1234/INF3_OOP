#include <iostream>

using namespace std;

class glass
{
public:
    string shape;
    double xmax,ymax,zmax;
    int level_of_hardness;
    string usage;
    //default constructor
    glass()
    {
        shape="irregular";
        ymax=10.4;
        xmax=7.6;
        zmax=8.9;
        level_of_hardness=9;
        usage="window";
        cout<<"Created default glass"<<endl;
    }
    //parametrised
    glass(double x, double y, double z)
    {
        xmax=x;
        ymax=y;
        zmax=z;
    }
    glass(string s, double param)
    {
        shape=s;
        xmax=ymax=zmax=param;
    }
    glass(glass &obj)
    {
        shape=obj.shape;
        level_of_hardness=obj.level_of_hardness;
    }
    glass(glass &obj, int magnify)
    {
        shape=obj.shape;
        xmax=obj.xmax*magnify;
        ymax=obj.ymax*magnify;
        zmax=obj.zmax*magnify;
    }
    double volume()
    {
        if(shape=="sphere") return xmax*ymax*zmax*3.14/8;
        else if(shape=="cube")return xmax*xmax*xmax;
        else return xmax*ymax*zmax;
    }
};

int main()
{
    glass random;
    glass one(10,10,10);
    cout<<one.volume()<<endl;
    glass two("cube", 10);
    cout<<two.volume()<<endl;
    glass copied(random);
    cout<<copied.level_of_hardness<<endl;
    glass sph ("sphere", 10);
    cout<<sph.volume()<<endl;
    glass magnified(sph,2);
    cout<<magnified.volume()<<endl;
}
