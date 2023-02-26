#ifndef BANCO_H
#define BANCO_H

#include "conta/ContaPoupanca.h"
#include "conta/ContaLimite.h"

class Banco: public PessoaJuridica{

public:

Banco(const string &nome, const string &cnpj, const string &razaoSocial): PessoaJuridica(nome, cnpj, razaoSocial){}
~Banco();

bool temPessoaNaLista(Pessoa *p);
bool temPessoaNaLista(const string &nome);
void cadastro(const int &tc, Pessoa *p);
bool cadastrarPessoaFisica(const string &nome, const string &cpf);
bool cadastrarPessoaJuridica(const string &nome, const string &cnpj, const string &razaoSocial);
void remocao(const int &n);
void consulta(const int &n) const;
void atualizacao(const string &nome, const string &nomeNovo);
void mostrar() const;

void listarPessoas() const;
void listarContasCorrentista(const string &nome) const;
void listarContas() const;
void listarNumContas() const;
void listarNomesPessoas() const;
void listarNumerosContas(Conta *C);
void mostrarContas();
Pessoa* devolvePessoa(const string &nome);
Conta* devolveConta(const int &num);

bool existeContaDaPessoa(const int &num, Pessoa *p);
bool existeConta(Conta *c, const int &num);
bool existeConta(const int &num);

void depositar(Conta *c, const double &valor);
void retirar(Conta *c, const double &valor);
void verSaldo(Conta *c);
void transferir(Conta *c1, Conta *c2, const double &valor);
void extratoB(Conta *c);

private:
  string nome;
  list <Pessoa *> pessoas;
  list <Conta *> contas;
}; 

#endif