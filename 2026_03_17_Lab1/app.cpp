#include <iostream>

using namespace std;

class Figura{
    public:
    virtual int obliczPole() = 0;
    virtual int obliczObwod() = 0;
};

class Kwadrat : public Figura{
    private:
        int a;
    public:
        Kwadrat(double a) : a(a) {}
        int obliczPole() override {
            return a*a;
        }
        int obliczObwod() override {
            return 4*a;
        }
        Kwadrat(int a){
            this->a=a;
        }
};

class Kolo : public Figura{
    private:
        int r;
    public:
        int obliczPole() override{
            return 2*3.14*r;
        }
        int obliczObwod() override{
            return 3.13*r*r;
        }
        Kolo(int r){
            this->r=r;
        }
};



int main(int argc, char const *argv[])
{
    Kwadrat *kwadrat1 = new Kwadrat(4);
    Kolo *kolo1 = new Kolo(3);
    Figura *user;

    int decyzja;

    do{
        cout<<"     <---------->     "<<endl;
        cout<<"1 - Kolo"<<endl;
        cout<<"2 - Kwadrat"<<endl;
        cout<<"5 - pole figury"<<endl;
        cout<<"6 - obwod figury"<<endl;
        cout<<"0 - exit"<<endl;

        if(decyzja == 1){ user = kolo1; }
        if(decyzja == 2){ user = kwadrat1; }
        if(decyzja == 5){ user -> obliczPole();}
        if(decyzja == 6){ user -> obliczObwod(); }

    }while(decyzja != 0);

    delete(kwadrat1, kolo1);
    return 0;
}
