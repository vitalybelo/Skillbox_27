#include <iostream>
#include "Company.h"
#include "use_lib.h"
using namespace std;

void solution_3() {


    Company company("BUBLIKOV & SONS LTD");
    company.generateCompany(5);
    cout << company << endl;

    cout << "Автоматически сгенерирована компания состоящая из:\n";
    cout << "Офиса генерального директора и 5-ти отделов с сотрудниками\n";
    cout << "Количество сотрудников каждого отдела от 5 до 8 человек, включая менеджера\n";
    cout << "Сейчас они ничего не делают, ждут распоряжения. Выдайте его пожалуйста.\n";
    cout << "Для этого введите целое число: ";

    do {
        int order;
        cin >> order;

        if (company.simulateCompanyWork(order)) break;
        cout << company << endl;
        cout << "Еще не все сотрудники заняты работой, продолжайте приказывать\n";
        cout << "Для этого введите целое число: ";

    } while (true);
    cout << company << endl;
    cout << "Вы молодец, и прирожденный руководитель! все работают - можно отдохнуть ...'\n";

}