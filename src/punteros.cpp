#include <iostream>
using namespace std;

int main (int argc, char const *argv[])
{
    int *pNumeroNuevo =NULL;

    pNumeroNuevo = new int;
    
    *pNumeroNuevo = 25;

std :: cout <<"direccion : " <<pNumeroNuevo << '\n';
std :: cout <<"valor: " << *pNumeroNuevo << '\n';

cout<< "Tipos de datos : " << endl;
cout << "Tamanño int: " << sizeof (int) <<endl;
cout << "Tamanño long: " << sizeof (long) <<endl;
cout << "Tamanño float: "<< sizeof (float) <<endl;
cout << "Tamanño double: "<< sizeof (double) <<endl;
cout << "Tamanño char: "<< sizeof (char) <<endl;
cout << "Tamanño bool: "<< sizeof (bool) <<endl;
cout << "Tamanño byte: "<< sizeof (byte) <<endl;
return 0;
}