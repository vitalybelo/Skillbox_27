#include <iostream>
#include "Company.h"
#include "use_lib.h"
using namespace std;

void solution_3() {


    Company company("BUBLIKOV & SONS LTD");
    company.generateCompany(5);
    cout << company << endl;

    cout << "������������� ������������� �������� ��������� ��:\n";
    cout << "����� ������������ ��������� � 5-�� ������� � ������������\n";
    cout << "���������� ����������� ������� ������ �� 5 �� 8 �������, ������� ���������\n";
    cout << "������ ��� ������ �� ������, ���� ������������. ������� ��� ����������.\n";
    cout << "��� ����� ������� ����� �����: ";

    do {
        int order;
        cin >> order;

        if (company.simulateCompanyWork(order)) break;
        cout << company << endl;
        cout << "��� �� ��� ���������� ������ �������, ����������� �����������\n";
        cout << "��� ����� ������� ����� �����: ";

    } while (true);
    cout << company << endl;
    cout << "�� �������, � ������������ ������������! ��� �������� - ����� ��������� ...'\n";

}