#include <iostream>
#include <limits>

double SoNumero (std::string NaoNumero, double maximo = -1) {
  double numero;

    while (true) {
      std::cout << NaoNumero << std::endl;
        std::cin >> numero;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor, digite apenas numeros." << std::endl;
        } else if (maximo > 0 && numero > maximo) {
            std::cout << "Numero de horas maior que o esperado, tente de novo." << std::endl;
        } else {
            return numero;
        }
    }
}

int main() {
    double GanhoPorHora = SoNumero("Quanto voce ganha por hora? : ");
    double HorasTrabalhadas = SoNumero("Quantas horas voce trabalhou no mes? : ", 730);

    double SalarioBruto = GanhoPorHora * HorasTrabalhadas;
    std::cout << "Seu Salario Bruto: R$ " << SalarioBruto << '\n' << std::endl;

    double ir = SalarioBruto * 11 / 100;
    double inss = SalarioBruto * 8 / 100;
    double sindicato = SalarioBruto * 5 / 100;
    double TotalDescontos = ir + inss + sindicato;

    double SalarioLiquido = SalarioBruto - inss - ir - sindicato;

    std::cout << "Seu Salario Liquido e gastos com impostos: \n"
      << "INSS: R$ " << inss << '\n'
        << "Imposto de Renda: R$ " << ir << '\n'
          << "Sindicato: R$ " << sindicato << '\n'
            << "Total dos descontos: R$ " << TotalDescontos << " | 24%" << '\n'
              << "Salario Liquido: R$ " << SalarioLiquido << '\n' << std::endl;

    return 0;
}
