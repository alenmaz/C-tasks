#include "Values.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    double val1 = 0;
    double val2 = 0;

    cout << "Расчет напряжения U по известным значениям тока I и сопротивления R." << endl;
    cout << "Введите I и R: ";
    cin >> val1 >> val2;
    cout << "Результат: U = I * R = " << (RValue(val1) * IValue(val2)).Volt() << endl;


    cout << "Расчет тока I по известным значениям напряжения U и сопротивления R." << endl;
    cout << "Введите U и R: ";
    cin >> val1 >> val2;
    cout << "Результат: I = U / R = " << (UValue(val1) / RValue(val2)).Ampere() << endl;


    cout << "Расчет сопротивления R по известным значениям напряжения U и тока I." << endl;
    cout << "Введите U и I: ";
    cin >> val1 >> val2;
    cout << "Результат: R = U / I = " << (UValue(val1) / IValue(val2)).Ohm() << endl;


    cout << "Расчет итогового сопротивления для последовательного соединения резисторов." << endl;
    cout << "Введите R1, R2: ";
    cin >> val1 >> val2;
    cout << "Результат: R = R1 + R2 = " << (RValue(val1) + RValue(val2)).Ohm() << endl;


    cout << "Расчет итогового сопротивления для параллельного соединения резисторов." << endl;
    cout << "Введите R1, R2: ";
    cin >> val1 >> val2;
    cout << "Результат: R = R1 % R2 = " << (RValue(val1) % RValue(val2)).Ohm() << endl;


    cout << "Расчет итоговой ёмкости для параллельного соединения конденсаторов." << endl;
    cout << "Введите C1, C2: ";
    cin >> val1 >> val2;
    cout << "Результат: C = C1 % C2 = " << (CValue(val1) % CValue(val2)).Farade() << endl;


    cout << "Расчет итоговой ёмкости для последовательного соединения конденсаторов." << endl;
    cout << "Введите C1, C2: ";
    cin >> val1 >> val2;
    cout << "Результат: C = C1 + C2 = " << (CValue(val1) + CValue(val2)).Farade() << endl;


    cout << "Расчет процесса заряда конденсатора ёмкостью C через резистор сопротивлением R от источника напряжения U в течение двух секунд для значений C = 10мкФ, R = 200кОм, U = 1В" << endl;
    CValue cval = CValue(10 * pow(10, -6));
    UValue uval = UValue(1);
    RValue rval = RValue(200 * pow(10, 3));
    TValue tval = TValue(2);
    IValue ival = uval / rval;
    for (TValue t = TValue(1); t <= tval; t = t + TValue(1))
    {
        cout << "При t = " << t << "и I = " << ival << endl;
        cout << "q = I * t" << ival * t << endl;
    }
}
