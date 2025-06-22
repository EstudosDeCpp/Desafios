#include <iostream>
#include <limits>
#include <cctype>

int menu() {
    int opcao;
    std::cout << "----------------------------------------\n";
    std::cout << "        Conversor de Temperatura\n";
    std::cout << "     1 = abrir opcoes de temperatura\n";
    std::cout << "     2 = Fechar Programa\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Selecione uma opcao: ";
    std::cin >> opcao;

    return opcao;
}

int main() {
    double temperatura;
    char TipoTemp;
    int OpcaoEscolhida;
    do {OpcaoEscolhida = menu();
        if (OpcaoEscolhida == 1) {
            std::cout << "----------------------------------------\n";
            std::cout << "        Conversor de Temperatura\n";
            std::cout << "     C = Celsius\n";
            std::cout << "     F = Fahrenheit\n";
            std::cout << "----------------------------------------\n";
            while (true) {
                std::cout << "Escreva a unidade que deseja converter para: \n";
                std::cin >> TipoTemp;
                if (std::cin.fail() || std::cin.peek() != '\n' || (TipoTemp != 'C' && TipoTemp != 'F' && TipoTemp != 'c' && TipoTemp != 'f')) {
                    std::cout << "Digite apenas 'C' ou 'F'.\n";
                    std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                std::cout << "Digite Apenas 1 ou 2: ";
                std::cin >> OpcaoEscolhida;
            }
        if (tolower (TipoTemp) == 'c') {
            std::cout << "Digite a Temperatura em Fahrenheit: \n";
            std::cin >> temperatura;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Erro: Por favor, digite apenas numeros.\n";
            }
            else {
                temperatura = (temperatura - 32) / 1.8;
                std::cout << "Temperatura em Celsius: " << temperatura << "C\n";
            }
        }
        if (tolower (TipoTemp) == 'f') {
            std::cout << "Digite a Temperatura em Celsius: \n";
            std::cin >> temperatura;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Erro: Por favor, digite apenas numeros.\n";
            }
            else {
                temperatura = (1.8 * temperatura) + 32.0;
                std::cout << "Temperatura em Fahrenheit: " << temperatura << "F\n";
            }
        }
    }while (OpcaoEscolhida != 2);
    return 0;
}
