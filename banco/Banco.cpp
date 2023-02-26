#include "Banco.h"

Banco::~Banco(){
  for(auto &i: contas){
    delete i;
  }
  for(auto &i: pessoas){
    delete i;
  }
}

bool Banco::temPessoaNaLista(Pessoa *p){
  //Verifica pelo nome se a pessoa já está na lista ou não
  for(auto &i: pessoas){
    if(p->getNome() == i->getNome()){
      return true;
    }
  }return false;
}

bool Banco::temPessoaNaLista(const string &nome){
  for(auto &i: pessoas){
    if(nome == i->getNome()){
      return true;
    }
  }return false;
}

Pessoa* Banco::devolvePessoa(const string &nome){
  Pessoa *p;
  for(auto &i: pessoas){
    if(nome == i->getNome()){
        p = i;
      }
    }
  return p;
}

Conta* Banco::devolveConta(const int &num){
  Conta *p;
  for(auto &i: contas){
    if(num == i->getN_conta()){
        p = i;
      }
    }
  return p;
}

bool Banco::existeContaDaPessoa(const int &num, Pessoa *p){
  for(auto &i: contas){
    if(num == i->getN_conta() && i->getNome() == p->getNome()){
      return true;
    }
  }return false;
}

bool Banco::existeConta(Conta *c, const int &num){
  for(auto &i: contas){
    if(num == i->getN_conta() && num == c->getN_conta()){
      return true;
    }
  }return false;
}

bool Banco::existeConta(const int &num){
  for(auto &i: contas){
    if(num == i->getN_conta()){
      return true;
    }
  }return false;
}

void Banco::cadastro(const int &tc, Pessoa *p){
  if(!temPessoaNaLista(p)){
    pessoas.push_back(p);
  }
  if(tc == 1){
    contas.push_back(new Conta(*p, contas.size()));
  }else if(tc == 2){
    contas.push_back(new ContaPoupanca(*p, contas.size()));
  }else{
    contas.push_back(new ContaLimite(*p, contas.size(), 1000));
  }
}

bool Banco::cadastrarPessoaFisica(const string &nome, const string &cpf){
  PessoaFisica *p = new PessoaFisica(nome, cpf);
  if(!temPessoaNaLista(p)){
      pessoas.push_back(p);
      return true;
    }return false;
}

bool Banco::cadastrarPessoaJuridica(const string &nome, const string &cnpj, const string &razaoSocial){
  PessoaJuridica *p = new PessoaJuridica(nome, cnpj, razaoSocial);
  if(!temPessoaNaLista(p)){
      pessoas.push_back(p);
    return true;
    }return false;
}

void Banco::remocao(const int &n){
  int num = 0;
  bool existe = false;
  for(auto &i: contas){
    if(i->getN_conta() == n){
      existe = true;
      break;
    }
    num++;
  }

  if(existe){
    auto it = contas.begin();
    for(int i = 0; i < num; i++)
      it++;
    contas.erase(it);
  }else{
    cout << "Não existe essa conta na lista!" << endl;
  }
}

void Banco::consulta(const int &n) const{
  bool existe = false;
  for(auto &i: contas){
    if(i->getN_conta() == n){
      i->extrato();
      i->mostraTrans();
      existe = true;
      break;
    }
  }
  
  if(!existe)
    cout << "Não existe essa conta na lista!" << endl;
}

void Banco::atualizacao(const string &nome, const string &nomeNovo){
  for(auto &i: pessoas){
    if(i->getNome() == nome){
      i->setNome(nomeNovo);
    }
  }
}

void Banco::listarContasCorrentista(const string &nome) const{
  for(auto &i: contas){
    if(i->getNome() == nome){
      i->extrato();
      i->mostraTrans();
    }
  }
}

void Banco::listarPessoas() const{
  for(auto &i: pessoas){
    i->imprimir();
  }
}

void Banco::listarContas() const{
  for(auto &i: contas)
    i->extrato();
}

void Banco::listarNumContas() const{
  cout << right;
  cout.fill('0');
  cout << "---------------------" << endl;
  cout << "   n° das Contas: " << endl << endl;
  for(auto &i: contas){
    cout << setw(3) << i->getN_conta() << endl;
  }cout << "---------------------" << endl;
}

void Banco::listarNomesPessoas() const{
  cout << "---------------------" << endl;
  cout << "  Nome das Pessoas: " << endl << endl;
  for(auto &i: pessoas){
    cout << i->getNome() << endl;
  }cout << "---------------------" << endl;
}

void Banco::mostrarContas(){
  for(auto &i: contas){
    i->extrato();
  }
}

void Banco::depositar(Conta *c, const double &valor){
  *c << valor;
}

void Banco::retirar(Conta *c, const double &valor){
  *c >> valor;
}

void Banco::verSaldo(Conta *c){
  c->mostrarSaldo();
}

void Banco::transferir(Conta *c1, Conta *c2, const double &valor){
  c1->transacao(*c2, valor);
}

void Banco::extratoB(Conta *c){
  c->extrato();
  c->mostraTrans();
}