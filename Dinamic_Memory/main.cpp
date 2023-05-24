﻿#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimetr "\n-------------------------------------------------------------------"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* arase(int* arr, int& n, int index);




void main()

{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;

	// создаем динамический масcив:
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "введите добавляемое значение в конец массива :"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;

	cout << "введите добавляемое значение в начало массива :"; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;

	int index;
	/*cout << "введите индекс добавляемого элемента :"; cin >> index;
	cout << "введите добавляемое значение :"; cin >> value;
	arr =insert (arr, n, value, index);
	Print(arr, n);
	cout << delimetr << endl; */

	cout << "Удаляем последний элемент массива" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << delimetr << endl;

	cout << "Удаляем  первый элемент массива" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << delimetr << endl;

	cout << "Введите индекс удаляемого значения:	"; cin >> index;
	arr = arase(arr, n, index);
	Print(arr, n);
	cout << delimetr << endl;

	delete[]arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}


void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}


int* push_back(int* arr, int& n, int value)
{
	// 1) Сщздаем буферный иассив нужного размера()
	int* buffer = new int[n + 1];
	// 2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) удаляем исходный массив:
	delete[]arr;
	// 4) подменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	buffer = nullptr;
	cout << typeid(nullptr).name() << endl;
	// 5) и только после этого в массив 'arr' можно добавить значение:

	arr[n] = value; //NULL -pointer(указатель на 0)
	// 6) После добавления элемента в массив количество его элементов увеличивается на 1:
	n++;
	// 7) Mission complete - элемент добавлен
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	//создаем буферный массив , на один добавляемый элемент больше 
	int* buffer = new int[n + 1] {};
	// записываем добавляемое значениие в первый (нулевой) элемент буферного масссива
	buffer[0] = value;
	//копируем мсходный массив в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//удаляем исходный масив
	delete[] arr;
	//в адрес исходного массива записываем адрес буферного
	arr = buffer;
	//получилось два указателя на один массив,поэтому буферному массиву присваиваем указатель на ноль,
	//тем самым оставляем только один (исходный ) массив
	buffer = nullptr;
	n++;
	return arr;
}

int* insert(int* arr, int& n, int value, int index)
{
	//создаем динамический массив на один (добавляемый) элемент больше 
	int* buffer = new int[n + 1];
	//копируем исходный массив в буферный массив до индекса добавляемого значения
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//копируем исходный массив в буферный начиная с индекса добавляемого значения
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//удаляем исходный массив 
	delete[] arr;
	//копируем буферный массив с добавленным элементом в исходный массив
	arr = buffer;
	//присваиваем элементу с указанным индексом добавляемое значение
	arr[index] = value;
	//увеличиваем размер массива
	n++;
	return arr; //что делать с индексом?????????????????????????????????
}
int* pop_back(int* arr, int& n)
{
	// создаем динамический массив на один элемент меньше
	int* buffer = new int[n - 1];
	//копируем исходный массив в буферный
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	// удаляем исходный массив
	delete[] arr;
	arr = buffer;
	//уменьшаем массив
	n--;
	return arr;

	//int* buffer = new int[--n];
	//for (int i = 0; i < n; i++)byffer[i] = arr[i + 1];
	//delete[] arr;
	//return buffer;
}
int* pop_front(int* arr, int& n)
{
	// создаем динамический массив на один элемент меньше
	int* buffer = new int[n - 1];
	//копируем исходный массив в буферный(не с НУЛЕВОГО элемента ,а с  ПЕРВОГО)
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//удаляем исходный массив
	delete[] arr;
	// копируем буферный массив с удаленным первым элементом в исходный
	arr = buffer;
	// уменьшаем массив
	n--;
	return arr;

	//int* buffer = new int[--n];
	//for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	//delete[] arr;
	//return buffer;
}
int* arase(int* arr, int& n, int index)
{
	// создаем динамический массив на один элемент меньше	
	int* buffer = new int[n] {};
	//копируем исходный массив в буферный ,до индекса
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//копируем исходный массив в буферный ,после индекса
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	//удаляем исходный массив
	delete[] arr;
	arr = buffer;
	n--;
	
	//arr[index];
	// что делать с индексом ?????????????????????????????????????????/
	return arr;
}