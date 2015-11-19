#include "Perfil.h"
#include <iostream>

//métodos recebe e envia aparentemente corrigidos

Perfil::Perfil(string nome)
{
    this->nome = nome;
    nContatos = 0;
    mensagensEnviadas = new list<Mensagem*>;
    mensagensRecebidas = new list<Mensagem*>;
    contatos= new vector <Perfil*>;
}

Perfil::~Perfil()
{
    delete contatos;
    delete mensagensEnviadas;
    delete mensagensRecebidas;
}

string Perfil::getNome(){
    return this->nome;
}

void Perfil::envia(string texto, bool curtir){
    if (!contatos->size())
        throw new logic_error("Voce nao possui contatos");
    else if (curtir == false) {
        Mensagem *m = new Mensagem(texto, this);
        this->mensagensEnviadas->push_back(m);
        for(int k = 0; k < nContatos; k++)
            this->contatos->at(k)->recebe(m);
    }
    else {
        Mensagem *m = new MensagemComCurtir(texto, this);
        this->mensagensEnviadas->push_back(m);
        for(int k = 0; k < nContatos; k++)
            this->contatos->at(k)->recebe(m);
    }
}

void Perfil::recebe(Mensagem* m) {
    this->mensagensRecebidas->push_back(m);
}

list<Mensagem*>* Perfil::getMensagensRecebidas() {
    return this->mensagensRecebidas;
}

list<Mensagem*>* Perfil::getMensagensEnviadas() {
    return this->mensagensEnviadas;
}

vector<Perfil*>* Perfil::getContatos() {
    /*if (this->nContatos != 0) {
        cout << "Contatos: " << endl;
        for(int k = 0; k < nContatos; k++)
            cout << "  " << this->contatos->at(k)->getNome() << endl;
    }*/
    return this->contatos;
}

void Perfil::verContatosAlcancaveis() {
    vector<Perfil*> *alcancavel = new vector<Perfil *>();
    vector<Perfil*>::iterator iter;

    cout << "Contatos alcancaveis " << endl;
    cout << "--------------------" << endl;

    for (iter = contatos->begin(); iter != contatos->end(); iter++){
        alcancavel->push_back(*iter);
        for (int i = 0; i < (*iter)->contatos->size(); i++){
            if (find(alcancavel->begin(), alcancavel->end(), (*iter)->contatos->at(i)) == alcancavel->end()){
                alcancavel->push_back((*iter)->contatos->at(i));
            }
        }
    }

    for(iter = alcancavel->begin(); iter != alcancavel->end(); iter++){
        cout << (*iter)->getNome() << endl;
    }
}

vector<Perfil*>* Perfil::getContatosAlcancaveis() {
    vector<Perfil*> *alcancavel = new vector<Perfil *>();
    vector<Perfil*>::iterator iter;

    for (iter = contatos->begin(); iter != contatos->end(); iter++){
        alcancavel->push_back(*iter);
        for (int i = 0; i < (*iter)->contatos->size(); i++){
            if (find(alcancavel->begin(), alcancavel->end(), (*iter)->contatos->at(i)) == alcancavel->end()){
                alcancavel->push_back((*iter)->contatos->at(i));
            }
        }
    }
    return alcancavel;
}
