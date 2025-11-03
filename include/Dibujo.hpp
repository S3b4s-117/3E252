#pragma once
#include <string>
#include <list>
using namespace std;

#include <ftxui/screen/screen.hpp>
using namespace ftxui;

class Dibujo
{
private:
   list<string> dibujo;
   int x = 0;
   int y = 0;


public:
   Dibujo()){
dibujo = {
    string("         (__)"),  
    string(" ` ------(oo)"),
    string("   ||    (__)"),
    string("   ||w--|| "),
}
~Dibujo(){}
   void Imprimir(Screen& pantalla){
    int fila = 0;
    for (auto &&linea : dibujo)
    {
        int columna = 0;
        for (auto &&letra : linea)
        {
            Pixel &pixel = pantalla.PixelAt(x +c
            pixel.character = letra;
            pixel.background_color = Color::Blue;
            pixel.foreground_color = Color::red;
            columna++;
            
        }
        fila++;
    }
   }
   void MoverDerecha(){
    x++;
   }
    void MoverIzquierda(){
    x--;
   }
    void MoverAbajo(){
    y++;
    }
    void MoverArriba(){
    y--;
    }
};