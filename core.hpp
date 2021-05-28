#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class core {
private:
	fstream f_t; //Файловый поток для БД рейсов
fstream f_c; //Файловый поток для БД городов
fstream f_p;  //Файловый поток для БД пассажиров
	char *f_city;  //Названия файла БД
	char *f_train;  //Названия файла БД
	char *f_passenger;  //Названия файла БД
	City *arrCity; //Массив, связанный с БД городов
	Train *arrTrain; //Массив, связанный с БД рейсов
	Passenger *arrPassenger;  //Массив, связанный с БД пассажиров
int size_t; // Кол-во объектов типа Train
int size_c; // Кол-во объектов типа City
int size_p; // Кол-во объектов типа Passenger
public:
void get_f_city(char *_f_city) {f_city = _f_city;} 
void get_f_train(char *_f_train) {f_train = _f_train;}
void get_f_passenger(char *_f_passenger) {f_passenger = _f_passenger;}  

void f_to_arr(){

			string buf;
		f_t.open(f_train,ios::in);
		size_t = 0;
                	while(file.peek() != EOF) {
                        	getline(f_t,buf);
			size_t++;
		}
		f_t.clear();
		f_t.seekg(0);
		arrTrain = new Train [size_t];
		for (int i = 0; i<size_t; i++) {
			считывание переменных с файла через << и getline
		}
		f_t.close();

f_c.open(f_city,ios::in);
		size_c = 0;
                	while(f_c.peek() != EOF) {
                        	getline(f_c,buf);
			size_c++;
		}
		f_c.clear();
		f_c.seekg(0);
		arrCity = new City [size_c];
		for (int i = 0; i<size_c; i++) {
			считывание переменных с файла через << и getline
		}
		f_c.close();

f_p.open(f_passenger,ios::in);
		size_p = 0;
                	while(f_p.peek() != EOF) {
                        	getline(f_p,buf);
			size_p++;
		}
		f_p.clear();
		f_p.seekg(0);
		arrPassenger = new Passenger [size_p];
		for (int i = 0; i<size_p; i++) {
			считывание переменных с файла через << и getline
		}
		f_p.close();

};
