/******************************************************************************

INF101
Trabalho – Implementação de um Sistema de
Registro e Gestão de Contas Bancárias (ETAPA 1)

Aluno: João Pedro Ferraz Barreto 
Matrícula: 29059

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numeroConta, tipoConta;
    string nomeCliente, cpf;
    double saldo;
    bool contaAtiva;
    int numero;
    bool contaCadastrada;

    do {

        cout << "********************************" << endl;
        cout << "********** ADS BANK ************" << endl;
        cout << "********************************" << endl;

        cout << "********************************" << endl;
        cout << "**********   MENU   ************" << endl;
        cout << "********************************" << endl;

        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "********************************" << endl;

        cout << "Digite o numero da opcao desejada: ";
        cin >> numero;

        switch (numero) {

            case 1: {
                cout << "\n--- CADASTRO DE CONTA ---\n";

                do {
                    cout << "Numero da conta: ";
                    cin >> numeroConta;

                    if (numeroConta <= 0) {
                        cout << "Erro: o numero da conta deve ser maior que zero.\n";
                    }

                } while (numeroConta <= 0);

                cin.ignore();

                cout << "Nome do titular: ";
                getline(cin, nomeCliente);

                cout << "CPF do titular: ";
                getline(cin, cpf);

                do {
                    cout << "Tipo da conta (1 - Corrente / 2 - Poupanca): ";
                    cin >> tipoConta;

                    if (tipoConta != 1 && tipoConta != 2) {
                        cout << "Erro: escolha 1 para Corrente ou 2 para Poupanca.\n";
                    }

                } while (tipoConta != 1 && tipoConta != 2);

                do {
                    cout << "Saldo inicial: R$ ";
                    cin >> saldo;

                    if (saldo < 0) {
                        cout << "Erro: o saldo nao pode ser negativo.\n";
                    }

                } while (saldo < 0);

                contaAtiva = true;
                contaCadastrada = true;

                cout << "\nConta cadastrada com sucesso!\n";
                break;
            }

            case 2: {
                cout << "\n--- CONSULTA DA CONTA ---\n";

                if (!contaCadastrada) {
                    cout << "Nenhuma conta foi cadastrada.\n";
                } else {
                    cout << "Numero da conta: " << numeroConta << endl;
                    cout << "Nome do titular: " << nomeCliente << endl;
                    cout << "CPF: " << cpf << endl;

                    if (tipoConta == 1) {
                        cout << "Tipo da conta: Corrente\n";
                    } else {
                        cout << "Tipo da conta: Poupanca\n";
                    }

                    cout << "Saldo: R$ " << saldo << endl;

                    if (contaAtiva) {
                        cout << "Situacao: Ativa\n";
                    } else {
                        cout << "Situacao: Inativa\n";
                    }
                }

                break;
            }

            case 3: {
                cout << "\n--- VERIFICAR SALDO ---\n";

                if (!contaCadastrada) {
                    cout << "Nenhuma conta foi cadastrada.\n";
                } else if (!contaAtiva) {
                    cout << "A conta esta inativa. Operacao nao permitida.\n";
                } else {
                    cout << "Saldo atual: R$ " << saldo << endl;
                }

                break;
            }

            case 4: {
                cout << "\n--- ALTERAR TIPO DA CONTA ---\n";

                if (!contaCadastrada) {
                    cout << "Nenhuma conta foi cadastrada.\n";
                } else if (!contaAtiva) {
                    cout << "A conta esta inativa. Operacao nao permitida.\n";
                } else {
                    cout << "Tipo atual: ";

                    if (tipoConta == 1) {
                        cout << "Corrente\n";
                    } else {
                        cout << "Poupanca\n";
                    }

                    do {
                        cout << "Novo tipo (1 - Corrente / 2 - Poupanca): ";
                        cin >> tipoConta;

                        if (tipoConta != 1 && tipoConta != 2) {
                            cout << "Erro: escolha 1 ou 2.\n";
                        }

                    } while (tipoConta != 1 && tipoConta != 2);

                    cout << "Tipo da conta alterado com sucesso!\n";
                }

                break;
            }

            case 5: {
                cout << "\n--- ATIVAR/DESATIVAR CONTA ---\n";

                if (!contaCadastrada) {
                    cout << "Nenhuma conta foi cadastrada.\n";
                } else {
                    contaAtiva = !contaAtiva;

                    if (contaAtiva) {
                        cout << "Conta ativada com sucesso!\n";
                    } else {
                        cout << "Conta desativada com sucesso!\n";
                    }
                }

                break;
            }

            case 6:
                cout << "\nSistema encerrado. Obrigado por utilizar o ADS BANK!\n";
                break;

            default:
                cout << "\nOpcao invalida! Escolha uma opcao de 1 a 6.\n";
        }

    } while (numero != 6);

    return 0;
}
    