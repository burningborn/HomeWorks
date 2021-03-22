#include<iostream>
using namespace std;

#define tab  "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int n, int value);
int* push_front(int arr[], int n, int value);
int* insert(int arr[], int n, int value);
int* pop_back(int arr[], int n);
int* pop_front(int arr[], int n);
int* erase(int arr[], int n, int value);



void main()
{
	setlocale(LC_ALL, "Rus");
	int n = 5;
	//cout << "Введите размер массива:  "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	cout << " Начальный массив для работы:                "; Print(arr, n);
	cout << " Каждое последующее действие будет проводиться с предшествующим ему (действию) массивом!!! \n"; 

	int value = 0; //Добавляемое значение
	cout << " Введите добавляемое значение:  "; cin >> value;
	arr = push_back(arr, n, value);
	n++;
	cout << " Массив с добавленным  последним элементом:  "; Print(arr, n); 
	arr = push_front(arr, n, value);
	n++;
	cout << " Массив  с  добавленным  первым  элементом:  "; Print(arr, n);
	arr = insert(arr, n, value);
	n++;
	cout << " Массив с вставленным по индексу значением:  "; Print(arr, n);
	arr = pop_back(arr, n);
	n--;
	cout << " Массив  с  удалённым  последним элементом:  "; Print(arr, n);
	arr = pop_front(arr, n);
	n--;
	cout << " Массив   с   удалённым  первым  элементом:  "; Print(arr, n);
	arr = erase(arr, n, value);
	n--;
	cout << " Массив с  удалённым по индексу  элементом:  "; Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	cout << tab;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

int* push_back(int arr[], int n, int value)
{
	int* buffer = new int[n + 1]{}; //1)Создаём новый (буферный) массив нужного размера
	for (int i = 0; i < n; i++)     //2)Копируем все значения из исходного массива в буферный:
	{
		buffer[i] = arr[i];
	}
	delete[] arr;                   //3)После того как данные скопированы исходный массив можно удалить:
	arr = buffer;                   //4)ПОдменяем адрес в указателе на исходный массив:
	arr[n] = value;                //5)И только после всего этого можно дописать новое значение в КОНЕЦ массива: 
	return arr;
}

int* push_front(int arr[], int n, int value)
{
	int* buffer = new int[n + 1]{}; //1)Создаём новый (буферный) массив нужного размера
	for (int i = 0; i < n; i++)     //2)Копируем все значения из исходного массива в буферный начиная со ВТОРОГО элемента нового массива:
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;                   //3)После того как данные скопированы исходный массив можно удалить:
	arr = buffer;                   //4)ПОдменяем адрес в указателе на исходный массив:
	arr[0] = value;                //5)И только после всего этого можно дописать новое значение в НАЧАЛО массива: 
	return arr;
}

int* insert(int arr[], int n, int value)
{
	
	int* buffer = new int[n + 1]{}; //Создаём новый (буферный) массив нужного размера:
	int x = 0;                      //Создаём переменную для приёма индекса элемента массива:
	cout << " Выберите индекс элемента от 0 до " << n - 1 << " "; cin >> x; //Принимаем индекса элемента массива:
	for (int i = 0; i < n; i++)     //Копируем все значения из исходного массива в буферный массив:
	{
		if (i < x)
			buffer[i] = arr[i];
		else
			buffer[i + 1] = arr[i];
	}
	delete[] arr;                   //После того как данные скопированы исходный массив можно удалить:
	arr = buffer;                   //ПОдменяем адрес в указателе на исходный массив:
	arr[x] = value;                //И только после всего этого можно дописать новое значение в выбраный элемент массива массива: 
	return arr;
}

int* pop_back(int arr[], int n)
{
	int* buffer = new int[n - 1]{};     //1)Создаём новый (буферный) массив нужного размера
	for (int i = 0; i < n - 1; i++)     //2)Копируем все значения из исходного массива в буферный:
	{
		buffer[i] = arr[i];
	}
	delete[] arr;                        //3)После того как данные скопированы исходный массив можно удалить:
	arr = buffer;                        //4)ПОдменяем адрес в указателе на исходный массив:	
	return arr;
}

int* pop_front(int arr[], int n)
{
	int* buffer = new int[n - 1]{};     //1)Создаём новый (буферный) массив нужного размера
	for (int i = 0; i < n - 1; i++)     //2)Копируем все значения из исходного массива (НАЧИНАЯ СО ВТОРОГО ЭЛЕМЕНТА) в буферный:
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;                       //3)После того как данные скопированы исходный массив можно удалить:
	arr = buffer;                       //4)ПОдменяем адрес в указателе на исходный массив:
	return arr;
}

int* erase(int arr[], int n, int value)
{
	int* buffer = new int[n + 1]{}; //Создаём новый (буферный) массив нужного размера:
	int x = 0;                      //Создаём переменную для приёма индекса элемента массива:
	cout << " Выберите индекс элемента от 0 до " << n - 1 << " "; cin >> x; //Принимаем индекса элемента массива:
	for (int i = 0; i < n; i++)     //Копируем все (КРОМЕ ВЫБРАННОГО!!!) значения из исходного массива в буферный массив:
	{
		if (i < x)
			buffer[i] = arr[i];
		else
			buffer[i] = arr[i + 1];
	}
	delete[] arr;                   //После того как данные скопированы исходный массив можно удалить:
	arr = buffer;                   //ПОдменяем адрес в указателе на исходный массив:
	return arr;
}