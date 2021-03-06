﻿#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <clocale>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <Windows.h>
#pragma warning(disable : 4996)

typedef unsigned short int usint;

using namespace std;

class Location {
private:
	char* name;
	usint course;
	usint group;
	usint loc;
public:
	Location(char* inName = nullptr, usint inCourse = 0, usint inGroup = 0, usint inLoc = 0) : course(inCourse), group(inGroup), loc(inLoc) {
		if (inName == nullptr) {
			name = nullptr;
			return;
		}
		try {
			name = new char[strlen(inName) + 1];
		}
		catch (...) {
			cout << "Ошибка при выделении памяти\n";
			exit(1);
		}
		strcpy(name, inName);
	};
	~Location() {
		delete[] name;
	};
	Location(const Location& other) : course(other.course), group(other.group), loc(other.loc) {
		if (other.name == nullptr) {
			name = nullptr;
			return;
		}
		try {
			name = new char[strlen(other.name) + 1];
		}
		catch (...) {
			cout << "Ошибка при выделении памяти\n";
			exit(1);
		}
		strcpy(name, other.name);
	};
	Location& operator=(const Location& other) {
		if (this != &other) { //нет ветки else rerurn *this;

			course = other.course;
			group = other.group;
			loc = other.loc;

			if (other.name == nullptr) {
				name = nullptr;
			}
			else {
				try {
					name = new char[strlen(other.name) + 1];
				}
				catch (...) {
					cout << "Ошибка при выделении памяти\n";
					exit(1);
				}
				strcpy(name, other.name);
			}
		}
	};
	friend istream& operator>>(istream &stream, Location &tmp) {
		char buffer[255];
		cout << "Введите фио студента(не более 255 символов)\n";
		fflush(stdin);
		while (1) {
			stream.getline(buffer, 255);
			if (strlen(buffer)) break;
		}
		if (tmp.name != nullptr) {
			delete[] tmp.name;  
		}
		try {
			tmp.name = new char[strlen(buffer) + 1]; //эту всю работу должен сделать constructor с параметрами...
		}
		catch (...) {
			cout << "Ошибка при выделении памяти\n";
			exit(1);
		}
		strcpy(tmp.name, buffer);
		cout << "Введите курс и группу студента\n";
		stream >> tmp.course >> tmp.group;
		cout << "Укажите тип жилья студента (0 - квартира, 1 - съемная квартира, 2 - общежитие)\n";
		while (1) {
			stream >> tmp.loc;
			if (tmp.loc / 3) cout << "Ошибка, повторите ввод\n";
			else break;
		}
		return stream;
	};
	friend ostream& operator<<(ostream &stream, Location &tmp) {
		stream << "Имя: " << tmp.name << "\nКурс: " << tmp.course << "\nГруппа: " << tmp.group << "\nТип жилья: ";
		switch (tmp.loc) {
		case 0:
			stream << "Квартира\n";
			break;
		case 1:
			stream << "Съемная квартира\n";
			break;
		case 2:
			stream << "Общежитие\n";
			break;
		}
		return stream;
	};
	char* getname() {
		return name;
	};
	usint getloc() {
		return loc;
	};
	usint getcourse() {
		return course;
	};
	usint getgroup() {
		return group;
	};
};
 // почему это в классе????? Внешняя, например, friend. Алучше создать set-еры
void sort(Location* base, int N) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (strcmp(base[i].getname(), base[j].getname()) > 0) {
				Location tmp = base[i];
				base[i] = base[j];
				base[j] = tmp;
			}
		}
	}
}
// почему это в классе?????
void getByLoc(Location* base, int N) {
	int loc;
	cout << "Укажите тип жилья студента (0 - квартира, 1 - съемная квартира, 2 - общежитие)\n";
	while (1) {
		cin >> loc;
		if (loc / 3) cout << "Ошибка, повторите ввод\n";
		else break;
	}
	for (int i = 0; i < N; i++) {
		if (base[i].getloc() == loc) {
			cout << base[i];
		}
	}
}

void getCount(Location* base, int N) {
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int group;
	int course;
	cout << "Введите курс и группу\n";
	cin >> course >> group;
	for (int i = 0; i < N; i++) {
		if (base[i].getcourse() == course && base[i].getgroup() == group) {
			switch (base[i].getloc()) {
			case 0:
				count0++;
				break;
			case 1:
				count1++;
				break;
			case 2:
				count2++;
				break;
			}
		}
	}
	cout << "Кол-во студентов, проживающих в квартире: " << count0 << '\n';
	cout << "Кол-во студентов, проживающих в съемной квартире: " << count1 << '\n';
	cout << "Кол-во студентов, проживающих в общежитии: " << count2 << '\n';
}

void getBy2(Location* base, int N) {
	int group;
	int course;
	cout << "Введите курс и группу\n";
	cin >> course >> group;
	for (int i = 0; i < N; i++) {
		if (base[i].getcourse() == course && base[i].getgroup() == group && base[i].getloc() == 2) cout << base[i];
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Введите кол-во записей в базе\n";
	cin >> N;
	Location* base;
	try {
		base = new Location[N];
	}
	catch (...) {
		cout << "Ошибка при выделении памяти\n";
		exit(1);
	}
	for (int i = 0; i < N; i++) {
		cin >> base[i];
	}
	sort(base, N);
	system("cls");

	for (int i = 0; i < N; i++) {
		cout << base[i] << '\n';
	}

	int op;
	while (1) {
		cout << "Выберите номер операции:\n";
		cout << "0 - Выход\n";
		cout << "1 - Получить списки студентов в алфавитном порядке по курсам и гуппам, проживающих в общежитии\n";
		cout << "2 - Получить список студентов в зависимости от типа жилья\n";
		cout << "3 - Вывести статистику по типу жилья для курса и группы\n";
		cin >> op;
		switch (op) {
		case 0:
			exit(0);
			break;
		case 1:
			getBy2(base, N);
			break;
		case 2:
			getByLoc(base, N);
			break;
		case 3:
			getCount(base, N);
			break;
		default:
			cout << "Неверный номер операции\n";
			break;
		}
	}

	delete[] base;

	system("pause");
	return 0;
}
