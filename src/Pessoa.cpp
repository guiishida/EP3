#include <iostream>
#include "Pessoa.h"
#include "Mensagem.h"

//o metodo envia aparentemente correto tb

Pessoa::Pessoa(string nome, string dataDeNascimento, string pais) : Perfil(nome) {
    this->dataDeNascimento = dataDeNascimento;
    this->pais = pais;
}

Pessoa::~Pessoa() {
    delete contatos;
    delete mensagensEnviadas;
    delete mensagensRecebidas;
}

string Pessoa::getDataDeNascimento() {
    return this->dataDeNascimento;
}

string Pessoa::getPais() {
    return this->pais;
}

void Pessoa::adiciona(Perfil *contato) {
    if (this == contato)
        throw new logic_error("Nao e possivel adicionar-se como contato");

    for (int i = 0; i < nContatos; i++)
        if (contatos->at(i) == contato)
            throw new logic_error(contato->getNome() + " ja e um contato");

    contatos->push_back(contato);

    contato->adicionadoPor(this);

    cout << this->getNome() << " conectado a " << contatos->at(this->nContatos++)->getNome() << endl;

}

void Pessoa::envia(string texto, Perfil *contato) {
    Mensagem *m = new Mensagem(texto, this);

    for (int i = 0; i < nContatos; i++)
        if (contatos->at(i) == contato) {
            this->mensagensEnviadas->push_back(m);
            contato->recebe(m);
            cout << "Mensagem enviada a " << contato->getNome() << endl;
            return;
        }
    throw new logic_error(contato->getNome() + " nao e um contato");
}

void Pessoa::adicionadoPor(Perfil *contato) {
    Mensagem *m = new Mensagem(contato->getNome() + " adicionou voce como contato", contato);
    this->mensagensRecebidas->push_back(m);
}

bool Pessoa::remove(Perfil *contato){

    vector<Perfil*>::iterator iter;
    iter = find(contatos->begin(), contatos->end() + 1, contato);
    if (iter != contatos->end() + 1){
        int posicao = distance(contatos->begin(),iter);
        cout << posicao << endl;
        nContatos--;
        contatos->erase(contatos->begin() + posicao);
        return true;
    }
    return false;
}
