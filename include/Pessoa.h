#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <stdexcept>
#include "Mensagem.h"
#include "Perfil.h"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Pessoa : public Perfil
{
protected:
    string dataDeNascimento;
    string pais;

public:
    Pessoa(string nome, string dataDeNascimento, string pais);
    virtual ~Pessoa();
    string getDataDeNascimento();
    string getPais();
    void adiciona(Perfil *contato);

    // Envia uma mensagem privada para um contato
    void envia(string texto, Perfil* contato);


     // Implementa o método adicionadoPor para adicionar uma mensagem à pessoa que
     // ela foi adicionada pelo contato
    virtual void adicionadoPor(Perfil *contato);

    // Remove o contato da lista de contatos da Pessoa.
    // Retorna true se foi possível remover ou false caso contrário.
    bool remove(Perfil *contato);

};

#endif // PESSOA_H
