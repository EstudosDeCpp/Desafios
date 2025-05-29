#include <iostream>

int main() {
    int altura;
    std::cout << "Digite o tamanho do triangulo:";
    std::cin >> altura;

    int linha = 1;
    while (linha <= altura) {
        int estrelas = 1 * linha;

        int j = 0;
        while (j < estrelas) {
            std::cout << "*";
            j++;
        }

        std::cout << std::endl;
        linha++;
    }
    while (linha >= 1) {
        int estrelas = linha * 1 - 2;

        int j = 0;
        while (j < estrelas) {
            std::cout << "*";
            j++;
        }

        std::cout << std::endl;
        linha--;
    }
    return 0;
}