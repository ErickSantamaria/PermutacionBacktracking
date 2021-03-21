#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Permutacion{
private:
    char* palabra;
    void intercambiar(char*,char*);
public:
    int get_tam_palabra();
    Permutacion(){};
    void permutar(int, int);

    //Sobrecarga de operadores no miembros
    friend ostream& operator << (ostream &o,const Permutacion &p);
    friend istream& operator >> (istream &o, Permutacion &p);
};

void Permutacion::intercambiar(char* p1, char* p2)
{
    char aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void Permutacion::permutar(int l, int r)
{
    if(l == r)
    {
        cout<<palabra<<endl;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            intercambiar((palabra+1),(palabra+i));
            permutar(l+1,r);
            intercambiar((palabra+1),(palabra+i)); //Vuelta atras
        }
    }
}

istream& operator >> (istream &i, Permutacion &p)
{
    cout << "Ingrese la palabra que desea permutar: ";
    p.palabra = new char[30];
    i>>p.palabra;
    i.ignore();
    return i;
}

ostream& operator << (ostream &o,const Permutacion &p)
{
    o<<"Palabra: "<<p.palabra<<endl;
    return o;
}

int Permutacion::get_tam_palabra()
{
    return strlen(palabra);
}
