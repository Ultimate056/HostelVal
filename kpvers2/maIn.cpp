#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#include "Zag.h"
#include <ctime>
using namespace std;
const int price_standart = 1500;
const int price_lux = 2000;
const int price_president = 2500;
const string name_hotel = "Eleon";

int main(void)
{
	setlocale(LC_ALL, "RUS");
	vector<int>rooms_standart = { 101,102,103,104,105,106,107 }; // ������� ��������� �������
	vector<int>rooms_lux = { 201,202,203,204,205 };
	vector<int>rooms_president = { 301,302,303 };
	time_t now = time(0);
	unsigned short int answer1; // ����� ������������
	unsigned short int choise_guest; // ����� ������������ ������ ������
	int payment; // ������(bool)
	int pay; // ����������� ����� � ������
	int kassa = 0;
	int days;
	int i = 0;
	guest* guests = new guest[10]; // ����� ��������
	rooms* _rom = new rooms[10];
	tm* times_now = new tm[10];
	//
	while (1)
	{
		if (i >= 1) {
			if (guests[i-1].get_str() == "") {
				i--;
			}
		}
		cout << "������: ���� ������ ��� � ����� " << name_hotel << endl;
		cout << "������: ��� ���� ������?" << endl;
		cout << "��: ������������, � �� �����: " << endl;
		cout << "1. ���������� � ��� � �����. " << endl;
		cout << "2. ������������� � ��� �����. " << endl;
		cin >> answer1; // ����� 1
		if (answer1 == 1) {
			cout << "������: �������, � ������� ������ ������ �� �� ������ � ��� ������������:\n1. �������� �� 1500 ������ � ����� \n2. ���� �� 2000 ������ � �����\n3. ������������� �� 2500 ������ � �����. " << endl;
			cout << "��: "; cin >> choise_guest;
			cout << "������: �� ����� ���-�� ����� ������� � ��� ������������?" << endl;
			cout << "��: ", cin >> days;
			cout << "������: ����������, �������� ���� �� ��������� ������..." << endl;
			_rom[i].get_date(13);
			_rom[i].get_choise_guest(choise_guest);
			_rom[i].get_days(days);
			if (_rom[i].check_busys())
				cout << "������: ��! ��������� ����� ����. " << endl;
			else {
				cout << "������: � ���������, ��������� ������� ������ �������� �� ������ �� �� �����(" << endl;
				break;
			}
			cout << "������: ������� ��� �������. ��������� ������." << endl;
			guests[i].set_info_guest(days);
			if (choise_guest == 1)
				pay = days * price_standart;
			if (choise_guest == 2)
				pay = days * price_lux;
			if (choise_guest == 3)
				pay = days * price_president;
			int live = _rom[i].send_room();
			cout << "������: ���������� ������ � �����: " << pay << endl;
			cout << "������� 1, ����� ��������. 0, ����� ���������� � ����." << endl;
			cout << "��: "; cin >> payment;
			if (payment == 1) {
				cout << "��������� ������� � ������ �������..." << endl;
				_rom[i].add_room_in_busy_rooms();
				guests[i].set_date_and_room(6, 7, live);
				cout << "��������� ������ � �����..." << endl;
				kassa += pay;
				cout << "������: ���� �������: " << live << " , ��������� ������" << endl;
			}
			else {
				guests[i].set_default();
				break;
			}
			char sym;
			cout << "��������� ���������? ������� (y - ��, n-���): "; cin >> sym;
			if (sym == 'y') {
				i++;
				system("cls");
				continue;
			}
			else {
				break;
			}
		}
		if (answer1 == 2) {
		}
	}

	return 0;
}


