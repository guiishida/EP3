#include "Mensagem.h"

using namespace std;

Mensagem::Mensagem(string texto, Perfil* autor)
{
    this->texto = texto;
    this->autor = autor;

}

Mensagem::~Mensagem()
{
    //dtor
}

string Mensagem::getTexto() {
    return this->texto;
}

Perfil* Mensagem::getAutor(){
    return this->autor;
}
