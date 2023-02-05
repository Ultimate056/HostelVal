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
	vector<int>rooms_standart = { 101,102,103,104,105,106,107 }; // Массивы свободных номеров
	vector<int>rooms_lux = { 201,202,203,204,205 };
	vector<int>rooms_president = { 301,302,303 };
	time_t now = time(0);
	unsigned short int answer1; // Ответ пользователя
	unsigned short int choise_guest; // Выбор пользователя уровня комнат
	int payment; // Оплата(bool)
	int pay; // Необходимая сумма к оплате
	int kassa = 0;
	int days;
	int i = 0;
	guest* guests = new guest[10]; // Поток клиентов
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
		cout << "Портье: Рады видеть вас в отеле " << name_hotel << endl;
		cout << "Портье: Чем могу помочь?" << endl;
		cout << "Вы: Здравствуйте, я бы хотел: " << endl;
		cout << "1. Поселиться у вас в отеле. " << endl;
		cout << "2. Забронировать у вас номер. " << endl;
		cin >> answer1; // ответ 1
		if (answer1 == 1) {
			cout << "Портье: Отлично, в комнате какого класса вы бы хотели у нас остановиться:\n1. Стандарт за 1500 рублей в сутки \n2. Люкс за 2000 рублей в сутки\n3. Президентский за 2500 рублей в сутки. " << endl;
			cout << "Вы: "; cin >> choise_guest;
			cout << "Портье: На какое кол-во суток желаете у нас остановиться?" << endl;
			cout << "Вы: ", cin >> days;
			cout << "Портье: Секундочку, проверяю есть ли свободные номера..." << endl;
			_rom[i].get_date(13);
			_rom[i].get_choise_guest(choise_guest);
			_rom[i].get_days(days);
			if (_rom[i].check_busys())
				cout << "Портье: Да! Свободный номер есть. " << endl;
			else {
				cout << "Портье: К сожалению, свободную комнату класса которого вы хотели мы не нашли(" << endl;
				break;
			}
			cout << "Портье: Давайте вас оформим. Заполните анкету." << endl;
			guests[i].set_info_guest(days);
			if (choise_guest == 1)
				pay = days * price_standart;
			if (choise_guest == 2)
				pay = days * price_lux;
			if (choise_guest == 3)
				pay = days * price_president;
			int live = _rom[i].send_room();
			cout << "Портье: Необходимо оплата в сумме: " << pay << endl;
			cout << "Нажмите 1, чтобы оплатить. 0, чтобы отказаться и уйти." << endl;
			cout << "Вы: "; cin >> payment;
			if (payment == 1) {
				cout << "Добавляем комнату в список занятых..." << endl;
				_rom[i].add_room_in_busy_rooms();
				guests[i].set_date_and_room(6, 7, live);
				cout << "Добавляем деньги в кассу..." << endl;
				kassa += pay;
				cout << "Портье: ваша комната: " << live << " , приятного отдыха" << endl;
			}
			else {
				guests[i].set_default();
				break;
			}
			char sym;
			cout << "Повторить программу? Нажмите (y - да, n-нет): "; cin >> sym;
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


