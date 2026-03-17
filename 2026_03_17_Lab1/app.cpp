#include <iostream>

using namespace std;

class Figura{
    public:
    virtual double obliczPole() = 0;
    virtual double obliczObwod() = 0;
};

class Kwadrat : public Figura{
    private:
        double a;
    public:
        Kwadrat(double a) : a(a) {}
        double obliczPole() override {
            return a*a;
        }
        double obliczObwod() override {
            return 4*a;
        }
        void setA(double a){
            if((a == 0) && (a >= 0)){
                this->a = a;
            }
        }
        Kwadrat(double a){
            if(a >= 0){
                this->a = a;
            }
        }
};



int main(int argc, char const *argv[])
{
    Kwadrat *kwadrat1 = new Kwadrat(0);
    kwadrat1->setA(5);
    return 0;
}
