#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <chrono>
using namespace std;
using namespace ftxui;


string vaca[] = {
    string("         (__)"),  
    string(" ` ------(oo)"),
    string("   ||    (__)"),
    string("   ||w--|| "),
};


int main(int argc, char const *argv[])
{
   Screen pantalla = Screen::Create(
    Dimension::full(),
    Dimension::Fixed(10)
   );

   int x = 0;
   while(true){ 
   cout <<pantalla.ResetPosition(true);

   Pixel& pixel = pantalla.PixelAt(5, 5);
   pixel.character = 'A';
   pixel.background_color = Color::Blue;
   pixel.foreground_color = Color::Red;

   pantalla.Print();
    
    this_thread::sleep_for(chromo::seconds(1));
}

    return 0;
}