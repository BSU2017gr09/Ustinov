/*Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.*/
#include <iostream>
using namespace std;

void initArray(int *A, const int N) {
    for (int *p = A; p < A + N; p++) {
        *p = rand() % 11;
    }
}

void printArray(int *A, const int N) {
    cout << "Элементы массива: ";
    for (int *p = A; p < A + N; p++) {
        cout << *p << " ";
    }
}


void ascendsort(int *A, const int N,int k) {
    for (int *p = (A + k); p < A + N; p++) {
        for (int *q = A+k; q < A + N; q++) {
            if (*p < *q) {
                swap(*q, *p);
            }
            
        }
    }
}
//void ascendsort(int *A, const int N,int k) {//Цикл не через указатели
//	for (int i = 0; i < N;i++) {
//		for (int j = k; j < N-1;j++) {
//			if (*(A+j)< *(A+j+1) ){
//				swap(*(A + j), *(A + j + 1));
//			}
//
//		}
//	}
//}

int *give_m(int N) {
    int *A;
    try {
        A = new int[N];
    }
    catch (...) {
        cout << "EROR! Can't creat this array.";
        return 0;
    }
    return A;
}
int *delete_m(int *A, int N) {
    delete[N] A;
    return 0;
}


int main() {
    setlocale(LC_ALL, "Rus");
    int N = 0;
    int k=0;
    int *A;
    cout << "Enter the number of elements in the array:" << endl;
    cin >> N;
    cout << "Enter the element from which the array is sorted:" << endl;
    cin >> k;
    A=give_m(N);
    initArray(A, N);
    printArray(A, N);
    ascendsort(A, N, k);
    cout << endl;
    printArray(A, N);
    delete_m(A, N);
    
    
    system("pause");
    return 0;
}
