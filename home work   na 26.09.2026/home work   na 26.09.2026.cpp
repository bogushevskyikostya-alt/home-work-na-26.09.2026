/* Завдання 1
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int maxVal, current;
    cout << "Введіть 7 цілих чисел:\n";
    cin >> maxVal;

    for (int i = 1; i < 7; i++) {
        cin >> current;
        if (current > maxVal) {
            maxVal = current;
        }
    }

    cout << "Максимальне число: " << maxVal << endl;

    return 0;
}*/
/* Завдання 2
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    double distAB, distBC, weight;
    cout << "Введіть відстань між пунктами А і В (км): ";
    cin >> distAB;
    cout << "Введіть відстань між пунктами В і С (км): ";
    cin >> distBC;
    cout << "Введіть вагу вантажу (кг): ";
    cin >> weight;

    if (weight > 2000 || weight < 0) {
        cout << "Політ неможливий: літак не піднімає такий вантаж або введено некоректну вагу!" << endl;
        return 0;
    }

    double consumption = 0;
    if (weight <= 500) {
        consumption = 1.0;
    } else if (weight <= 1000) {
        consumption = 4.0;
    } else if (weight <= 1500) {
        consumption = 7.0;
    } else if (weight <= 2000) {
        consumption = 9.0;
    }

    double fuelAB = distAB * consumption;
    double fuelBC = distBC * consumption;

    const double TANK_CAPACITY = 300.0;

    if (fuelAB > TANK_CAPACITY) {
        cout << "Політ неможливий: відстань A-B занадто велика для повного бака!" << endl;
        return 0;
    }

    if (fuelBC > TANK_CAPACITY) {
        cout << "Політ неможливий: відстань B-C занадто велика навіть з повним баком!" << endl;
        return 0;
    }

    double fuelLeftInB = TANK_CAPACITY - fuelAB;

    
    double neededFuelInB = fuelBC - fuelLeftInB;

    if (neededFuelInB < 0) {
        neededFuelInB = 0; 
    }

    cout << "Витрата палива: " << consumption << " л/км" << endl;
    cout << "Палива потрібно на перший відрізок: " << fuelAB << " л" << endl;
    cout << "Палива залишиться в пункті В: " << fuelLeftInB << " л" << endl;
    cout << "Мінімальна кількість палива для дозаправки в пункті В: " << neededFuelInB << " л" << endl;

    return 0;
}
*/
/*Завдання 3
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

double calculateSalary(double sales) {
    double base = 200.0;
    double percent = 0.0;
    if (sales < 500) {
        percent = 0.03;
    } else if (sales <= 1000) {
        percent = 0.05;
    } else {
        percent = 0.08;
    }
    return base + sales * percent;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    double sales[3];
    double salaries[3];
    int bestManager = 0;

    cout << "Введіть рівень продажів для трьох менеджерів:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Менеджер " << i + 1 << ": ";
        cin >> sales[i];
        salaries[i] = calculateSalary(sales[i]);
    }

    for (int i = 1; i < 3; i++) {
        if (salaries[i] > salaries[bestManager]) {
            bestManager = i;
        }
    }

    salaries[bestManager] += 200.0;

    cout << "\n--- ПІДСУМКИ РОБОТИ МЕНЕДЖЕРІВ ---\n";
    fixed(cout);
    cout << setprecision(2);
    for (int i = 0; i < 3; i++) {
        cout << "Менеджер " << i + 1 << " (продажі: " << sales[i] << "$) -> Зарплата (з урахуванням премії, якщо є): " << salaries[i] << "$" << endl;
    }
    cout << "\nНайкращий менеджер: Менеджер " << bestManager + 1 << " (отримав додаткову премію 200$)\n";

    return 0;
}
*/
/* Завдання 4
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    cout << "Оберіть пункт меню:\n";
    cout << "1. Ввести бажаний дохід та кількість запізнень (порахувати рядки коду).\n";
    cout << "2. Ввести написані рядки коду та бажану зарплату (порахувати можливі запізнення).\n";
    cout << "3. Ввести кількість рядків коду та запізнень (визначити фінальну зарплату).\n";
    cout << "Ваш вибір (1-3): ";
    cin >> choice;

    if (choice == 1) {
        double desiredIncome;
        int lates;
        cout << "Введіть бажаний дохід Васі ($): ";
        cin >> desiredIncome;
        cout << "Введіть кількість запізнень: ";
        cin >> lates;
        double penalty = (lates / 3) * 20.0;
        double targetEarnings = desiredIncome + penalty;

        if (targetEarnings < 0) targetEarnings = 0;
        int linesNeeded = static_cast<int>(targetEarnings / 0.5);
        cout << "Васі потрібно написати мінімум " << linesNeeded << " рядків коду." << endl;

    } else if (choice == 2) {
        int lines;
        double desiredIncome;
        cout << "Введіть кількість написаних рядків коду: ";
        cin >> lines;
        cout << "Введіть бажаний обсяг зарплати ($): ";
        cin >> desiredIncome;

        double codeEarnings = (lines / 100.0) * 50.0;
        double allowedPenalty = codeEarnings - desiredIncome;

        if (allowedPenalty <= 0) {
            cout << "Вася вже не зможе отримати таку зарплату при поточній кількості коду (або заробіток менший за бажаний)." << endl;
        } else {
            int allowedLates = static_cast<int>(allowedPenalty / 20) * 3;
            cout << "Вася може запізнитися максимум " << allowedLates << " разів." << endl;
        }

    } else if (choice == 3) {
        int lines, lates;
        cout << "Введіть кількість написаних рядків коду: ";
        cin >> lines;
        cout << "Введіть кількість запізнень: ";
        cin >> lates;

        double codeEarnings = (lines / 100.0) * 50.0;
        double penalty = (lates / 3) * 20.0;
        double totalSalary = codeEarnings - penalty;

        if (totalSalary < 0) {
            totalSalary = 0;
        }

        cout << "Заробіток за код: " << codeEarnings << "$" << endl;
        cout << "Штрафи за запізнення (" << lates << " запізнень): -" << penalty << "$" << endl;
        cout << "Фінальна зарплата Васі: " << totalSalary << "$" << endl;
        if (totalSalary > 0) {
            cout << "Васі заплатять." << endl;
        } else {
            cout << "Васі нічого не заплатять через великі штрафи." << endl;
        }

    } else {
        cout << "Невірний вибір пункту меню!" << endl;
    }

    return 0;
}
*/