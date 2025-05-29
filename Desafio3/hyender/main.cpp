#include <iostream>
#include <limits>
using namespace std;

double SoNumero (string NaoNumero, double maximo = -1) {
  double numero;

    while (true) {
      cout << NaoNumero << endl;
        cin >> numero;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Por favor, digite apenas numeros." << endl;
        } else if (maximo > 0 && numero > maximo) {
            cout << "Numero de horas maior que o esperado, tente de novo." << endl;
        } else {
            return numero;
        }
    }
}

int main() {
    double GanhoPorHora = SoNumero("Quanto voce ganha por hora? : ");
    double HorasTrabalhadas = SoNumero("Quantas horas voce trabalhou no mes? : ", 730);

    double SalarioBruto = GanhoPorHora * HorasTrabalhadas;
    cout << "Seu Salario Bruto: R$ " << SalarioBruto << '\n' << endl;

    double ir = SalarioBruto * 11 / 100;
    double inss = SalarioBruto * 8 / 100;
    double sindicato = SalarioBruto * 5 / 100;
    double TotalDescontos = ir + inss + sindicato;

    double SalarioLiquido = SalarioBruto - inss - ir - sindicato;

    cout << "Seu Salario Liquido e gastos com impostos: \n"
      << "INSS: R$ " << inss << '\n'
        << "Imposto de Renda: R$ " << ir << '\n'
          << "Sindicato: R$ " << sindicato << '\n'
            << "Total dos descontos: R$ " << TotalDescontos << " | 24%" << '\n'
              << "Salario Liquido: R$ " << SalarioLiquido << '\n' << endl;

    return 0;
}
