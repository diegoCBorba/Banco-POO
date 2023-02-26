#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Pessoa.h"

class PessoaJuridica : public Pessoa {

public:

  PessoaJuridica(const string &nome, const string &cnpj, const string &razaoSocial): Pessoa(nome), cnpj(cnpj), razaoSocial(razaoSocial){}

  void setCNPJ(const string &cnpj){this->cnpj = cnpj;}
  string getCNPJ(){return cnpj;}
  void setRazaoSocial(const string &razao){this->razaoSocial = razao;}
  string getRazaoSocial(){return razaoSocial;}

  virtual void imprimir() const;

private:
  string cnpj;
  string razaoSocial;

};

#endif