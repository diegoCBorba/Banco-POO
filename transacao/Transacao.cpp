#include "Transacao.h"
#include <string>
using std::string;

ostream &operator<<(ostream &out, const Transacao &obj){
    out << "------------------" << std::endl;
    out << "Descrição: " << obj.descricao << std::endl;
    out << "Valor: R$" << obj.valor << std::endl;
    out << "Data: " << obj.data << std::endl;
    out << "------------------" << std::endl;

  return out;
}

string Transacao::informaDia(){
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