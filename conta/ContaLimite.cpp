#include "ContaLimite.h"

//falta tratamento de erro
ContaLimite &ContaLimite::operator>>(const int &valor){
  if(valor <= this->saldo + this->limite){
    this->saldo -= valor;
    Transacao t(-valor, "Retirada");
    addTransacao(t);
  }else{
    cout << "O valor da retirada está acima do seu saldo!" << endl;
  }
  return *this;
}

void ContaLimite::transacao(Conta &obj, const double &valor){
  if(this->n_conta == obj.getN_conta()){
    cout << "Você não pode fazer uma tranferência para a mesma conta" << endl;
  }else if(valor > this->saldo + this->limite){
    cout << "Saldo insuficiente para a tranferência!" << endl;
  }else{
    *this >> valor; //retirada
    obj << valor; //deposito
    Transacao t(-valor, "Transferência");
    addTransacao(t);
  }
}

void ContaLimite::extrato() const{
  cout << right;
  cout.fill('0');
  cout << "_________________" << endl;
  cout << "  CONTA LIMITE" << endl;
  cout << "Nome Cliente: " << this->p->getNome() << endl;
  cout << "N° Conta: " << setw(3) << this->n_conta << endl;
  cout << "Saldo: R$ " << this->saldo << endl;
  cout << "Limite: " << this->limite << endl;
  cout << "-----------------" << endl;
}
