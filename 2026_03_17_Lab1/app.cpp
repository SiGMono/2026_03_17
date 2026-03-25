#include <iostream>
#include <cmath>

using namespace std;

class Figura{       //Klasa abstrakcyjna
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

class Prostokat : public Figura{
    private:
        int a,b;
    public:
        int obliczPole() override{
            return a*b;
        }
        int obliczObwod() override{
            return 2*a + 2*b;
        }
    
    Prostokat(int a,int b){
        this->a=a;
        this->b=b;
    }
};

class Trojkat : public Figura{
    private:
        int a,b,c;
    public:
        int obliczPole() override{
            int p = (a+b+c)/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }
        int obliczObwod() override{
            return a+b+c;
        }

    Trojkat(int a, int b, int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
};



int main(int argc, char const *argv[])
{
    //Tworzenie obiektów klas
    Kwadrat *kwadrat1 = new Kwadrat(4);
    Kolo *kolo1 = new Kolo(3);
    Prostokat *prostokat1 = new Prostokat(3,4);
    Trojkat *trojkat1 = new Trojkat(5,5,4);
    Figura *user;

    int decyzja = -1;

    do{
        cout<<"     <---------->     "<<endl;
        cout<<"1 - Kolo"<<endl;
        cout<<"2 - Kwadrat"<<endl;
        cout<<"3 - Prostokat"<<endl;
        cout<<"4 - Trojkat"<<endl;
        cout<<"5 - pole figury"<<endl;
        cout<<"6 - obwod figury"<<endl;
        cout<<"0 - exit"<<endl;

        cin>>decyzja;

        switch(decyzja){
            case 1:
                user = kolo1;
                break;
            case 2:
                user = kwadrat1;
                break;
            case 3:
                user = prostokat1;
                break;
            case 4:
                user = trojkat1;
                break;
            case 5:
                if(user != nullptr) cout<<"Pole to: "<<user->obliczPole();
                else cout<<"Najpierw wybierz figure";
                break;
            case 6:
                if(user != nullptr) cout<<"Obwod to: "<<user->obliczObwod();
                else cout<<"Najpierw wybierz figure";
                break;
            case 0:
                break;
            default:
                cout<<"Nieznana opcja";
                break;
        }

    }while(decyzja != 0);

    delete(kwadrat1, kolo1, prostokat1, trojkat1);
    return 0;
}
