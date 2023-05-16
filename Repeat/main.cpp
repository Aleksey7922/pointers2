#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimetr "\n-------------------------------------------------------------------"

//#define POINTERS
//#define SPLIT
//


void FillRand(int* arr, const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, int &n, int value);
int* front_back(int* arr, int &n, int value);
int* insert(int* arr, int& n, int value, int index);

void main()
{

	setlocale(LC_ALL, "rus");

#ifdef POINTERS
	const int a = 5;
	int arrr[a]{ 1,2,3,4,5, };
	for (int i = 0; i < a; i++)
	{
		cout << *(arrr + i) << "\t";
	}
	cout << endl;
#endif // 
#ifdef SPLIT

	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	// 1)вычисляем размер массивов:
	int even_counter = 0;
	int odd_counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_counter++;
		else odd_counter++;
	}

	// 2) выделяем память для динамических массивов:
	int* even_arr = new int[even_counter];
	int* odd_arr = new int[odd_counter];

	// 3) копируем значения в сооветствующие массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i];
	}

	Print(even_arr, even_counter);
	Print(odd_arr, odd_counter);

	delete[]even_arr;
	delete[]odd_arr;

#endif // SPLIT

	/*const int n = 5;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	int value = 0;
	cout << "введите добавляемое значение: "; cin >> value;*/

	 
	int n;
	cout << "Введите размер массива: "; cin >> n;
	//создаем динамический массив
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение в конец массива:  "; cin >> value;
	arr=push_back(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;
	cout << "Введите добавляемое значение в начало массива: "; cin >> value;
	arr = front_back(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;
	/*int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[n] = value;
	n++;
	Print(arr, n);


	delete[] arr;
*/

}
void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr+i) = rand() % 100;
	}
	cout << endl;
}
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
//
//void FillRand(int arr[], const int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		*(arr + i) = rand() % 100;
//	}
//}
//void Print(int arr[], const int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << "\t";
//	}
//	cout << endl;
//}
//

int* push_back(int* arr,  int &n, int value)
{
	//создаем буферный массив
	int* buffer = new int[n + 1];
	//копируем исходный массив в буферный массив
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//удаляем исходный массив
	delete[] arr;
	//в адрес исходного массива записываем адрес буферного массива
	arr = buffer;
	//получилось два указателя на один массив,поэтому буферному массиву присваиваем указатель на ноль,
	//тем самым оставляем только один (исходный ) массив
	buffer = nullptr;
	//и только после  этого добавляем значение в конец массива
	arr[n] = value;
	n++;
	return arr;
}
int* front_back(int* arr, int &n, int value)
{
	//создаем буферный массив , на один добавляемый элемент больше 
	int* buffer = new int[n + 1]{};
	// записываем добавляемое значениие в первый (нулевой) элемент буферного масссива
	buffer[0] = value;
	//копируем мсходный массив в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
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
	//копируем исходный массив в буферный массив
	for (int i = 0; i < n; i++)???????????
	{
		buffer[i] = arr[i];
	}
}

