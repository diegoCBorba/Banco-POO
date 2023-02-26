#include "PessoaJuridica.h"

void PessoaJuridica::imprimir() const{
  cout << "______________________" << endl;
  cout << "   PESSOA JURÍDICA "<< endl;
  cout << "Nome: " << this->nome << endl;
  cout << "----------------------" << endl;
}