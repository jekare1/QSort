// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "algorithm"
#include "cstdlib" // подключение заголовочного файла для использования rand()

using namespace std;

//функция сортировки
// принимает на вход указатель на массив m, индекс первого и последнего элемента в массиве
void qSort(int *m, int first, int last)
{
	int mid = m[(first + last) / 2]; //вычисление опорного элемента
	int f = first, l = last;
	do
	{
		while (m[f] < mid)
			f++;
		while (m[l] > mid)
			l--;
		if (f <= l) //перестановка элементов
		{
			swap(m[f], m[l]);
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) qSort(m, first, l);
	if (f < last) qSort(m, f, last);
}

//главная функция
int main()
{
	setlocale(LC_ALL, "Rus");

	const int n = 10; // кол-во элементов массива
	int *m = new int[n]; // выделение памяти для массива

	cout << "Исходный массив: ";
	for (int i = 0; i<n; i++)
	{
		m[i] = rand() % 10; // генерация массива
		cout << m[i] << " ";
	}

	int first = 0;
	int last = n - 1;

	qSort(m, first, last);

	cout << endl << "Результирующий массив: ";

	for (int i = 0; i < n; i++)
		cout << m[i] << " ";
	system ("pause");
	delete[]m; // очистка памяти

	return 0;
}