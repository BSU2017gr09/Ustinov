#include <iomanip>
#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;

typedef void menu(int**&, int&, int&);
typedef menu* ptrmenu;

void exit(int**&, int&, int&);
void help(int**&, int&, int&);
void input(int**&, int&, int&);
void output(int**&, int&, int&);
void transform(int**&, int&, int&);

void giveMemory(int**&, int, int);
void freeMemory(int**&, int, int);

void foreach(ptrmenu, int**&, int&, int&);

int main() {
	setlocale(LC_ALL, ".1251");
	srand(time(NULL));

	int** matrix = nullptr;
	int n = 0;
	int m = 0;

	ptrmenu function[5] = { exit, help, input, transform, output };

	char op;

	while (1) {
		cout << "Введите номер операции:\n\
0) Выход\n\
1) Вывести условие задачи\n\
2) Ввести матрицу\n\
3) Преобразовать матрицу по условию\n\
4) Вывести матрицу\n";
		cin >> op;
		op -= '0';
		if (op < 0 || op > 4) {
			cout << "Неверный номер операции\n\n";
			continue;
		}
		foreach(function[op], matrix, n, m);
	}

	system("pause");
	return 0;
}

void giveMemory(int**& matrix, int n, int m) {
	try {
		matrix = new int*[n];
	}
	catch (...) {
		cout << "Ошибка при выделении памяти\n";
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		try {
			matrix[i] = new int[m];
		}
		catch (...) {
			cout << "Ошибка при выделении памяти\n";
			exit(1);
		}
	}
}

void freeMemory(int**& matrix, int n, int m) {
	if (matrix == nullptr) return;
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void foreach(ptrmenu fun, int**& matrix, int& n, int& m) {
	fun(matrix, n, m);
}

void exit(int**& matrix, int& n, int& m) {
	freeMemory(matrix, n, m);
	exit(0);
}

void help(int**& matrix, int& n, int& m) {
	cout << "17. Сменить знак минимального элемента массива А(N,N), если он\n\
находится выше главной диагонали.\n\n";
}

void input(int**& matrix, int& n, int& m) {
	cout << "Введите размеры матрицы: ";
	cin >> n >> m;
	giveMemory(matrix, n, m);
	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << '\n';
}

void output(int**& matrix, int& n, int& m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(4) << matrix[i][j];
		}
		cout << '\n';
	}
	cout << "\n\n";
}

void transform(int**& matrix, int& n, int& m) {
	if (matrix == nullptr) return;
	int min = matrix[0][0];
	int iMin = 0;
	int jMin = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] < min) {
				iMin = i;
				jMin = j;
				min = matrix[i][j];
			}
		}
	}
	matrix[iMin][jMin] = -matrix[iMin][jMin];
	cout << '\n';
}