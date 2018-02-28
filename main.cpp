/*Даны точки плоскости своими координатами в виде двух одномерных массивов. Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.*/
#include <iostream>
using namespace std;
void initArray(float *A, const int N) {
    for (float *p = A; p < A + N; p++) {
        *p = rand() % 11;
    }
}
void printArray(float *A, const int N) {
    cout << "Array elements: ";
    for (float *p = A; p < A + N; p++) {
        cout << *p<<"  ";
    }
    cout << endl;
}

float CountDist(float x, float y, float a, float b, float c) {
    float dist = abs(a*x + b*y + c) / sqrt(a*a + b*b);
    return dist;
}

float *give_m(int N) {
    float *A;
    try {
        A = new float[N];
    }
    catch (...) {
        cout << "EROR! Can't creat this array.";
        return 0;
    }
    return A;
}

int delete_m(float *A, int N) {
    delete[N] A;
    return 0;
}

void SortDistance(float *A, float *B, const int N, float a, float b, float c) {
    for (float *p = A, *q = B; p < A + N; p++, q++) {
        for (float *k = p, *i = q; k < A + N; k++, i++) {
            if (CountDist(*p, *q, a, b, c) > CountDist(*k, *i, a, b, c)) {
                swap(*k, *p);
                swap(*i, *q);
            }
            
        }
    }
}




int main() {
    setlocale(LC_ALL, "ru");
    int N=0;
    float a = 0;
    float b = 0;
    float c = 0;
    float *A;
    float *B;
    
    cout << "Enter how much points of plane: ";
    cin >> N;
    A = give_m(N);
    B = give_m(N);
    while (1)
    {
        cout << "Enter coefficient of a*x+b*y+x=0: ";
        cout << "a=";
        cin >> a;
        cout << "b=";
        cin >> b;
        cout << "c=";
        cin >> c;
        if (a*a + b*b) break;//Геометрическая проверка на сущетвование прямой!
        else
        {
            cout << "This equation does not make sense.Please,try again! " << endl;
        }
    }
    
    
    initArray(A, N);
    initArray(B, N);
    printArray(A, N);
    printArray(B, N);
    SortDistance(A, B, N, a, b, c);
    cout << "Sorted from distance" << endl;
    printArray(A, N);
    printArray(B, N);
    system("pause");
    delete_m(A, N);
    return 0;
}
