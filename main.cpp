#include <iostream>
#include "interfaces/Interfaces.h"

/*
Caso esteja no windows trocar em Interfaces.h
na função clear() o "clear" por "cls".
*/

int main(){
  Banco B("Bransino", "3895-451", "Bransino Company");
  B.cadastrarPessoaFisica("Diego", "111");
  B.cadastrarPessoaFisica("Pedro", "111");
  Pessoa *p1 = B.devolvePessoa("Diego");
  Pessoa *p2 = B.devolvePessoa("Pedro");
  B.cadastro(1, p1);
  B.cadastro(2, p1);
  B.cadastro(3, p1);
  B.cadastro(2, p2);

  Interfaces roda(&B);
  int visao;

  roda.opVisoes();
  
}