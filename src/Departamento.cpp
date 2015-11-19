#include "Departamento.h"

Departamento::Departamento(string nome, string site, Pessoa* responsavel) : Perfil(nome) {
    this->site = site;
    this->responsavel = responsavel;
}

Departamento::~Departamento() {
    delete contatos;
    delete mensagensEnviadas;
    delete mensagensRecebidas;
}

string Departamento::getSite() {
    return this->site;
}

Pessoa* Departamento::getResponsavel() {
    return this->responsavel;
}

void Departamento::recebe(Mensagem* m) {
    this->mensagensRecebidas->push_back(m);
    this->responsavel->getMensagensRecebidas()->push_back(m);
}

void Departamento::adicionadoPor(Perfil* contato) {
    this->contatos->push_back(contato);
    nContatos++;
    string txt = this->getNome() + " adicionou voce como contato";
    Mensagem *m = new Mensagem(txt, this);
    contato->getMensagensRecebidas()->push_back(m);
}
