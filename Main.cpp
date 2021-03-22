#include <iostream>
using namespace std;
/*
	������ ������������ ������� ����� ���� ����� ������ ������������� ����������� ���������, �
������ �� ����� ��������� ����. ������ ������������ ������� ���������� �������� ����� ����������.
	������ ������������� ������� ����� ���� ����� ���������� ���������, �� ����� ���������� ���������.
��������������, ��� ���������� �������� ����� ���������, ���� ������ � ����������.
	��� ���� ��� �� �������� ������������ ������ ����� ��������� ���������, � ��������
������ ��� ������ ��������� NEW. �������� NEW �������� ������ ��� N ��������� ��������� ����
(� ������ ������ int) � ���������� ����� ���������� ������. ���� ����� �� � ���������� � ���
���������. �������� NEW ����� �������� ����������� ���� ������.
-----------------------------------------------------------------------------------------------------
						��������� 
	���������� � ��������� ������������� ����� ����� ��� �� ��� � ��������� ������������ �������, �.�. 
��������� ���������� ���������� � �������� ������������� ��� �� ����� �������� ��������������.
� � ��� � � ������ ������ ������ � ��������� ������� ��������������� �� ����������� �����, ��������� 
�������� � �������� ��������.
-----------------------------------------------------------------------------------------------------
						�������� ������������� ������� � �������

������������ ������ ����� �������� � ������� ����� ��� �� ��� � �����������.
-----------------------------------------------------------------------------------------------------

����� ���� ��� ������������ ������ ��� �� �����, ��� ����� �������, ��� �� ����������� ������  
������� �� �������, ��� �� ��� ������ ����� ���� ������������. ��� �������� ������������� ������� 

-----------------------------------------------------------------------------------------------------
Stack (������)- ��� ������ ������, �� ������� ��������� ���������� ������� ����������� ���������.
Heap (����) - ��� ������������ ������, ��������� ������ ����������� �������.
-----------------------------------------------------------------------------------------------------
�������� NEW ���������� ����������� ������ ������ � ������������ �������. � ���� � �� ���� ����������� 
���� ������ ������� �������, �� ��� ��� ��������. � ��������� ������ ��������� ����������. ����� ����
��� �� �������������� ������� � ����� ������� ������������ �������. ������ ��� � ������ �������� DELETE.
�������� DELETE ����������� ������ �� ���������� ������ � ��������� �� ���� �� ������ � ����������.
-----------------------------------------------------------------------------------------------------
���� ������ �������� ������ � �������� � �� ����������� �� ���� ��� ������ ��������� ����������� ������ 
� �� ����������, � ��� � ���� ������� ���������� ������ ������ ����������. �� ������� �������� ��� ������!!!
-----------------------------------------------------------------------------------------------------
*/
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << " ������� ������ �������: "; cin >> n;
	//1) ���������� ������������� �������
	int* arr = new int[n] {};
	//2) ������������� ������������� �������
	Print(arr, n);
	FillRand(arr, n);
	Print(arr, n);
	//3) �������� ������������� �������
	delete[] arr;
	cout << " Tat`s okey!!-)" << endl;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//������ � ��������� ������� ����� ���������� � �������� �������������.
		*(arr + i) = rand();
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}