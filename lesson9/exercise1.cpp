#include <iostream>

using namespace std;

class Game{
    public:
    virtual int result()=0;
};

class FakeFootballGame : public Game {
    public:
    int result(){
        return 420;
    }
};

int main(){
    FakeFootballGame fake_game;
    cout<<fake_game.result()<<endl;
}
