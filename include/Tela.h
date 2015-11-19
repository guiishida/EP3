#ifndef TELA_H
#define TELA_H

#include "Pessoa.h"
#include "Departamento.h"
#include "Mensagem.h"
#include <vector>
#include <list>
#include <iterator>


class Tela
{
private:
    int nCadastrados;
    vector<Perfil*>* cadastrado;
    Perfil *logado;

public:
    Tela();
    ~Tela();
    void TelaInicial();
    void TelaPessoal(bool start);
    void Cadastrar(int comando);
    bool Logar();
    void Encerrar();
    void helperPrintListaEnviadas(list <Mensagem*>* Mensagens);
    void helperPrintListaRecebidas(list <Mensagem*>* Mensagens);
};

#endif // TELA_H
