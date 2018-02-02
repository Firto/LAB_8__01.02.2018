#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
using namespace std;
void Sort(int mass[], int size, string op) {
	if (op == "spad") {
		for (int i = 0; i < size - 1; i++)
			for (int j = size - 1; j > i; j--)
				if (mass[j] > mass[j - 1]) swap(mass[j], mass[j - 1]);
	}
	else if (op == "zrost") {
		for (int i = 0; i < size - 1; i++)
			for (int j = size - 1; j > i; j--)
				if (mass[j] < mass[j - 1]) swap(mass[j], mass[j - 1]);
	}
}
void CoutMass(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << "Arr[" << i << "] = " << arr[i] << endl;
}
void RandMass(int arr[], int size, int a, int b)
{
	b++;
	srand(time(0));
	for (int i = 0; i < size; i++) arr[i] = rand() % (b - a) + a;
}
void main() {
	const int size = 10;
	int arr[size];
	RandMass(arr, size, -9, 9);
	CoutMass(arr, size);
	cout << endl << "Spad" << endl;
	Sort(arr, size, "spad");
	CoutMass(arr, size);
	cout << endl << "Zrost" << endl;
	Sort(arr, size, "zrost");
	CoutMass(arr, size);
	system("pause");
}