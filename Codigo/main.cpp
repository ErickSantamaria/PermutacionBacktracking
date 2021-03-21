#include <iostream>
#include "Permutacion.h"
using namespace std;

int main()
{
    int n = 0;
    Permutacion p;
    cin>>p;
    cout<<p;
    n = p.get_tam_palabra();
    cout<<"\nLas posibles permutaciones que se pueden hacer son: "<<endl;
    p.permutar(0,n-1);
    return 0;
}

