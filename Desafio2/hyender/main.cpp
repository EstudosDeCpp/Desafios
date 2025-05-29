#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

int menu() {
    int opcao;
    cout << "----------------------------------------\n";
    cout << "        Conversor de Temperatura\n";
    cout << "     1 = abrir opcoes de temperatura\n";
    cout << "     2 = Fechar Programa\n";
    cout << "----------------------------------------\n";
    cout << "Selecione uma opcao: ";
    cin >> opcao;

    return opcao;
}

int main() {
    double temperatura;
    char TipoTemp;
    int OpcaoEscolhida;
    do {OpcaoEscolhida = menu();
        if (OpcaoEscolhida == 1) {
            cout << "----------------------------------------\n";
            cout << "        Conversor de Temperatura\n";
            cout << "     C = Celsius\n";
            cout << "     F = Fahrenheit\n";
            cout << "----------------------------------------\n";
            while (true) {
                cout << "Escreva a unidade que deseja converter para: \n";
                cin >> TipoTemp;
                if (cin.fail() || cin.peek() != '\n' || (TipoTemp != 'C' && TipoTemp != 'F' && TipoTemp != 'c' && TipoTemp != 'f')) {
                    cout << "Digite apenas 'C' ou 'F'.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    TipoTemp = tolower(TipoTemp);
                    break;
                }
            }
        }
        if (OpcaoEscolhida == 2) {
            break;
        }
        if (OpcaoEscolhida > 2) {
                cout << "Digite Apenas 1 ou 2: ";
                cin >> OpcaoEscolhida;
            }
        if (tolower (TipoTemp) == 'c') {
            cout << "Digite a Temperatura em Fahrenheit: \n";
            cin >> temperatura;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Erro: Por favor, digite apenas numeros.\n";
            }
            else {
                temperatura = (temperatura - 32) / 1.8;
                cout << "Temperatura em Celsius: " << temperatura << "C\n";
            }
        }
        if (tolower (TipoTemp) == 'f') {
            cout << "Digite a Temperatura em Celsius: \n";
            cin >> temperatura;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Erro: Por favor, digite apenas numeros.\n";
            }
            else {
                temperatura = (1.8 * temperatura) + 32.0;
                cout << "Temperatura em Fahrenheit: " << temperatura << "F\n";
            }
        }
    }while (OpcaoEscolhida != 2);
    return 0;
}
