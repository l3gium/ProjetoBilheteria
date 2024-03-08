#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
    const int fileiras = 15;
    const int qtdPoltronas = 40;
    const double valorFileira_1a5 = 50.00;
    const double valorFileira_6a10 = 30.00;
    const double valorFileira_11a15 = 15.00;
    
    bool ocupacao[fileiras][qtdPoltronas] = {false};

    int opcao;
    do {
        cout << "\nSelecione uma opção:" << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupação" << endl;
        cout << "3. Faturamento" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Finalizando programa." << endl;
                break;
            case 1: {
                int fileiraEscolhida, poltronaEscolhida;
                cout << "Informe a fileira (1-15): ";
                cin >> fileiraEscolhida;
                cout << "Informe o número da poltrona (1-40): ";
                cin >> poltronaEscolhida;

                if (fileiraEscolhida < 1 || fileiraEscolhida > fileiras || poltronaEscolhida < 1 || poltronaEscolhida > qtdPoltronas) {
                    cout << "Dados inválidos. Tente novamente." << endl;
                    break;
                }

                if (ocupacao[fileiraEscolhida - 1][poltronaEscolhida - 1]) {
                    cout << "Poltrona já está ocupada." << endl;
                } else {
                    ocupacao[fileiraEscolhida - 1][poltronaEscolhida - 1] = true;
                    cout << "Reserva efetuada com sucesso!" << endl;
                }
                break;
            }
            case 2: {
                cout << "Mapa de ocupação do teatro:" << endl;
                for (int i = 0; i < fileiras; ++i) {
                    for (int j = 0; j < qtdPoltronas; ++j) {
                        if (ocupacao[i][j]) {
                            cout << "#";
                        } else {
                            cout << ".";
                        }
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                int lugaresOcupados = 0;
                double valorTotal = 0.0;

                for (int i = 0; i < fileiras; ++i) {
                    for (int j = 0; j < qtdPoltronas; ++j) {
                        if (ocupacao[i][j]) {
                            lugaresOcupados++;
                            if (i < 5) {
                                valorTotal += valorFileira_1a5;
                            } else if (i < 10) {
                                valorTotal += valorFileira_6a10;
                            } else {
                                valorTotal += valorFileira_11a15;
                            }
                        }
                    }
                }

                cout << "Quantidade de lugares ocupados: " << lugaresOcupados << endl;
                cout << fixed << setprecision(2);
                cout << "Valor total da bilheteria: R$ " << valorTotal << endl;
                break;
            }
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
