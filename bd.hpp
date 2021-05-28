#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class City {
private:
	string city_name; //название города
	float city_x; //кооридната по оси ox этого города
	float city_y; //кооридната по оси oy этого города

public:
	City(string a, float b, float c){
		city_name = a;
		city_x = b;
		city_y =c;
	}
	void a() {
	cout << a;
	}
	string get_city_name(){
		return  name;
	}
	float get_city_x(){
		return city_x;
	}
	float get_city_y(){
		return city_y;
	}
	void set_city_name(string n){
		city_name = n;
	}
void set_coordinates(float a, float b){
	city_x = a;
city_y = b;
}
};

class Train {
private:
	int number; // номер поезда (id маршрута)
	float speed; // скорость поезда
	string from; // город откуда 
	string to; // город куда
	float distance; // расстояние между городами(*)
	int h_f; // Время отправления поезда, часы
	int m_f; // Время отправления поезда, минуты
	int h_f; // Время прибытия поезда, часы (*)
	int m_f; // Время прибытия поезда, минуты (*)
	int capacity_kupe; // вместительность купе в 1 вагоне
	int capacity_plackart; // вместительность плацкарта в 1 вагоне
	int vagoni_plackart; //кол-во вагонов плацкарт
	int vagoni_kupe;//кол-во вагонов купе
	int cost_kupe; // цена купе
	int cost_plackart; // цена плацкарта
public:
	int get_train_number(){
		return  number;
	}
	float get_train_speed(){
		return  speed;
	}
	string get_train_sity_from(){
		return from ;
	}
	string get_train_sity_to(){
		return  to;
	}
	int get_train_h_f(){
		return  h_f;
	}
	int get_train_m_f(){
		return  m_f;
	}
	int get_train_vagoni_plackart(){
		return  vagoni_plackart;
	}
	int get_train_vagoni_kupe(){
		return  vagoni_kupe;
	}
	int get_train_cost_plackart(){
		return  cost_plackart;
	}
	int get_train_cost_kupe(){
		return  cost_kupe;
	}

	void set_train_number(int a){
			train_number = a;
		}
	void set_train_speed(float a){
		if (a > 0.0){
			train_speed = a;
			}else{
				cout<<"не корректно"<<endl;
				}
		}
	void set_train_from(string a){
		if (a != " "){
			train_from = a;
			}else{
				cout<<"не корректно"<<endl;
				}
		}
	void set_train_to(string a){
		if (a != " "){
			train_to = a;
			}else{
				cout<<"не корректно"<<endl;
				}
		}
	void set_train_h_f(int a){
		if (a < 24 ){
			train_h_f = a;
			}else{
				cout<<"не корректно"<<endl;
				}
		}
	void set_train_m_f(int a){
		if (a < 60 ){
			train_m_f = a;
			}else{
				cout<<"не корректно"<<endl;
				}
		}
	void set_train_vagoni_kupe(int a){
			train_vagoni_kupe = a;
		}
	void set_train_vagoni_plackart(int a){
			train_vagoni_plackart = a;
		}
	void set_train_cost_kupe(int a){
			train_cost_kupe = a;
		}
	void set_train_cost_plackart(int a){
			train_cost_plackart = a;
		}

};

class Passenger{
private:
	string name; 
	int train_number; // номер поезда (id маршрута) (*) определяется по городам 
	int age; // возраст пассажира
	int spot; //Вид места пассажира, где 0 - купэ, 1 - плацкарт
	int n_vagona; //номер вагона пассажира (*) 
	int n_mesta; //номер места пассажира в вагоне (*)
	string city_from; //название города, откуда едет пассажир
	string city_to; //название города, в который едет пассажир
public:
	string get_name(){
		return name;
	}
	int get_train_number(){
		return train_number;
	}
	int get_age{
		return age;
	}
	int get_spot(){
		return spot;
	}
	int get_n_vagona(){
		return n_vagona;
	}
	int get_n_mesta(){
		return n_mesta;
	}
	/*string get_city_from(){
		return city_from;
	}
	string get_city_to(){
		return city_to;
	}*/
	void set_name(string a){
	name = a;
	}
	void set_age(int a){
		age = a;	
	}
	void set_spot(int a){
		spot = a;
	}
	void set_city_from(string a){
		sity_from = a;
	}
	void set_city_to(string a){
		city_to = a;
	}
};

class Time {

private:

	int d;
	int h;
	int m;

public: 

int get_d() {return d;}
int get_h() {return h;}
int get_m() {return m;}
void set_d(int _d){d = _d;} 
void set_h(int _h){h = _h;} 
void set_m(int _m){m = _m;} 

friend Time operator+(int const &t1, int const &t2) {
	Time result(((t1.d+t2.d)*1440 + (t1.h+t2.h)*60 +(t1.m+t2.m)) /     
	1440,((t1.h+t2.h)*60+(t1.m+t2.m))/60,((t1.m+t2.m) %60));
	return result;
};

friend Time operator-(int const &t1, int const &t2) {
	if(((t1.d- t2.d)*1440 + (t1.h-t2.h)*60 +(t1.m-t2.m)) > 0) {
		Time result(((t1.d-t2.d)*1440 + (t1.h-t2.h)*60 +(t1.m-t2.m)) /     
		1440,((t1.h-t2.h)*60+(t1.m-t2.m))/60,((t1.m-t2.m) %60));
		return result;
	}
	else {
		Time result(((t2.d-t1.d)*1440 + (t2.h-t1.h)*60 +(t2.m-t1.m)) /     
		1440,((t2.h-t1.h)*60+(t2.m-t1.m))/60,((t2.m-t1.m) %60));
		return result;
	};
	
friend ostream &operator<<(ostream &out, int const &t) {
	out << t.d << “:” << t.h << “:” << t.m;
return out;	
};


/*Дни: (дни*1440 + часы*24 + минуты) / 1440 
	Часы: (часы*60 + минуты) / 60 
	Минуты:(минуты) % 60*/