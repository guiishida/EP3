#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <string>
#include "Pessoa.h"
#include "Perfil.h"


class Departamento : public Perfil
{
protected:
    string site;
    string nome;
    Pessoa* responsavel;

public:
    Departamento(string nome, string site, Pessoa* responsavel);

    // Deve ser usado apenas pela persistência
    Departamento(string nome, string site);

    virtual ~Departamento();

    string getSite();

    // Deve ser usado apenas pela persistência
    void setResponsavel(Pessoa* responsavel);

    Pessoa* getResponsavel();

    // Redefine o método "recebe" para repassa-la ao responsável.
    // A mensagem recebida deve também ser adicionada às mensagens recebidas do
    // departamento.
    virtual void recebe(Mensagem* m);

    // Implementa o método adicionadoPor para adicionar o Perfil como contato do
    // Departamento
    virtual void adicionadoPor(Perfil* contato);
};

#endif // DEPARTAMENTO_H
