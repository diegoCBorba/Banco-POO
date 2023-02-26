#ifndef TRANSACAO_H
#define TRASANCAO_H

#include <string>
using std::string;
#include <iostream>
using std::ostream;

class Transacao{

friend ostream &operator<<(ostream &, const Transacao &);

public:
  Transacao(const double &valor = 0, const string &descricao = "indefinida"): valor(valor), data(informaDia()), descricao(descricao){}

  double getValor() const{return this->valor;}
  void setValor(const double &valor){this->valor = valor;}
  string informaDia();

private:
  string data, descricao;
  double valor;

};

#endif