#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <string>
#include <iostream>

class Perfil;

class Mensagem
{
    public:
        Mensagem(std::string texto, Perfil* autor);
        virtual ~Mensagem();
        std::string getTexto();
        Perfil* getAutor();
    protected:
        std::string texto;
        Perfil* autor;

};

#endif // MENSAGEM_H
