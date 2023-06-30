//#include<iostream>
//using namespace std;
//using std::cin;
//using std::cout;
//using std::endl;
//
//#define delimetr "\n-------------------------------------------------------------------"
//
//int** Allocate(int const rows, int const cols);
//void Clear(int** arr, const int rows);
//
////void FillRand(int arr[], const int n);
////void FillRand(int** arr[], const int rows, const int cols);
//
//
////void Print(int arr[], const int n);
////void Print(int** arr[], const int rows, const int cols);
//
//int* push_back(int* arr, int& n, int value);
//int* push_front(int* arr, int& n, int value);
//int* insert(int* arr, int& n, int value, int index);
//
//int* pop_back(int* arr, int& n);
//int* pop_front(int* arr, int& n);
//int* arase(int* arr, int& n, int index);
//
//
//
////#define DINAMIC_MEMORY_1
//#define DINAMIC_MEMORY_2
//
//
//void main()
//
//{
//	setlocale(LC_ALL, "");
//
//#ifdef DINAMIC_MEMORY_1
//	int n;
//	cout << "Введите размер массива: "; cin >> n;
//
//	// создаем динамический масcив:
//	int* arr = new int[n];
//	FillRand(arr, n);
//	Print(arr, n);
//
//	int value;
//	cout << "введите добавляемое значение в конец массива :"; cin >> value;
//	arr = push_back(arr, n, value);
//	Print(arr, n);
//	cout << delimetr << endl;
//
//	cout << "введите добавляемое значение в начало массива :"; cin >> value;
//	arr = push_front(arr, n, value);
//	Print(arr, n);
//	cout << delimetr << endl;
//
//	int index;
//	cout << "введите индекс добавляемого элемента :"; cin >> index;
//	cout << "введите добавляемое значение :"; cin >> value;
//	arr = insert(arr, n, value, index);
//	Print(arr, n);
//	cout << delimetr << endl;
//
//	cout << "Удаляем последний элемент массива" << endl;
//	arr = pop_back(arr, n);
//	Print(arr, n);
//	cout << delimetr << endl;
//
//	cout << "Удаляем  первый элемент массива" << endl;
//	arr = pop_front(arr, n);
//	Print(arr, n);
//	cout << delimetr << endl;
//
//	cout << "Введите индекс удаляемого значения:	"; cin >> index;
//	arr = arase(arr, n, index);
//	Print(arr, n);
//	cout << delimetr << endl;
//
//	delete[]arr;
//#endif // DINAMIC_MEMORY_1
//
//	int rows, cols;
//	cout << "введите количество строк: "; cin >> rows;
//	cout << "введите количество элементов строки: "; cin >> cols;
//
//	int** arr = Allocate(rows, cols);
//	Clear(arr, rows);
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			arr[i][j] = rand() % 100;
//		}
//	}
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			cout << arr[i][j] << "\t";
//		}
//		cout << endl;
//	}
//
//
//	/*FillRand(arr, rows, cols);
//	Print(arr, rows, cols);*/
//
//}
//
//int** Allocate(int const rows, int const cols)
//{
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		arr[i] = new int[cols];
//	}
//	return arr;
//}
//void Clear(int** arr, const int rows)
//{
//	// 1)удаляем строки 
//	for (int i = 0; i < rows; i++)
//	{
//		delete[] arr[i];
//	}
//	// 2) удаляем массив указателей
//	delete[] arr;
//}
//
//void FillRand(int arr[], const int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		*(arr + i) = rand() % 100;
//	}
//}
////void FillRand(int** arr[], const int rows, const int cols)
////{
////	for (int i = 0; i < rows; i++)
////	{
////		for (int j = 0; j < cols; j++)
////		{
////			arr[i][j] = rand() % 100;
////		}
////	}
//
//void Print(int arr[], const int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << "\t";
//	}
//	cout << endl;
//}
////void Print(int** arr[], const int rows, const int cols)
////{
////	for (int i = 0; i < rows; i++)
////	{
////		for (int j = 0; j < cols; j++)
////		{
////			cout << arr[i][j] << "\t";
////		}
////		cout << endl;
////	}
////}
//
//
//int* push_back(int* arr, int& n, int value)
//{
//	// 1) Сщздаем буферный иассив нужного размера()
//	int* buffer = new int[n + 1];
//	// 2) Копируем все значения из исходного массива в буферный:
//	for (int i = 0; i < n; i++)
//	{
//		buffer[i] = arr[i];
//	}
//	// 3) удаляем исходный массив:
//	delete[]arr;
//	// 4) подменяем адрес исходного массива адресом нового массива:
//	arr = buffer;
//	buffer = nullptr;
//	cout << typeid(nullptr).name() << endl;
//	// 5) и только после этого в массив 'arr' можно добавить значение:
//
//	arr[n] = value; //NULL -pointer(указатель на 0)
//	// 6) После добавления элемента в массив количество его элементов увеличивается на 1:
//	n++;
//	// 7) Mission complete - элемент добавлен
//	return arr;
//}
//int* push_front(int* arr, int& n, int value)
//{
//	//создаем буферный массив , на один добавляемый элемент больше 
//	int* buffer = new int[n + 1] {};
//	// записываем добавляемое значениие в первый (нулевой) элемент буферного масссива
//	buffer[0] = value;
//	//копируем мсходный массив в буферный
//	for (int i = 0; i < n; i++)
//	{
//		buffer[i + 1] = arr[i];
//	}
//	//удаляем исходный масив
//	delete[] arr;
//	//в адрес исходного массива записываем адрес буферного
//	arr = buffer;
//	//получилось два указателя на один массив,поэтому буферному массиву присваиваем указатель на ноль,
//	//тем самым оставляем только один (исходный ) массив
//	buffer = nullptr;
//	n++;
//	return arr;
//}
//
//int* insert(int* arr, int& n, int value, int index)
//{
//	//создаем динамический массив на один (добавляемый) элемент больше 
//	int* buffer = new int[n + 1];
//	//копируем исходный массив в буферный массив до индекса добавляемого значения
//	for (int i = 0; i < index; i++)
//	{
//		buffer[i] = arr[i];
//	}
//	//копируем исходный массив в буферный начиная с индекса добавляемого значения
//	for (int i = index; i < n; i++)
//	{
//		buffer[i + 1] = arr[i];
//	}
//	//удаляем исходный массив 
//	delete[] arr;
//	//копируем буферный массив с добавленным элементом в исходный массив
//	arr = buffer;
//	//присваиваем элементу с указанным индексом добавляемое значение
//	arr[index] = value;
//	//увеличиваем размер массива
//	n++;
//	return arr;
//}
//int* pop_back(int* arr, int& n)
//{
//	// создаем динамический массив на один элемент меньше
//	int* buffer = new int[n - 1];
//	//копируем исходный массив в буферный
//	for (int i = 0; i < n - 1; i++)
//	{
//		buffer[i] = arr[i];
//	}
//	// удаляем исходный массив
//	delete[] arr;
//	arr = buffer;
//	//уменьшаем массив
//	n--;
//	return arr;
//
//	//int* buffer = new int[--n];
//	//for (int i = 0; i < n; i++)byffer[i] = arr[i + 1];
//	//delete[] arr;
//	//return buffer;
//}
//int* pop_front(int* arr, int& n)
//{
//	// создаем динамический массив на один элемент меньше
//	int* buffer = new int[n - 1];
//	//копируем исходный массив в буферный(не с НУЛЕВОГО элемента ,а с  ПЕРВОГО)
//	for (int i = 0; i < n; i++)
//	{
//		buffer[i] = arr[i + 1];
//	}
//	//удаляем исходный массив
//	delete[] arr;
//	// копируем буферный массив с удаленным первым элементом в исходный
//	arr = buffer;
//	// уменьшаем массив
//	n--;
//	return arr;
//
//	//int* buffer = new int[--n];
//	//for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
//	//delete[] arr;
//	//return buffer;
//}
//int* arase(int* arr, int& n, int index)
//{
//	// создаем динамический массив на один элемент меньше	
//	int* buffer = new int[n] {};
//	//копируем исходный массив в буферный ,до индекса
//	for (int i = 0; i < index; i++)
//	{
//		buffer[i] = arr[i];
//	}
//	//копируем исходный массив в буферный ,после индекса
//	for (int i = index; i < n; i++)
//	{
//		buffer[i] = arr[i + 1];
//	}
//	//удаляем исходный массив
//	delete[] arr;
//	arr = buffer;
//	n--;
//	return arr;
//}


#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimetr "\n-------------------------------------------------------------------"

int** Allocate(const int rows, const int cols);   //выделяем память для двумерного массива
void Clear(int** arr, const int rows);  //удаляем двумерный динамический массив

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert_row(int* arr, int n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* arase(int* arr, int& n, int index);


int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, const int index);// ?????? не работает

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, const int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
//void insert_col(int** arr, const int rows, int& cols, const int index); // не получается???????

void pop_col_back(int** arr, const int rows, int& cols);

//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void main()

{
	setlocale(LC_ALL, "");

#ifdef DINAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;

	// создаем динамический масcив:
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "введите добавляемое значение в начало массива :"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;

	cout << "введите добавляемое значение в конец массива :"; cin >> value;
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
#endif // DINAMIC_MEMORY_1

#ifdef DINAMIC_MEMORY_2
	int rows, cols;
	cout << "введите количество строк: "; cin >> rows;
	cout << "введите количество элементов  строк: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "добавляем пустую строку в конец массива" << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "добавляем пустую строку в начало массива" << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	int index = 0;
	/*cout << "введите индекс добавляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimetr;*/

	cout << "удаляем последнюю строку массива" << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "удаляем нулевую строку" << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "добавляем пустой столбец в конец массива" << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "добавляем пустой столбец в начало массива" << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	//cout << "введите индекс добавляемого столбца:	"; cin >> index;
	//insert_col(arr, rows, cols,index);
	//Print(arr, rows, cols);
	//cout << delimetr << endl;

	cout << "удаляем столбец с конца массива" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	Clear(arr, rows);


#endif // DINAMIC_MEMORY_2

}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	// 1)удаляем строки 
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	// 2)удаляем массив указателей 
	delete[] arr;
}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";

		}
		cout << endl;
	}
}

int* push_back(int* arr, int& n, int value)
{
	// 1) Сoздаем буферный массив нужного размера()
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
	buffer = nullptr;//NULL -pointer(указатель на 0)
	cout << typeid(nullptr).name() << endl;
	// 5) и только после этого в массив 'arr' можно добавить значение:
	arr[n] = value;
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
	return arr;
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
	int* buffer = new int[n - 1];
	//копируем исходный массив в буферный ,до индекса
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//копируем исходный массив в буферный ,после индекса
	for (int i = index + 1; i < n; i++)
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


int** push_row_back(int** arr, int& rows, int const cols)
{
	// 1) создаем буферный массив указателей на один элемент(строку) больше
	int** buffer = new int* [rows + 1];
	// 2) копируем адреса строк из исходного массива в буфферный
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	// 3) удаляем исходный массив указателей
	delete[] arr;
	// 4) подменяем адрес иходного массива указателей
	arr = buffer;
	// 5) создаем новую строку
	arr[rows] = new int[cols] {};
	// 6) после добавления строки нужно увеличить количество строк массива
	rows++;
	// 7) возвращаем новый массив
	return arr;
}
int** push_row_front(int** arr, int& rows, int const cols)
{
	// создаем буферный массив указателей на 1 элемент (строку) больше
	int** buffer = new int* [rows + 1];

	// копируем адреса строк из исходного массива в буферный
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	// удаляем исходный массив указателей
	delete[] arr;
	// подменяем адрес исходного массива указателей
	arr = buffer;
	// создаем новую строку
	arr[0] = new int[cols] {};
	// увеличиваем количество строк
	rows++;
	// возвращаем новый масссив
	return arr;
}
//int** insert_row(int** arr, int& rows, const int cols, int const index)
//{
//	1) создаем буферный массив на один элемент больше
//	int** buffer = new int* [rows + 1];
//	2) копируем элементы в новый массив до индекса
//	for (int i = 0; i < index; i++)buffer[i] = arr[i];
//	3)копируем элементы начиная с индекса,массив становится на один элемент больше
//	for (int i = index; i < rows; i++)buffer[i] = arr[i];
//	5) удаляем исходный массив
//	delete[] arr;
//	arr = buffer;
//	arr[index] = new int[cols] {};
//	rows++;
//	return arr;
//	????????????????????????????????????????????????????????????????????????/не работает
//}


int** pop_row_back(int** arr, int& rows, const int cols)
{

	//1) удаляем удаляемую строку
	delete[] arr[rows - 1];
	//2) создаем буферный массив
	int** buffer = new int* [--rows];
	//3) копируем адреса строк в новый массив
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//4)удаляем исходный массив указателей
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	//1)создаем буферный массив
	int** buffer = new int* [--rows];
	//2)копируем адреса в новый массив
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	//3) удаляем исходный массив
	delete[] arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, const int index)
{
	//1) создаем буферный массив на один элемент меньше
	int** buffer = new int* [rows - 1];
	//2) копируем элементы до индекса
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//3) копируем элементы после индекса.при этом уменьшаем массив на одну строку
	for (int i = index; i < rows - 1; i++)buffer[i] = arr[i + 1];
	//4) удаляем исходный массив
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	// 1) создаем буферную строку
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		// 2) копируем из исходной строки в буферную
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) удаляем исходную строку
		delete[] arr[i];
		// 4)записываем адрес новой строки в массив указателей
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	//1) создаем буферный массив 
	int* byffer = new int[rows + 1] {};
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		//2) копируем из исходной строки в буфферную
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		//3)удаляем исходную строку
		delete[] arr[i];
		//4) записываем адрес новой строки в массив указателей
		arr[i] = buffer;
	}
	cols++;
}
//void insert_col(int** arr, const int rows, int& cols, const int index)
//{
//	//1) создаем беферный массив 
//	int* buffer = new int [cols + 1] {};
//	//2) копируем из исходной строки в буферную
//	for (int i = 0; i < rows; i++)
//	{
//		int* buffer = new int[cols + 1];
//	}
//		//3) копируем до индекса	
//	for (int j = 0; j < index; j++)
//	{
//		buffer[j] = arr[j];
//	}
// 
//	
//}

void pop_col_back(int** arr, const int rows, int& cols)
{
	//int* buffer = new int [rows];
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
		
	}
				
}

