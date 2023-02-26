#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include "Conta.h"

class ContaPoupanca : public Conta{

public:
  ContaPoupanca(Pessoa &p, const int &n_conta): Conta(p, n_conta), data_aniversario(informaDia()){}

  void creditaJuros();
  virtual void extrato() const;
  string informaDia();

private:
  string data_aniversario;
  
};

#endif