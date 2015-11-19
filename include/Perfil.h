#ifndef PERFIL_H
#define PERFIL_H
#include "MensagemComCurtir.h"
#include "Mensagem.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Mensagem;

class Perfil
{
protected:
    vector<Perfil*>* contatos;
    string nome;
    list<Mensagem*>* mensagensRecebidas;
    list<Mensagem*>* mensagensEnviadas;
    int nContatos;

public:
    Perfil(string nome);
    virtual ~Perfil();

    string getNome();

    // Informa que o perfil foi adicionado pelo perfil "contato"
    virtual void adicionadoPor(Perfil* contato) = 0;

    // Envia uma mensagem para todos os contatos do perfil.
    // O curtir informa se a mensagem pode ser curtida ou n�o.
    virtual void envia(string texto, bool curtir);

    // Recebe uma mensagem.
    virtual void recebe(Mensagem* m);

    // Obt�m a lista ligada com as mensagens recebidas.
    list<Mensagem*>* getMensagensRecebidas();


    // Obt�m a lista ligada com as mensagens enviadas.
    list<Mensagem*>* getMensagensEnviadas();

    // retorna a lista de contatos de um perfil.
    vector<Perfil*>* getContatos();

    // Imprime a lista de contatos alcan��veis.
    void verContatosAlcancaveis();

    // Retorna a lista de contatos alcan��veis.
    vector<Perfil*>* getContatosAlcancaveis();
};

#endif // PERFIL_H
