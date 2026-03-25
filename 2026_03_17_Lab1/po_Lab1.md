# Zadanie laboratoryjne  

![VS Code](https://img.shields.io/badge/IDE-VS%20Code-007ACC?logo=visualstudiocode&logoColor=white)
![Visual Studio](https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?logo=visualstudio&logoColor=white)
![IntelliJ IDEA](https://img.shields.io/badge/IDE-IntelliJ%20IDEA-000000?logo=intellijidea&logoColor=white)
![Mermaid](https://img.shields.io/badge/Diagram-Mermaid-FF3670?logo=mermaid&logoColor=white)
![GitHub Markdown](https://img.shields.io/badge/Format-GitHub%20Markdown-181717?logo=github&logoColor=white)

[![C++ Reference](https://img.shields.io/badge/Dokumentacja-C%2B%2B%20Reference-00599C?logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/)
[![Java Documentation](https://img.shields.io/badge/Dokumentacja-Java%20Docs-ED8B00?logo=openjdk&logoColor=white)](https://docs.oracle.com/en/java/)

**Przedmiot:** *Programowanie obiektowe*  

## <img src="https://img.icons8.com/color/48/student-male--v1.png" alt="Piktogram dane studenta" width="24" /> Dane studenta



| Pole | Wartość |
|---|---|
| Imię i nazwisko | Szymon Zeller |
| Numer albumu | 10149 |
| Kierunek / specjalność | Informatyka |
| Rok/Semestr | I |
| Grupa laboratoryjna | grupa 1 |
| Rok akademicki |  2025/2026 |
| Prowadzący | mgr inż. Artur Pelo |

## <img src="https://img.icons8.com/color/48/info--v1.png" alt="Piktogram informacje o zadaniu" width="24" /> Informacje o zadaniu

| Pole | Wartość |
|---|---|
| Numer laboratorium | 1 |
| Temat laboratorium | Podstawy programowania obiektowego - dziedziczenie i polimorfizm |
| Data realizacji | 24.03.2026 |
| Data oddania | 25.03.2026 |
| Język programowania | CPP |
| Środowisko / IDE | VSC |

## <img src="https://img.icons8.com/color/48/task.png" alt="Piktogram tresc zadania" width="24" /> Treść zadania

Krótki opis zadania:

Napisz program, który umożliwa obliczanie pola i obwodu figur płaskich.
Figury to kolo, kwadrat i trójkąt. Zastosuj polimorfizm.

## <img src="https://img.icons8.com/color/48/checklist.png" alt="Piktogram wymagania funkcjonalne" width="24" /> Wymagania funkcjonalne

| ID | Opis wymagania | Poziom |
|---|---|---|
| WF-01 | Program umożliwia wybór figury: koło, kwadrat lub trójkąt. | Wysoki |
| WF-02 | Dla każdej figury program oblicza pole. | Wysoki |
| WF-03 | Dla każdej figury program oblicza obwód. | Wysoki |
| WF-04 | Implementacja wykorzystuje klasę abstrakcyjną i polimorfizm w klasach potomnych. | Wysoki |

## <img src="https://img.icons8.com/color/48/inspection.png" alt="Piktogram wymagania niefunkcjonalne" width="24" /> Wymagania niefunkcjonalne

| ID | Opis wymagania | Poziom |
|---|---|---|
| WN-01 | Kod jest napisany w języku C++ zgodnie z zasadami programowania obiektowego. | Wysoki |
| WN-02 | Program kompiluje się bez błędów w standardowym kompilatorze C++ (np. g++). | Wysoki |
| WN-03 | Kod jest czytelny i podzielony na klasy odpowiadające figurom. | Średni |
| WN-04 | Interfejs tekstowy programu zawiera jasne komunikaty dla użytkownika. | Średni |

## <img src="https://img.icons8.com/color/48/workflow.png" alt="Piktogram realizacja zadania" width="24" /> Realizacja zadania



Opis implementacji:

Program spełnia wszystkie wymagania funkcjonalne oraz niefunkcjonalne.

## <img src="https://img.icons8.com/color/48/class.png" alt="Piktogram diagram klas" width="24" /> Diagram klas (jeśli dotyczy)

```mermaid
classDiagram
	class Figura {
		<<abstract>>
		+obliczPole() int
		+obliczObwod() int
		+~Figura()
	}

	class Kolo {
		-promien : int
		+Kolo(promien : int)
		+obliczPole() int
		+obliczObwod() int
	}

	class Kwadrat {
		-bok : int
		+Kwadrat(bok : int)
		+obliczPole() int
		+obliczObwod() int
	}

	class Prostokat {
		-a : int
		-b : int
		+Prostoka(a : int, b : int)
		+obliczPole() int
		+obliczObwod() int	
	}

	class Trojkat {
		-a : int
		-b : int
		-c : int
		+Trojkat(a : int, b : int, c : int)
		+obliczPole() int
		+obliczObwod() int
		-czyPoprawny() int
	}

	class main {
		+uruchom() void
		+utworzFigure(typ : int) Figura*
	}

	Figura <|-- Kolo
	Figura <|-- Kwadrat
	Figura <|-- Trojkat
	Figura <|-- Prostokat
	main --> Figura : korzysta z
```
## <img src="https://img.icons8.com/color/48/source-code.png" alt="Piktogram kod zrodlowy" width="24" /> Kod źródłowy


### <img src="https://img.icons8.com/color/48/c-plus-plus-logo.png" alt="Piktogram C++" width="24" /> C++

```cpp
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


```

## <img src="https://img.icons8.com/color/48/combo-chart--v1.png" alt="Piktogram wynik dzialania" width="24" /> Wynik działania programu

Opis testów i przykładowe wyniki:

Wybranie trójkąta, wykonanie operacji pola i obwodu oraz wyjście z programu
```bash
PS D:\CODE\VSCODE\PRJ\programowanie_obiektowe\2026_03_17\2026_03_17_Lab1>  & 'c:\Users\Orrimano\.vscode\extensions\ms-vscode.cpptools-1.30.5-win32-x64\debugAdapters\bin\WindowsDebugLauncher.exe' '--stdin=Microsoft-MIEngine-In-enmwzkk4.q0v' '--stdout=Microsoft-MIEngine-Out-q0fmvbd3.liv' '--stderr=Microsoft-MIEngine-Error-krdjfytm.0bv' '--pid=Microsoft-MIEngine-Pid-4bs44awa.wou' '--dbgExe=C:\msys64\ucrt64\bin\gdb.exe' '--interpreter=mi' 
     <---------->     
1 - Kolo
2 - Kwadrat
3 - Prostokat
4 - Trojkat
5 - pole figury
6 - obwod figury
0 - exit
4
     <---------->     
1 - Kolo
2 - Kwadrat
3 - Prostokat
4 - Trojkat
5 - pole figury
6 - obwod figury
0 - exit
5
Pole to: 9     <---------->     
1 - Kolo
2 - Kwadrat
3 - Prostokat
4 - Trojkat
5 - pole figury
6 - obwod figury
0 - exit
6
Obwod to: 14     <---------->     
1 - Kolo
2 - Kwadrat
3 - Prostokat
4 - Trojkat
5 - pole figury
6 - obwod figury
0 - exit
0
PS D:\CODE\VSCODE\PRJ\programowanie_obiektowe\2026_03_17\2026_03_17_Lab1> 

```

Wybranie Kwadratu, wykonanie operacji pola i obwodu oraz wyjście z programu

```bash
PS D:\CODE\VSCODE\PRJ\programowanie_obiektowe\2026_03_17\2026_03_17_Lab1>  & 'c:\Users\Orrimano\.vscode\extensions\ms-vscode.cpptools-1.30.5-win32-x64\debugAdapters\bin\WindowsDebugLauncher.exe' '--stdin=Microsoft-MIEngine-In-naflwslr.3e5' '--stdout=Microsoft-MIEngine-Out-oxql4nnb.stj' '--stderr=Microsoft-MIEngine-Error-ijwwtdmc.ffn' '--pid=Microsoft-MIEngine-Pid-lk4k2s52.l2m' '--dbgExe=C:\msys64\ucrt64\bin\gdb.exe' '--interpreter=mi'
     <---------->     
1 - Kolo
2 - Kwadrat
3 - Prostokat
4 - Trojkat
5 - pole figury
6 - obwod figury
0 - exit
2
     <---------->     
1 - Kolo
2 - Kwadrat
3 - Prostokat
4 - Trojkat
5 - pole figury
6 - obwod figury
0 - exit
5
Pole to: 16     <---------->     
1 - Kolo
2 - Kwadrat
3 - Prostokat
4 - Trojkat
5 - pole figury
6 - obwod figury
0 - exit
6
Obwod to: 16     <---------->     
1 - Kolo
2 - Kwadrat
3 - Prostokat
4 - Trojkat
5 - pole figury
6 - obwod figury
0 - exit
0
PS D:\CODE\VSCODE\PRJ\programowanie_obiektowe\2026_03_17\2026_03_17_Lab1> 

```
## <img src="https://img.icons8.com/color/48/test-passed.png" alt="Piktogram samoocena" width="24" /> Samoocena studenta

| Kryterium | Tak / Nie | Uwagi |
|---|---|---|
| Program kompiluje się bez błędów | X |  |
| Wszystkie wymagania zostały spełnione | X |  |
| Kod jest czytelny i podzielony na klasy | X |  |
| Zastosowano zasady OOP | X |  |
| Zastosowano zasady czystego kodu | X |  |
| Zastosowano wzorce projektowe (jakie?) | X |  |



##Przesłanie pliu do oceny:
[![Upload ZIP](https://img.shields.io/badge/Upload-PO_KowalskiJan_Lab1.zip-2ea44f?logo=icloud&logoColor=white)](https://upload.pelo.com.pl) [zawartość, uzupełniony TEN plik oraz podfolder LAB1 z plikami zródłowymi]


## <img src="https://img.icons8.com/color/48/approval.png" alt="Piktogram ocena prowadzacego" width="24" /> Ocena prowadzącego

| Element oceny | Punkty maks. | Punkty uzyskane |
|---|---:|---:|
| Poprawność działania | 5 |  |
| Zastosowanie OOP | 5 |  |
| Jakość kodu | 3 |  |
| Terminowość oddania | 2 |  |
| **Suma** | **15** |  |

Uwagi prowadzącego:

................................................................................

................................................................................

Podpis prowadzącego: ........................................................

