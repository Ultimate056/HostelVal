#include <iostream>
#include <string>
#include <algorithm>
#include <Zag.h>
#include <vector>
vector<int>::iterator iter;
vector<int> rooms::iline_busy_101;
vector<int> rooms::iline_busy_102;
vector<int> rooms::iline_busy_103;
vector<int> rooms::iline_busy_104;
vector<int> rooms::iline_busy_105;
vector<int> rooms::iline_busy_106;
vector<int> rooms::iline_busy_107;
vector<int> rooms::iline_busy_201;
vector<int> rooms::iline_busy_202;
vector<int> rooms::iline_busy_203;
vector<int> rooms::iline_busy_204;
vector<int> rooms::iline_busy_205;
vector<int> rooms::iline_busy_301;
vector<int> rooms::iline_busy_302;
vector<int> rooms::iline_busy_303;
vector<int> rooms::rooms_standart_busy_now;
vector<int> rooms::rooms_lux_busy_now;
vector<int> rooms::rooms_president_busy_now;


bool check_busy(vector<int>busy_room, int day_come, int days)
{
	int k = 0;
	int n = 0;
	bool check = false;
	if (busy_room.empty())
		return true;
	for (day_come; day_come <= day_come + days; day_come++)
	{
		for (iter = busy_room.begin(); iter != busy_room.end(); ++iter)
		{
			if (day_come != *iter)
			{
				n++;
			}
		}
		if (n == busy_room.size())
		{
			k++;
		}
		n = 0;
	}
	if (k == days + 1)
	{
		return true;
	}
}
void rooms::get_choise_guest(unsigned short int cg) { // Получаем выбор клиента
		choise_guest = cg;
	}
void rooms::get_date(int day) { // Получаем день заезда
		this->day_come = day;
}
void rooms::get_days(int days) { // Получаем кол-во суток
	this->ammount_days = days;
}
int rooms::send_room() { // Возвращаем комнату жильца
	return living_room;
}
bool rooms::check_busys()
{
	if (choise_guest == 1)
	{
		if (check_busy(iline_busy_101, day_come, ammount_days) == true) {
			living_room = 101;
			return true;
		}
		if (check_busy(iline_busy_102, day_come, ammount_days) == true) {
			living_room = 102;
			return true;
		}
		if (check_busy(iline_busy_103, day_come, ammount_days) == true) {
			living_room = 103;
			return true;
		}
		if (check_busy(iline_busy_104, day_come, ammount_days) == true) {
			living_room = 104;
			return true;
		}
		if (check_busy(iline_busy_105, day_come, ammount_days) == true) {
			living_room = 105;
			return true;
		}
		if (check_busy(iline_busy_106, day_come, ammount_days) == true) {
			living_room = 106;
			return true;
		}
		if (check_busy(iline_busy_107, day_come, ammount_days) == true) {
			living_room = 107;
			return true;
		}
	}
	if (choise_guest == 2)
	{
		if (check_busy(iline_busy_201, day_come, ammount_days) == true) {
			living_room = 201;
			return true;
		}
		if (check_busy(iline_busy_202, day_come, ammount_days) == true) {
			living_room = 202;
			return true;
		}
		if (check_busy(iline_busy_203, day_come, ammount_days) == true) {
			living_room = 203;
			return true;
		}
		if (check_busy(iline_busy_204, day_come, ammount_days) == true) {
			living_room = 204;
			return true;
		}
		if (check_busy(iline_busy_205, day_come, ammount_days) == true) {
			living_room = 205;
			return true;
		}
	}
	if (choise_guest == 3)
	{
		if (check_busy(iline_busy_301, day_come, ammount_days) == true) {
			living_room = 301;
			return true;
		}
		if (check_busy(iline_busy_302, day_come, ammount_days) == true) {
			living_room = 302;
			return true;
		}
		if (check_busy(iline_busy_303, day_come, ammount_days) == true) {
			living_room = 303;
			return true;
		}
	}
} 
void rooms::add_room_in_busy_rooms() {
	int temp = day_come + ammount_days;
	if (living_room >= 101 && living_room <= 107) {
		rooms_standart_busy_now.push_back(living_room);
		if (living_room == 101) {
			while (day_come < temp) {
				cout << day_come << endl;
				iline_busy_101.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 102) {
			while (day_come < temp) {
				iline_busy_102.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 103) {
			while (day_come < temp) {
				iline_busy_103.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 104) {
			while (day_come < temp) {
				iline_busy_104.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 105) {
			while (day_come < temp) {
				iline_busy_105.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 106) {
			while (day_come < temp) {
				iline_busy_106.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 107) {
			while (day_come < temp) {
				iline_busy_107.push_back(day_come);
				day_come++;
			}
		}
	}
	if (living_room >= 201 && living_room <= 205) {
		rooms_lux_busy_now.push_back(living_room);
		if (living_room == 201) {
			while (day_come < temp) {
				iline_busy_201.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 202) {
			while (day_come < temp) {
				iline_busy_202.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 203) {
			while (day_come < temp) {
				iline_busy_203.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 204) {
			while (day_come < temp) {
				iline_busy_204.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 205) {
			while (day_come < temp) {
				iline_busy_205.push_back(day_come);
				day_come++;
			}
		}
	}
	if (living_room >= 301 && living_room <= 303) {
		rooms_president_busy_now.push_back(living_room);
		if (living_room == 301) {
			while (day_come < temp) {
				iline_busy_301.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 302) {
			while (day_come < temp) {
				iline_busy_302.push_back(day_come);
				day_come++;
			}
		}
		if (living_room == 303) {
			while (day_come < temp) {
				iline_busy_303.push_back(day_come);
				day_come++;
			}
		}
	}
}

void guest::set_default() {
	family = "";
	name = "";
	phone = "";
	series_pass = "";
	number_pass = "";
}
string guest::get_str() {
	return family;
}
void guest::set_info_guest(int am_d) {
	cin.get();
	cout << "1. Фамилия: "; cin >> family;
	cout << "2. Имя: "; cin >> name;
	cout << "3. Телефон: "; cin >> phone;
	cout << "4. Серия паспорта: "; cin >> series_pass;
	cout << "5. Номер паспорта: "; cin >> number_pass;
	ammount_days = am_d;
}
void guest::put_info_guest()
{
	cout << "Номер комнаты: " << living_room << endl;
	cout << "Фамилия: " << family << endl;
	cout << "Имя: " << name << endl;
	cout << "Номер телефона: " << phone << endl;
	cout << "Серия паспорта: " << series_pass << endl;
	cout << "Номер паспорта: " << number_pass << endl;
	cout << "Дата прибытия: " << date_coming << endl;
	cout << "Дата уезда: " << date_county << endl;
}
void guest::set_date_and_room(int mon, int day, int room) {
	date_coming = " ";
	date_county = " ";
	living_room = room;
}



