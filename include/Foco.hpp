#programa once
#include <EstadoFoco.hpp>

class Foco
{
    private:
    EstadoFoco estado;

    public:
    Foco()  // constructor
    {
        estado = false ;
    }
    ~Foco() {} // destructor
    void Encender(){
        //codigo en paradigma estructurado
        estado = true;
    }
    void Apagar(){
        estado = false;
    }
    EstadoFoco MostrarEstado(){
        return estado;
    }
};