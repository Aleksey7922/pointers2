#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimetr "\n-------------------------------------------------------------------"

int** Allocate(const int rows, const int cols);   //�������� ������ ��� ���������� �������
void Clear(int** arr, const int rows);  //������� ��������� ������������ ������

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* arase(int* arr, int& n, int index);


int** push_row_back(int** arr, int& rows, const int cols);

int** push_row_front(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows,  int& cols);


//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void main()

{
	setlocale(LC_ALL, "");

#ifdef DINAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;

	// ������� ������������ ���c��:
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� �������� � ������ ������� :"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;

	cout << "������� ����������� �������� � ����� ������� :"; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;

	int index;
	/*cout << "������� ������ ������������ �������� :"; cin >> index;
	cout << "������� ����������� �������� :"; cin >> value;
	arr =insert (arr, n, value, index);
	Print(arr, n);
	cout << delimetr << endl; */

	cout << "������� ��������� ������� �������" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << delimetr << endl;

	cout << "�������  ������ ������� �������" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << delimetr << endl;

	cout << "������� ������ ���������� ��������:	"; cin >> index;
	arr = arase(arr, n, index);
	Print(arr, n);
	cout << delimetr << endl;

	delete[]arr;
#endif // DINAMIC_MEMORY_1

#ifdef DINAMIC_MEMORY_2
	int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ���������  �����: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "��������� ������ ������ � ����� �������" << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "��������� ������ ������ � ������ �������" << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimetr << endl;

	cout << "��������� ������ ������� � ����� �������" << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

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
	// 1)������� ������ 
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	// 2)������� ������ ���������� 
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
	// 1) �o����� �������� ������ ������� �������()
	int* buffer = new int[n + 1];
	// 2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) ������� �������� ������:
	delete[]arr;
	// 4) ��������� ����� ��������� ������� ������� ������ �������:
	arr = buffer;
	buffer = nullptr;//NULL -pointer(��������� �� 0)
	cout << typeid(nullptr).name() << endl;
	// 5) � ������ ����� ����� � ������ 'arr' ����� �������� ��������:
	arr[n] = value;
	// 6) ����� ���������� �������� � ������ ���������� ��� ��������� ������������� �� 1:
	n++;
	// 7) Mission complete - ������� ��������
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	//������� �������� ������ , �� ���� ����������� ������� ������ 
	int* buffer = new int[n + 1] {};
	// ���������� ����������� ��������� � ������ (�������) ������� ��������� ��������
	buffer[0] = value;
	//�������� �������� ������ � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//������� �������� �����
	delete[] arr;
	//� ����� ��������� ������� ���������� ����� ���������
	arr = buffer;
	//���������� ��� ��������� �� ���� ������,������� ��������� ������� ����������� ��������� �� ����,
	//��� ����� ��������� ������ ���� (�������� ) ������
	buffer = nullptr;
	n++;
	return arr;
}

int* insert(int* arr, int& n, int value, int index)
{
	//������� ������������ ������ �� ���� (�����������) ������� ������ 
	int* buffer = new int[n + 1];
	//�������� �������� ������ � �������� ������ �� ������� ������������ ��������
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//�������� �������� ������ � �������� ������� � ������� ������������ ��������
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//������� �������� ������ 
	delete[] arr;
	//�������� �������� ������ � ����������� ��������� � �������� ������
	arr = buffer;
	//����������� �������� � ��������� �������� ����������� ��������
	arr[index] = value;
	//����������� ������ �������
	n++;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	// ������� ������������ ������ �� ���� ������� ������
	int* buffer = new int[n - 1];
	//�������� �������� ������ � ��������
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	// ������� �������� ������
	delete[] arr;
	arr = buffer;
	//��������� ������
	n--;
	return arr;

	//int* buffer = new int[--n];
	//for (int i = 0; i < n; i++)byffer[i] = arr[i + 1];
	//delete[] arr;
	//return buffer;
}
int* pop_front(int* arr, int& n)
{
	// ������� ������������ ������ �� ���� ������� ������
	int* buffer = new int[n - 1];
	//�������� �������� ������ � ��������(�� � �������� �������� ,� �  �������)
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//������� �������� ������
	delete[] arr;
	// �������� �������� ������ � ��������� ������ ��������� � ��������
	arr = buffer;
	// ��������� ������
	n--;
	return arr;

	//int* buffer = new int[--n];
	//for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	//delete[] arr;
	//return buffer;
}
int* arase(int* arr, int& n, int index)
{
	// ������� ������������ ������ �� ���� ������� ������	
	int* buffer = new int[n - 1];
	//�������� �������� ������ � �������� ,�� �������
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//�������� �������� ������ � �������� ,����� �������
	for (int i = index + 1; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//������� �������� ������
	delete[] arr;
	arr = buffer;
	//arr[index];
	// ��� ������ � �������� ?
	return arr;
}


int** push_row_back(int** arr, int& rows, int const cols)
{
	// 1) ������� �������� ������ ���������� �� ���� �������(������) ������
	int** buffer = new int* [rows + 1];
	// 2) �������� ������ ����� �� ��������� ������� � ���������
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	// 3) ������� �������� ������ ����������
	delete[] arr;
	// 4) ��������� ����� �������� ������� ����������
	arr = buffer;
	// 5) ������� ����� ������
	arr[rows] = new int[cols] {};
	// 6) ����� ���������� ������ ����� ��������� ���������� ����� �������
	rows++;
	// 7) ���������� ����� ������
	return arr;
}
int** push_row_front(int** arr, int& rows, int const cols)
{
	// ������� �������� ������ ���������� �� 1 ������� (������) ������
	int** buffer = new int* [rows + 1];
	// ���������� ������ ������ � ������� ������� ��������� �������
	buffer[0] = 0;
	// �������� ������ ����� �� ��������� ������� � ��������
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	// ������� �������� ������ ����������
	delete[] arr;
	// ��������� ����� ��������� ������� ����������
	arr = buffer;
	// ������� ����� ������
	arr[rows] = new int[rows] {};
	// ����������� ���������� �����
	rows++;
	// ���������� ����� �������
	return arr;
} //???????????????????????

void push_col_back(int** arr, const int rows,  int& cols)
{
	// 1) ������� �������� ������
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		// 2) �������� �� �������� ������ � ��������
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) ������� �������� ������
		delete[] arr[i];
		// 4)���������� ����� ����� ������ � ������ ����������
		arr[i] = buffer;
	}
	cols++;
}
