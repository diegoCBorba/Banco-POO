#ifndef CONTA_H
#define CONTA_H

#include <iostream>
using std::cout; using std::endl;
using std::right;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <list>
using std::list;

#include "transacao/Transacao.h"
#include "pessoa/Pessoa.h"
#include "pessoa/PessoaFisica.h"
#include "pessoa/PessoaJuridica.h"

class Conta{

public:

  Conta(Pessoa &p, const int &n_conta);
  ~Conta(){}

  virtual Conta &operator<<(const int &valor); //deposito
  virtual Conta &operator>>(const int &valor); //retirada
  virtual void extrato() const;
  virtual void transacao(Conta &, const double &);

  int getN_conta() const{return this->n_conta;}
  void addTransacao(const Transacao &obj);
  void mostraTrans() const;
  string getNome(){return p->getNome();}
  void mostrarSaldo();
  void mostrarContar();

protected:
  Pessoa *p;
  int n_conta;
  double saldo;
  list <Transacao> transacoes;
};

#endif