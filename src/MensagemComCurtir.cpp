#include "MensagemComCurtir.h"
using namespace std;



MensagemComCurtir::MensagemComCurtir(string texto, Perfil* autor) : Mensagem(texto, autor)
{
    this->curtidas = 0;
}

MensagemComCurtir::~MensagemComCurtir()
{
    //dtor
}

void MensagemComCurtir::curtir() {
     this->curtidas++;
     cout << "Mensagem curtida" << endl;
}

int MensagemComCurtir::getCurtidas() {
    return this->curtidas;
}
