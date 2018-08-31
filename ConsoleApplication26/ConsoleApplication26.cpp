// ConsoleApplication26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//1.	Написать функцию, которая получает указатель на массив и его размер, и возвращает сумму и произведение его элементов в двух параметрах-указателях.

void sp(int *a, int size) {
	int *p;
	int sum =0, pr = 1;
	for ( p = a; p < a + size; p++)
	{
		sum += *p;
		pr *= *p;
	}
	cout << "sum = " << sum << "\tproizvedenie = " << pr << endl;
}

//2.	Написать функцию, которая получает указатель на массив и его размер, и возвращает количество отрицательных, положительных и нулевых элементов массива.
void opn(int *a, int size) {
	int *p;
	int o = 0, po = 0, n = 0;
	for ( p = a	; p < a + size; p++)
	{
		if (*p < 0) o++; else if (*p>0) po++; else n++;
		
	}
	cout << "polojitel'nyh = " << po << "\noticatel'nyh = " << o << "\nnylevyh = " << n <<endl;
}

//3.	Написать следующие функции для работы с динамическим массивом:
//a.функция распределения динамической памяти
void alloc(int *&arr, int n)
{
	arr = new int[n];
}
//b.функция инициализации динамического массива
void init(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}
//c.функция печати динамического массива
void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//d.функцию удаления динамического массива
void erase(int *&arr)
{
	delete[] arr;
}
//e. функцию добавления элемента в конец массива
void insert_end(int *&arr, int &n, int value)
{
	int *tmp = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[n] = value;
	n += 1;
	delete[]arr;
	arr = tmp;

}
//f. функцию вставки элемента по указанному индексу
void addNumber(int *&arr, int &n, int index, int number)
{
	int *tmp1 = new int[++n];
	for (int i = 0; i < index; ++i)
		tmp1[i] = arr[i];
	tmp1[index] = number;
	for (int i = index; i < n - 1; ++i)
		tmp1[i + 1] = arr[i];
	delete[]arr;
	arr = tmp1;
}
//g. функцию удаления элемента по указанному индексу
bool DelNum(int *arr, int &n, int nom)
{
	if (nom > n || nom < 1)
	{
		cout << "Ошибка удаления" << endl;
		return false;
	}

	for (int i = nom - 1; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return true;
}



//4.	Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все отрицательные числа и вернуть указатель на новый динамический массив.
void dinA(int *&a, int &n)
{
	int *tmp;
	int k = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			k++;
		}
	}
	tmp = new int[k];
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
			tmp[j++] = a[i];
	}
	delete[] a;
	a = tmp;
	n = k;
}



int main()
{
	//1.
	const int size = 5 ;
	int a[size];
	int s = 0, m = 1;

	for (int i = 0; i < size; i++)
	{
		a[i] = 1 + rand() % 5;
		cout <<  *(a + i) << " ";
	}
	cout << endl;

	sp(a, size);

	//2. 
	const int size2 = 9;
	int b[size2] = { 0,2,3,-4,-5,-6,0,0,0 };

	for (int i = 0; i < size2; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	opn(b, size2);

	//3.
	int *ar;
	int size3 = 5;
	alloc(ar, size3);
	init(ar, size3);
	print(ar, size3);
	insert_end(ar, size3, 10);
	print(ar, size3);
	addNumber(ar, size3, 3, 89);
	print(ar, size3);
	DelNum(ar, size3, 2);
	print(ar, size3);
	erase(ar);

	//4.
	int *br;
	int size4;
	cout << "array size = ";
	cin >> size4;
	br = new int[size4];
	for (int i = 0; i < size4; i++)
	{
		br[i] = rand() % 10 - 5;
		cout << br[i] << " ";
	}
	cout << endl;
	dinA(br, size4);
	for (int i = 0; i < size4; i++)
	{
		cout << br[i] << " ";
	}
	cout << endl;
	delete[] br;

	//5.
	int *a1;
	int *b1;
	int *c1;

	int M, N;

	cout << "M = ";
	cin >> M;
	cout << "N = ";
	cin >> N;

	int k = M + N;

	a1 = new int[M];
	b1 = new int[N];
	c1 = new int[k];

	for (int i = 0; i < M; i++)
	{
		a1[i] = 1 + rand() % 20;
		c1[i] = a1[i];
		cout << a1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		b1[i] = 1 + rand() % 20;
		c1[i + M] = b1[i];
		cout << b1[i] << " ";
	}
	cout << endl;
	cout << endl;

	for (int i = 0; i < k; i++)
	{
		cout << c1[i] << " ";
	}
	cout << endl;

	delete[] a1;
	delete[] b1;
	delete[] c1;

    return 0;
}

