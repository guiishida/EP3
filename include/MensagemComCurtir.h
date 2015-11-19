#ifndef MENSAGEMCOMCURTIR_H
#define MENSAGEMCOMCURTIR_H
#include <string>
#include <iostream>
#include "Mensagem.h"

class Perfil;


class MensagemComCurtir : public Mensagem
{
    public:
        MensagemComCurtir(std::string texto, Perfil* autor);
        virtual ~MensagemComCurtir();
        void curtir();
        int getCurtidas();
    protected:
        int curtidas;


};

#endif // MENSAGEMCOMCURTIR_H
