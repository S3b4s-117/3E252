#pragma once
#include <string>
#include <list>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>

using namespace std;
using namespace ftxui;

class Dibujo
{
private:
    list<string> forma; 
    int x = 0;         
    int y = 0;         

public:
    
    Dibujo(const list<string>& pForma, int startX, int startY) 
        : forma(pForma), x(startX), y(startY) {}

    Dibujo() = default; 

    ~Dibujo(){} 

    
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    int getX() const { return x; }

    int getY() const { return y; }

    int getAncho() const {
        if (forma.empty()) return 0;
        
        size_t max_ancho = 0; 
        
        for (const auto& linea : forma) {
            if (linea.size() > max_ancho) {
                max_ancho = linea.size();
            }
        }
        return (int)max_ancho;
    }
    
    
    void Imprimir(Screen& pantalla, Color color) const {
        int fila = 0;
        for (auto const& linea : forma)
        {
            int columna = 0;
            for (char caracter : linea)
            {
                
                if (caracter != ' ') { 
                    
                    
                    if (x + columna < pantalla.dimx() && y + fila < pantalla.dimy()) {
                        Pixel &pixel = pantalla.PixelAt(x + columna, y + fila); 
                        pixel.character = caracter;
                        pixel.foreground_color = color;
                    }
                }
                columna++;
            }
            fila++;
        }
    }
    
    
    void MoverDerecha(){ x++; }
    void MoverIzquierda(){ x--; }
    void MoverAbajo(){ y++; }
    void MoverArriba(){ y--; }
};