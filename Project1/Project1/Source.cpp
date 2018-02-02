#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
using namespace std;
void Sort_Miz_Vid(int mass[], int size, string op) {
	int poch, kin = 0;
	for (int i = 0; i < size; i++)
		if (mass[i] < 0) { poch = i + 1; break; }
	for (int i = size - 1; i>0; i--)
		if (mass[i] < 0) { kin = i - 1; break; }

	if (op == "spad") {
		for (int i = poch; i < kin - 1; i++)
			for (int j = kin - 1; j > i; j--)
				if (mass[j] > mass[j - 1]) swap(mass[j], mass[j - 1]);
	}
	else if (op == "zrost") {
		for (int i = poch; i < kin - 1; i++)
			for (int j = kin - 1; j > i; j--)
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
	RandMass(arr, size, -10, 20);
	CoutMass(arr, size);
	cout << endl << "Spad" << endl;
	Sort_Miz_Vid(arr, size, "spad");
	CoutMass(arr, size);
	cout << endl << "Zrost" << endl;
	Sort_Miz_Vid(arr, size, "zrost");
	CoutMass(arr, size);
	system("pause");
}