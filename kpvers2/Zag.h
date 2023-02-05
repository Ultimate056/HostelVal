#include <string>
#include <vector>
using namespace std;
bool check_busy(vector<int>busy_room, int day_come, int days);
class rooms
{
private:
	static vector<int>iline_busy_101; // К каждой комнате своя линейка (из занятых дней)
	static vector<int>iline_busy_102;
	static vector<int>iline_busy_103;
	static vector<int>iline_busy_104;
	static vector<int>iline_busy_105;
	static vector<int>iline_busy_106;
	static vector<int>iline_busy_107;
	static vector<int>iline_busy_201;
	static vector<int>iline_busy_202;
	static vector<int>iline_busy_203;
	static vector<int>iline_busy_204;
	static vector<int>iline_busy_205;
	static vector<int>iline_busy_301;
	static vector<int>iline_busy_302;
	static vector<int>iline_busy_303;
	static vector<int>rooms_standart_busy_now;
	static vector<int>rooms_lux_busy_now;
	static vector<int>rooms_president_busy_now;
	int day_come; // День заезда
	unsigned int living_room; // Комната жильца
	unsigned short int ammount_days; // Кол-во суток
	unsigned short int choise_guest; // Выбор гостя уровня номеров
public:
	void get_choise_guest(unsigned short int cg);
	void get_date(int day);
	void get_days(int days);
	int send_room();
	bool check_busys();
	void add_room_in_busy_rooms();
};
class guest
{
	friend class rooms;
private:
	string family;
	string name;
	string phone;
	string series_pass;
	string number_pass;
	unsigned int living_room;
	string date_coming; // Дата прибытия
	string date_county; // Дата уезда
	unsigned short int ammount_days;
public:
	~guest() {}
	void set_default();
	string get_str();
	void set_info_guest(int am_d);
	void put_info_guest();
	void set_date_and_room(int mon, int day, int room);
};



