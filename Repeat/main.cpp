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
int* push_front(int* arr, int &n, int value);
int* insert(int* arr, int& n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* arase(int* arr, int& n,int index);

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
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;

	int index;
	cout << "Введите добавляемое  в индекс  массива значение: "; cin >> value;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << delimetr << endl;
	
	cout << "Удаляем последний элемент массива" << endl;
	arr=pop_back(arr, n);
	Print(arr, n);
	cout << delimetr << endl;

	cout << "Удаляем  первый элемент массива" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << delimetr << endl;

	
	cout << "Введите индекс удаляемого значения:	"; cin>> index;
	arr = arase(arr, n, index);
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
int* push_front(int* arr, int &n, int value)
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
	return arr;
}
int* pop_back(int* arr, int& n)
{
	// создаем динамический массив на один элемент меньше
	int* buffer = new int[n-1];
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

}
int* arase(int* arr, int& n,int index)
{	
	// создаем динамический массив на один элемент меньше	
	int* buffer = new int[n-1];
	//копируем исходный массив в буферный ,до индекса
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//копируем исходный массив в буферный ,после индекса
	for (int i = index+1; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//удаляем исходный массив
	delete[] arr;
	arr = buffer;
	//arr[index];
	// что делать с индексом ?
	return arr;
}


