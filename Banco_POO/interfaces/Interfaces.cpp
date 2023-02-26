#include "Interfaces.h"

void Interfaces::sairBanco(){
  exit(0);
}

void Interfaces::opVisoes(){
  cout << "    ╭─────────━─────────╮" << endl << endl;
  cout << "Escolha qual visão você deseja" << endl;
  cout << "          •°• ✾ •°•" << endl;
  cout << "    ╰─────────━─────────╯" << endl << endl;
  cout << "Opções: " << endl;
  cout << "1: Gerente" << endl;
  cout << "2: Correntista" << endl;
  cout << "-1: Sair do banco" << endl;
  cout << "━━━━━━━━━━━━━━━━━━┛" << endl;
  switchVisoes();
}

//FALTA CASE 1 - GERENTE
void Interfaces::switchVisoes(){
  int visao;
  cout << "Informe sua escolha: ";
  cin >> visao;
  while(visao != 1 && visao != 2 && visao != -1){
    cout << "Digite uma opção válida" << endl;
    cout << "Informe sua escolha: ";
    cin >> visao;
  }
  switch(visao){
    case 1:
      opGerente();
      break;
    case 2:
      opEhPessoa();
      break;
    case 3:
      sairBanco();
      break;
  }
}

//FALTA O CASE 1
void Interfaces::opEhPessoa(){
  cout << endl;
  cout << "┌─────────────────────────────────" << endl;
  cout << "  Você já é um usuário do Banco?" << endl;
  cout <<  "─────────────────────────────────┘" << endl;
  cout << "Opções: " << endl;
  cout << "1: Sim" << endl;
  cout << "2: Não" << endl;
  cout << "━━━━━━━━━━━━━━━━━━┛" << endl;
  int escolha;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  while(escolha != 1 && escolha != 2){
  cout << "Digite uma opção válida" << endl;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  }
  switch(escolha){
    case 1:
      escolhePessoa();
      break;
    case 2:
      cadastroPessoa();
      break;
  }
}

void Interfaces::cadastroPessoa(){
  cout << "      ╭─────────━─────────╮" << endl << endl;
  cout << "Escolha qual Pessoa você deseja criar" << endl;
  cout << "            •°• ✾ •°•" << endl;
  cout << "      ╰─────────━─────────╯" << endl << endl;
  cout << "Opções: " << endl;
  cout << "1: Física" << endl;
  cout << "2: Jurídica" << endl;
  cout << "━━━━━━━━━━━━━━━━━━┛" << endl;
  
  int escolha;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  while(escolha != 1 && escolha != 2){
  cout << "Digite uma opção válida" << endl;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  }
  switch(escolha){
    case 1:
      cadastroPessoaFisica();
      break;
    case 2:
      cadastroPessoaJuridica();
      break;
  }
}


void Interfaces::cadastroPessoaFisica(){
  string nome, cpf;
  cout << "Informe seu Nome: ";
  cin >> nome;
  cout << "Informe seu CPF: ";
  cin >> cpf;
  while(1){
    if(b->cadastrarPessoaFisica(nome, cpf)){
      cout << endl <<"Sucesso no cadastro!" << endl << endl;
      this -> pEscolhida = b->devolvePessoa(nome);
      cadastroConta();
      break;
    }else{
      cout << "Nome já cadastrado!" << endl;
      cout << "Informe outro nome: ";
      cin >> nome;    
    }
  }
}


void Interfaces::cadastroPessoaJuridica(){
  string nome, cnpj, razaoSocial;
  cout << "Informe seu Nome: ";
  cin >> nome;
  cout << "Informe seu CNPJ: ";
  cin >> cnpj;
  cout << "Informe sua Razão Social: ";
  cin >> razaoSocial;
  while(1){
    if(b->cadastrarPessoaJuridica(nome, cnpj, razaoSocial)){
      cout << endl <<"Sucesso no cadastro!" << endl << endl;
      this -> pEscolhida = b->devolvePessoa(nome);
      cadastroConta();
      break;
    }else{
      cout << "Nome já cadastrado! ";
      cout << "Informe outro nome: ";
      cin >> nome;  
    }
  }
}

void Interfaces::escolhePessoa(){
  cout << "      ╭─────────━─────────╮" << endl << endl;
  cout << "    Digite seu nome no banco" << endl;
  cout << "            •°• ✾ •°•" << endl;
  cout << "      ╰─────────━─────────╯" << endl << endl;
  string nome;
  cout << "----: ";
  cin >> nome;
  while(!b->temPessoaNaLista(nome)){
    cout << "Digite um nome válido!" << endl;
    cout << "----: ";
    cin >> nome;
  }
  this -> pEscolhida = b->devolvePessoa(nome);
  opTemConta();
}

void Interfaces::opTemConta(){
  cout << endl;
  cout << "┌─────────────────────────" << endl;
  cout << "  Você já tem uma conta?" << endl;
  cout <<  "─────────────────────────┘" << endl;
  cout << "Opções: " << endl;
  cout << "1: Sim" << endl;
  cout << "2: Não || Quer criar outrar" << endl;
  cout << "━━━━━━━━━━━━━━━━━━┛" << endl;
  int escolha;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  while(escolha != 1 && escolha != 2){
  cout << "Digite uma opção válida" << endl;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  }
  switch(escolha){
    case 1:
      escolhaConta();
      break;
    case 2:
      cadastroConta();
      break;
  }
}

void Interfaces::cadastroConta(){
  cout << endl;
  cout << "┌────────────────────────────────────" << endl;
  cout << "  Qual tipo de conta você quer criar" << endl;
  cout <<  "────────────────────────────────────┘" << endl;
  cout << "Opções: " << endl;
  cout << "1: Corrente" << endl;
  cout << "2: Poupança" << endl;
  cout << "3: Com limite" << endl;
  cout << "━━━━━━━━━━━━━━━━━━┛" << endl;
  int escolha;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  while(escolha != 1 && escolha != 2 && escolha != 3){
  cout << "Digite uma opção válida" << endl;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  }
  switch(escolha){
    case 1:
      b->cadastro(escolha, pEscolhida);
      cout << endl << "─────SUCESSO AO CADASTRAR!─────" << endl << endl;
      escolhaConta();
      break;
    case 2:
      b->cadastro(escolha, pEscolhida);
      cout << endl << "─────SUCESSO AO CADASTRAR!─────" << endl << endl;
      escolhaConta();
      break;
    case 3:
      b->cadastro(escolha, pEscolhida);
      cout << endl << "─────SUCESSO AO CADASTRAR!─────" << endl << endl;
      escolhaConta();
      break;
  }
}

//LIGAR PARA INTERFACE CORRENTISTA
void Interfaces::escolhaConta(){
  b->listarContasCorrentista(pEscolhida->getNome());
  cout << "┌────────────────────────────────────────" << endl;
  cout << "  Insira o número de uma das suas Contas" << endl;
  cout <<  "────────────────────────────────────────┘" << endl;
  int escolha;
  cout << "Informe seu número: ";
  cin >> escolha;
  while(!b->existeContaDaPessoa(escolha, pEscolhida)){
    cout << "Informe um número de conta valido!" << endl;
    cout << "Informe seu número: ";
    cin >> escolha;
  }
  this -> cEscolhida = b->devolveConta(escolha);
  opCorrentista();
}

void Interfaces::opCorrentista(){
  cout << "  ╭─────────━─────────╮" << endl << endl;
  cout << "Escolha o que você deseja" << endl;
  cout << "       •°• ✾ •°•" << endl;
  cout << "  ╰─────────━─────────╯" << endl << endl;
  cout << "Opções: " << endl;
  cout << "1: Depositar" << endl;
  cout << "2: Retirar" << endl;
  cout << "3: Transferir" << endl;
  cout << "4: Ver Saldo" << endl;
  cout << "5: Extrato" << endl;
  cout << "-1: Sair do banco" << endl;
  cout << "━━━━━━━━━━━━━━━━━━┛" << endl;  
  int escolha;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  while(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4 && escolha != 5 && escolha != -1){
  cout << "Digite uma opção válida" << endl;
  cout << "Informe sua escolha: ";
  cin >> escolha;
  }
  switch(escolha){
    int valor;
    case 1:
      cout << "Informe um valor: ";
      cin >> valor;
      b->depositar(cEscolhida, valor);
      break;
    
    case 2:
      cout << "Informe um valor: ";
      cin >> valor;
      b->retirar(cEscolhida, valor);
      break;
    
    case 3:
      cout << "Informe um valor: ";
      cin >> valor;
      transferirEntreContas(valor);
      break;
    
    case 4:
      b->verSaldo(cEscolhida);
      break;
    
    case 5:
      b->extratoB(cEscolhida);
      break;

    case -1:
      sairBanco();
      break;
  }
  opCorrentista();
}

void Interfaces::transferirEntreContas(const double &valor){
  cout << "┌────────────────────────────────────────" << endl;
  cout << "  Insira o número de uma das suas Contas" << endl;
  cout <<  "────────────────────────────────────────┘" << endl;
  int escolha;
  cout << "Informe seu número: ";
  cin >> escolha;
  while(b->existeConta(cEscolhida, escolha)){
    cout << "Informe um número de conta valido!" << endl;
    cout << "Informe seu número: ";
    cin >> escolha;
    }
  Conta *c = b->devolveConta(escolha);
  b->transferir(cEscolhida, c, valor);
}

void Interfaces::opGerente(){
  cout << "  ╭─────────━─────────╮" << endl << endl;
  cout << "Escolha o que você deseja" << endl;
  cout << "       •°• ✾ •°•" << endl;
  cout << "  ╰─────────━─────────╯" << endl << endl;
  cout << "Opções: " << endl;
  cout << "1: Consultar Conta" << endl;
  cout << "2: Atualizar Conta" << endl;
  cout << "3: Fechar Conta" << endl;
  cout << "4: Mostrar Contas" << endl;
  cout << "-1: Sair do banco" << endl;
  cout << "━━━━━━━━━━━━━━━━━━┛" << endl;
  int escolha;
  cout << "informe sua escolha: ";
  cin >> escolha;
  while(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4 && escolha != -1){
  cout << "Digite uma opção válida" << endl;
  cout << "informe sua escolha: ";
  cin >> escolha;
  }
  switch(escolha){
    case 1:
      consultarContas();
      break;

    case 2:
      atualizarConta();
      break;

    case 3:
      fecharConta();
      break;

    case 4:
      b->mostrarContas();
      opGerente();
      break;
    
    case -1:
      sairBanco();
      break;
  }
}

void Interfaces::consultarContas(){
  b->listarNumContas();
  cout << "┌──────────────────────────────────────────────" << endl;
  cout << "  Escolha o Num da conta que você quer acessar" << endl;
  cout <<  "──────────────────────────────────────────────┘" << endl;
  int escolha;
  cout << "Informe seu número: ";
  cin >> escolha;
  while(!b->existeConta(escolha)){
    cout << "Informe um número de conta valido!" << endl;
    cout << "Informe seu número: ";
    cin >> escolha;
  }
  b->consulta(escolha);
  opGerente();
}

void Interfaces::atualizarConta(){
  b->listarNomesPessoas();
  cout << "┌──────────────────────────────────────────────" << endl;
  cout << "   Escolha a pessoa que você quer atualizar" << endl;
  cout <<  "──────────────────────────────────────────────┘" << endl;
  string nome;
  cout << "----: ";
  cin >> nome;
  while(!b->temPessoaNaLista(nome)){
    cout << "Digite um nome válido!" << endl;
    cout << "----: ";
    cin >> nome;
  }
  
  string nomeNovo;
  cout << "Escolha o novo nome: ";
  cin >> nomeNovo;
  while(b->temPessoaNaLista(nomeNovo)){
  cout << "Digite um nome válido!" << endl;
  cout << "----: ";
  cin >> nomeNovo;
  }
  
  b->atualizacao(nome, nomeNovo);
  opGerente();
}

void Interfaces::fecharConta(){
  b->listarNumContas();
  cout << "┌──────────────────────────────────────────────" << endl;
  cout << "  Escolha o Num da conta que você quer remover" << endl;
  cout <<  "──────────────────────────────────────────────┘" << endl;
  int escolha;
  cout << "Informe seu número: ";
  cin >> escolha;
  while(!b->existeConta(escolha)){
    cout << "Informe um número de conta valido!" << endl;
    cout << "Informe seu número: ";
    cin >> escolha;
  }
  b->remocao(escolha);
  opGerente();
}