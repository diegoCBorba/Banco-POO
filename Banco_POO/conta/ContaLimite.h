#ifndef CONTALIMITE_H
#define CONTALIMITE_H
#include "Conta.h"

class ContaLimite : public Conta{

public:
  ContaLimite(Pessoa &p, const int &n_conta, const double &limite): Conta(p, n_conta), limite(limite){}

  virtual ContaLimite &operator>>(const int &valor);
  virtual void extrato() const;
  virtual void transacao(Conta &, const double &);

private:
  double limite;
  
};

#endif