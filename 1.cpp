#include <iostream>

using namespace std;

class human
{
    public:
        string F_name;
        string L_name;
        int age;
        bool male;
        void saysth(string what, string who)
        {
            cout<<who<<" check out this: "<<what<<endl;
        }

};
class device
{
    public:
        string type;
        bool electrical;
        string ID;
        string owner;
};
class action
{
    public:
        string name;
        string performer;
        bool timeconsuming;
        int difficulity; //scale 1-10
        bool change_gender(int m)
        {
            if(m<5)return 1;
            else return 0;
        }
};

int main()
{
    human me;
    me.F_name="Mikolaj";
    me.L_name="Nowak";
    me.age=20;
    me.male=1;

    device my_computer;
    my_computer.type="machine";
    my_computer.electrical=1;
    my_computer.ID="234.235.0.67";
    //my_computer.owner=me;

    action typing;
    typing.name="coding";
    typing.timeconsuming=0;
    typing.difficulity=6;
    //typing.performer=me;

    me.saysth("WORD!",me.F_name);
    cout<<me.male<<endl;
    me.male=typing.change_gender(typing.difficulity);
    cout<<me.male<<endl;
}
