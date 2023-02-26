#include "Conta.h"

Conta::Conta(Pessoa &p, const int &n_conta): p(&p), n_conta(n_conta), saldo(0.){}

//deposito
Conta &Conta::operator<<(const int &valor){
  this->saldo += valor;
  Transacao t(valor, "Deposito");
  addTransacao(t);
  return *this;
}

//retirada - falta tratamento de erro
Conta &Conta::operator>>(const int &valor){
  if(valor <= this->saldo){
    this->saldo -= valor;
    Transacao t(-valor, "Retirada");
    addTransacao(t);
  }else{
    cout << "O valor da retirada está acima do seu saldo!" << endl;
  }
  return *this;
}

void Conta::extrato() const{
  cout << right;
  cout.fill('0');
  cout << "_________________" << endl;
  cout << " CONTA CORRENTE" << endl;
  cout << "Nome Cliente: " << this->p->getNome() << endl;
  cout << "N° Conta: " << setw(3) << this->n_conta << endl;
  cout << "Saldo: R$ " << this->saldo << endl;
  cout << "-----------------" << endl;
}

void Conta::addTransacao(const Transacao &obj){
  transacoes.push_back(obj);
}

void Conta::mostraTrans() const{
  cout << "LISTA DE TRANSAÇÕES - " << p->getNome() << endl;
  int tamanho = transacoes.size();
  if(tamanho < 30){
    auto it = transacoes.begin();
    for(; it != transacoes.end(); ++it){
      cout << *it;
      }
  }else{ 
    auto it = transacoes.begin();
    int inicio = tamanho - 30;
    for(int i = 0; i < inicio; i++){
      it++;
    }
    for(;it != transacoes.end(); ++it){
      cout << *it << endl;
      }
  }
}

void Conta::transacao(Conta &obj, const double &valor){
  if(this->n_conta == obj.n_conta){
    cout << "Você não pode fazer uma tranferência para a mesma conta" << endl;
  }else if(this->saldo < valor){
    cout << "Saldo insuficiente para a tranferência!" << endl;
  }else{
    *this >> valor; //retirada
    obj << valor; //deposito
    Transacao t(-valor, "Transferência");
    addTransacao(t);
  }
}

void Conta::mostrarSaldo(){
  cout << "_________________" << endl << endl;
  cout << "Saldo: R$ " << this->saldo << endl << endl;
  cout << "-----------------" << endl;
}
