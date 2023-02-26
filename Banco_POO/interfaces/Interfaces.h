#ifndef INTERFACES_H
#define INTERFACES_H

#include "banco/Banco.h"

#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::right;

class Interfaces{

public:
  Interfaces(Banco *b): b(b){}

  void sairBanco();
  void opVisoes();
  void switchVisoes();
  void opEhPessoa();
  void cadastroPessoa();
  void cadastroPessoaFisica();
  void cadastroPessoaJuridica();
  void opTemConta();

  void opCorrentista();
  void escolhePessoa();
  void cadastroConta();
  void escolhaConta();

  void opGerente();
  void consultarContas();
  void atualizarConta();
  void fecharConta();

  void transferirEntreContas(const double &valor);

private:
  Banco *b;
  Pessoa *pEscolhida;
  Conta *cEscolhida;

};

#endif