#include "ContaPoupanca.h"

string ContaPoupanca::informaDia(){
  struct tm *data;
  time_t curr_time;
	time(&curr_time);
  data = localtime(&curr_time);
  int dia = data->tm_mday, mes = data->tm_mon + 1, ano = data->tm_year + 1900;
  
  string dia_s(std::to_string(dia));
  string mes_s(std::to_string(mes));
  string ano_s(std::to_string(ano));

  return dia_s + "/" + mes_s + "/" + ano_s;
}

void ContaPoupanca::extrato() const{
  cout << right;
  cout.fill('0');
  cout << "_________________" << endl;
  cout << " CONTA POUPANÇA" << endl;
  cout << "Nome Cliente: " << this->p->getNome() << endl;
  cout << "N° Conta: " << setw(3) << this->n_conta << endl;
  cout << "Saldo: R$ " << this->saldo << endl;
  cout << "Data aniversário: " << this->data_aniversario << endl;
  cout << "-----------------" << endl;
}


void ContaPoupanca::creditaJuros(){
  this->saldo = this->saldo * 1.05;
}