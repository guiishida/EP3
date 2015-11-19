#include <iostream>
#include <string>
#include "Tela.h"

Tela::Tela() {
    this->nCadastrados = 0;
    cadastrado = new vector <Perfil*> ();
}

void Tela::TelaInicial() {
    int comando = -1;

    while (comando) {
        cout << "PoliSocial" << endl;
        cout << "-----------" << endl;
        cout << "1) Cadastrar pessoa" << endl;
        cout << "2) Cadastrar departamento" << endl;
        cout << "3) Logar como perfil" << endl;
        cout << "0) Terminar" << endl;
        cin >> comando;
        cin.ignore(256, '\n');

        if (comando == 1 || comando == 2) //&& nCadastrados <= MAX_CONTATOS)
            Cadastrar(comando);
        else if (comando == 3)
            TelaPessoal(Logar());
    }
}

void Tela::TelaPessoal(bool start) {
    int opcao = 1, i, numAdicionado, msgCurtida, msgOp;
    string texto;
    Pessoa *ehPessoa = dynamic_cast<Pessoa *>(logado);
    Departamento *ehDepartamento = dynamic_cast<Departamento *>(logado);

    while (start) {
        if (ehPessoa) {
            cout << "--------------------------------------------------------------------------------";
            cout << "Pessoa: " << logado->getNome() << endl;
            cout << ehPessoa->getDataDeNascimento() << " | " << ehPessoa->getPais() << endl << endl;
            if (logado->getContatos()->size() != 0){
                cout << "Contatos: " << endl;
                for(int k = 0; k < logado->getContatos()->size(); k++)
                    cout << "  " << logado->getContatos()->at(k)->getNome() << endl;
            }
            cout << "--------------------------------------------------------------------------------";
            cout << "Escolha uma opcao: " << endl;
            cout << "1) Ver mensagens enviadas" << endl;
            cout << "2) Ver mensagens recebidas" << endl;
            cout << "3) Escrever mensagem" << endl;
            cout << "4) Ver contatos alcancaveis" << endl;
            cout << "5) Adicionar Contato" << endl;
            cout << "6) Remover Contato" << endl;
            cout << "0) Voltar" << endl;
        }
        else {
            cout << "--------------------------------------------------------------------------------";
            cout << "Departamento: " << logado->getNome() << endl;
            cout << "Responsavel: " << ehDepartamento->getResponsavel()->getNome() << endl << endl;
            if (logado->getContatos()->size() != 0){
                cout << "Contatos: " << endl;
                for(int k = 0; k < logado->getContatos()->size(); k++)
                    cout << "  " << logado->getContatos()->at(k)->getNome() << endl;
            }
            cout << "--------------------------------------------------------------------------------";
            cout << "Escolha uma opcao: " << endl;
            cout << "1) Ver mensagens enviadas" << endl;
            cout << "2) Ver mensagens recebidas" << endl;
            cout << "3) Escrever mensagem" << endl;
            cout << "4) Ver contatos alcancaveis" << endl;
            cout << "0) Voltar" << endl;
        }
        cin >> opcao;
        cin.ignore(256, '\n');

        if (opcao == 0) {
            logado = NULL;
            return;
        }
        else if (opcao == 1) {
            cout <<"Mensagens enviadas" <<endl;
            cout <<"------------------" <<endl;

            helperPrintListaEnviadas(logado->getMensagensEnviadas());

        }
        else if (opcao == 2) {
            cout << "Mensagens recebidas" << endl;
            cout << "-------------------" << endl;

            helperPrintListaRecebidas(logado->getMensagensRecebidas());
            if (logado->getMensagensRecebidas()->size()){

                cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
                cin >> msgCurtida;
                cin.ignore(256, '\n');

                if (msgCurtida > 0 && msgCurtida <= logado->getMensagensRecebidas()->size()) {
                    list<Mensagem*>::iterator iter;
                    iter = logado->getMensagensRecebidas()->begin();
                    for(int i = 1; i < msgCurtida; i ++){
                        iter++;
                    }
                    MensagemComCurtir *ehCurtivel = dynamic_cast<MensagemComCurtir *>((*iter));
                    if(ehCurtivel)
                        ehCurtivel->curtir();
                }
            }
        }
        else if (opcao == 3) {
            try {
                msgOp = 0;
                if (ehPessoa) {
                    cout << "A mensagem eh privada (0 - nao, 1 - sim): ";
                    cin >> msgOp;
                }

                if (!msgOp) {
                    cout << "A mensagem pode ser curtida? (0 - nao, 1 - sim): ";
                    cin >> msgOp;
                    cin.ignore(256, '\n');
                    cout << "Digite a mensagem: ";
                    getline(cin, texto);
                    logado->envia(texto, msgOp);
                    cout << "Mensagem enviada a todos os contatos" << endl;
                }
                else {
                    cout << "Escolha o destino: " << endl;
                    for (i = 0; i < nCadastrados; i++)
                        cout << i + 1 << ") " << (*cadastrado)[i]->getNome() << endl;
                    cout << "Digite um numero ou 0 para cancelar: ";
                    cin >> i;
                    cin.ignore(256, '\n');
                    cout << "Digite a mensagem: ";
                    getline(cin, texto);
                    ehPessoa->envia(texto, (*cadastrado)[i-1]);
                }
            } catch (logic_error *e) {
                    cout << "Erro: " << e->what() << endl;
                    delete e;
            }
        }
        else if (opcao == 4) {
            logado->verContatosAlcancaveis();
        }
        else if (opcao == 5) {
            try {
                cout << "Adicionar contato: " << endl;
                for(i = 0; i < nCadastrados; i ++)
                    cout << i + 1 << ") " << (*cadastrado)[i]->getNome() << endl;
                cout << "Digite um numero ou 0 para cancelar: ";
                cin >> numAdicionado;
                cin.ignore(256, '\n');
                if (numAdicionado != 0 && numAdicionado <= nCadastrados)
                    ehPessoa->adiciona((*cadastrado)[numAdicionado-1]);
            } catch (logic_error *e) {
                cout << "Erro: " << e->what() << endl;
                delete e;
            }
        }
        else if (opcao == 6){
            if (logado->getContatos()->size() != 0){
                int numero;
                cout << "Escolha o contato a remover" << endl;
                for(int k = 0; k < logado->getContatos()->size(); k++)
                    cout << k + 1 << ") " << logado->getContatos()->at(k)->getNome() << endl;
                cout << "Digite um numero ou 0 para voltar: ";
                cin >> numero;
                if (numero > 0 && numero <= logado->getContatos()->size()){
                    string contato_removido = logado->getContatos()->at(numero - 1)->getNome();
                    if(ehPessoa->remove(logado->getContatos()->at(numero - 1)))
                        cout << "Contato com " << contato_removido << " removido" << endl;

                }
            }

        }
    }
}


void Tela::Cadastrar(int comando) {
    string nome;
    string dataDeNascimento, pais;
    string site;
    Pessoa *ehPessoa;
    int nResponsavel;

    if (comando == 1) {
        cout << "Informe os dados da pessoa: " << endl;
        cout << "Nome: ";
        getline(cin, nome);

        cout << "Data de nascimento: ";
        getline(cin, dataDeNascimento);

        cout << "Pais: ";
        getline(cin, pais);

        cadastrado->push_back(new Pessoa(nome, dataDeNascimento, pais));
        nCadastrados++;
        cout << "Pessoa cadastrada com sucesso" << endl << endl;
    }
    else {
        cout << "Informe os dados do departamento: " << endl;
        cout << "Nome: ";
        getline(cin, nome);

        cout << "Site: ";
        getline(cin, site);

        cout << "Escolha um responsavel: " << endl;
        for (int i = 0; i < nCadastrados; i++) {
            ehPessoa = dynamic_cast<Pessoa *>(cadastrado->at(i));
            if (ehPessoa)
                cout << i + 1 << ") " << ehPessoa->getNome() << endl;
        }
        cout << "Digite um numero ou 0 para cancelar: ";
        cin >> nResponsavel;
        cin.ignore(256, '\n');
        if (nResponsavel) {
            cadastrado->push_back(new Departamento(nome, site, dynamic_cast<Pessoa *>(cadastrado->at(nResponsavel-1))));
            nCadastrados++;
            cout << "Departamento cadastrado com sucesso" << endl << endl;
        }
    }
}

bool Tela::Logar() {
    int numero;

    if (this->nCadastrados) {
        cout << "Escolha um dos perfis: " <<endl;

        for (int i = 0; i < this->nCadastrados; i++)
            cout << i + 1 << ") " << (*cadastrado)[i]->getNome()<< endl;

        cout << "Digite um numero ou 0 para cancelar: ";
        cin >> numero;
        cin.ignore(256, '\n');

        if (numero && numero <= nCadastrados) {
            this->logado = (*cadastrado)[numero-1];
            return true;
        }
    }
    return false;
}



void Tela::helperPrintListaEnviadas(list <Mensagem*>* Mensagens) {
    if (Mensagens->size() == 0)
        return;
    int i = 1;
    list <Mensagem*>::iterator iter;
    for(iter = Mensagens->begin(); iter != Mensagens->end(); iter++){
        MensagemComCurtir *ehCurtivel = dynamic_cast<MensagemComCurtir *>((*iter));
        cout << i << ") " << (*iter)->getTexto();
        if (ehCurtivel)
            cout << " (" << ehCurtivel->getCurtidas() << " curtidas" << ")" << endl;
        else
            cout << endl;
        i++;
    }
}

void Tela::helperPrintListaRecebidas(list <Mensagem*>* Mensagens) {
    if (Mensagens->size() == 0)
        return;
    int i = 1;
    list <Mensagem*>::iterator iter;
    for(iter = Mensagens->begin(); iter != Mensagens->end(); iter++){
        MensagemComCurtir *ehCurtivel = dynamic_cast<MensagemComCurtir *>((*iter));
        cout << i << ") " << (*iter)->getTexto();
        if (ehCurtivel)
            cout << " (" << ehCurtivel->getCurtidas() << " curtidas" << ") - " << ehCurtivel->getAutor()->getNome() <<endl;
        else
            cout << " - " << (*iter)->getAutor()->getNome() <<endl;
        i++;
    }
}
