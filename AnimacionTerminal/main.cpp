#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <string>
#include <list>
#include "Dibujo.hpp"

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{

    Screen pantalla = Screen::Create(
        Dimension::Fixed(100), 
        Dimension::Fixed(24) 
    );

    const list<string> scrat_ascii = {
R"(  _,                          _                )",
R"(.  `.                  ___.>"''-..-.          )",
R"(`-.   ;           .--"""        .-._@;         )",
R"(__;  !_.--..._ .'      /     .[_@'`'.         )", 
R"(  ;            /       : .'  ; :_.._  `.)",
R"(  :           ;        ;[   _T-"  `.'-. `-.    )",
R"(   \        .-:      ; `.`-=_,88p.   _.}.-")",
R"(    `-.__.-'   \    /L._ Y",P$T888;  ""        )",
R"(             .-'_.-'  / ;$$$$$$]8P;            )",
R"(             \ /     / / "Y$$P" ^"             )",
R"(     fsc      ;\_    `.\_._                    )",
R"(              ]__\     \___;)"
    };
    
    const list<string> sid_ascii = {
R"(                       .-.)",
R"(    _.--"""".o/         .-.-._)",
R"(  __'   ."""" {       _J ,__ `.)",
R"(  ; o\.-.`._.'J;      ; /  `- /  )",
R"(  `--i`"`" .';       `._ __.'   |)",
R"(    \  `"""  \        `;      :)",
R"(      `.-.    ;      ____/    /)",
R"(        `-.`     `-.-'    `"-..' )",
R"(           `;__.-'          `.)",
R"(.-{_ `--._        /.-"          "-.)",
R"( /   ""T   ""---...'   _.-""  """-.      `.)",
R"(;      /              __.-\"".    `.        `,            _..)",
R"( \    /          __.-""      '.    \          `.,__     .'L' })",
R"(  `---"`-.__  __.\"\"\"    .-.      j      `.          :  `.  .' ,' /)",
R"(          \"\"\"\"      /  \      :        `.      |    F' \  ;)",
R"(                  ;    `-._,L_,-""-.   `-,    ;    `  ; /)",
R"(                   `.      7        `-._  `.__/_      \/)",
R"(                    \    _;            \ _.'  `-.    /)",
R"(                     `---" `.___,,      ;""        \  .')",
R"(                               _/      ;           \""")",
R"(                              .-"    _,-')",
R"(                             {      \"\"})",
R"(                              ;-.____.'`. )",
R"(            fsc             `.  \ '.  :)",
R"(                              \  : : /)",
R"(                               `':/ `)"
    };
    
    Dibujo scrat(scrat_ascii, 10, 5); 
    Dibujo sid(sid_ascii, 0, 10);   

    int frame = 0; 
    
    while(true){ 

        pantalla.Clear();

        scrat.setX((scrat.getX() + 1) % (pantalla.dimx() - scrat.getAncho())); 
        
        if (sid.getX() < scrat.getX()) {
            sid.setX(sid.getX() + 1); 
        } 
        else if (sid.getX() > scrat.getX()) {
            sid.setX(sid.getX() - 1); 
        }
        
        if (sid.getY() < scrat.getY()) {
            sid.setY(sid.getY() + 1); 
        } else if (sid.getY() > scrat.getY()) {
            sid.setY(sid.getY() - 1); 
        }


        scrat.Imprimir(pantalla, Color::Green); 
        sid.Imprimir(pantalla, Color::Red);   

        cout << pantalla.ResetPosition(true);
        pantalla.Print();
        cout << flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
        
        frame++; 
    } 

    return 0; 
}