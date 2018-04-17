// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "algorithm"
#include "cstdlib" // ����������� ������������� ����� ��� ������������� rand()

using namespace std;

//������� ����������
// ��������� �� ���� ��������� �� ������ m, ������ ������� � ���������� �������� � �������
void qSort(int *m, int first, int last)
{
	int mid = m[(first + last) / 2]; //���������� �������� ��������
	int f = first, l = last;
	do
	{
		while (m[f] < mid)
			f++;
		while (m[l] > mid)
			l--;
		if (f <= l) //������������ ���������
		{
			swap(m[f], m[l]);
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) qSort(m, first, l);
	if (f < last) qSort(m, f, last);
}

//������� �������
int main()
{
	setlocale(LC_ALL, "Rus");

	const int n = 10; // ���-�� ��������� �������
	// ��������� ������ ��� �������
	int m[n] = { 1,5,3,2,4,7,8,1,5,6 };
	cout << "�������� ������: ";
	for (int i = 0; i<n; i++)
	{
		cout << m[i] << " ";
	}

	int first = 0;
	int last = n - 1;

	qSort(m, first, last);

	cout << endl << "�������������� ������: ";

	for (int i = 0; i < n; i++)
		cout << m[i] << " ";
	system("pause");

	return 0;
}