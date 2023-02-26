#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using std::ostream; using std::endl; using std::cout;

#include <string>
using std::string;

class Pessoa{

public:
  
  Pessoa(const string &nome = "indefinido"): nome(nome){}
  virtual ~Pessoa(){}

  void setNome(const string &nome){this -> nome = nome;}
  string getNome(){return this->nome;}

  virtual void imprimir() const = 0;
    
protected:
  string nome;

};

#endif