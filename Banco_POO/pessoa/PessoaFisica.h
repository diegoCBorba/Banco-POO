#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include "Pessoa.h"

//CPF, nome, endereço, data de nascimento, email, estado civil

class PessoaFisica : public Pessoa {

public:
  PessoaFisica(const string &nome, const string &cpf): Pessoa(nome), cpf(cpf){}

  void setCPF(const string &cpf){this->cpf = cpf;}
  string getCPF(){return cpf;}

  virtual void imprimir() const;

protected:
  string cpf;

};

#endif