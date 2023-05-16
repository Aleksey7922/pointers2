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
	// 1)��������� ������ ��������:
	int even_counter = 0;
	int odd_counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_counter++;
		else odd_counter++;
	}

	// 2) �������� ������ ��� ������������ ��������:
	int* even_arr = new int[even_counter];
	int* odd_arr = new int[odd_counter];

	// 3) �������� �������� � �������������� �������:
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
	cout << "������� ����������� ��������: "; cin >> value;*/

	 
	int n;
	cout << "������� ������ �������: "; cin >> n;
	//������� ������������ ������
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� �������� � ����� �������:  "; cin >> value;
	arr=push_back(arr, n, value);
	Print(arr, n);
	cout << delimetr << endl;
	cout << "������� ����������� �������� � ������ �������: "; cin >> value;
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
	//������� �������� ������
	int* buffer = new int[n + 1];
	//�������� �������� ������ � �������� ������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//������� �������� ������
	delete[] arr;
	//� ����� ��������� ������� ���������� ����� ��������� �������
	arr = buffer;
	//���������� ��� ��������� �� ���� ������,������� ��������� ������� ����������� ��������� �� ����,
	//��� ����� ��������� ������ ���� (�������� ) ������
	buffer = nullptr;
	//� ������ �����  ����� ��������� �������� � ����� �������
	arr[n] = value;
	n++;
	return arr;
}
int* front_back(int* arr, int &n, int value)
{
	//������� �������� ������ , �� ���� ����������� ������� ������ 
	int* buffer = new int[n + 1]{};
	// ���������� ����������� ��������� � ������ (�������) ������� ��������� ��������
	buffer[0] = value;
	//�������� �������� ������ � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
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
	//�������� �������� ������ � �������� ������
	for (int i = 0; i < n; i++)???????????
	{
		buffer[i] = arr[i];
	}
}

