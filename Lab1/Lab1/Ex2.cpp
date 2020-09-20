#include<iostream>
#include<iomanip>
using namespace std;

//Криворучко Ксения, ИВТ-2, 4 вариант

/*Написать программу, которая преобразует одномерный массив (1D) в двумерный (2D)
(или наоборот), в соответствии с вариантом. Необходимо оформить в отдельных
функциях код следующих действий: 1) инициализация массива; 2) вывод массива; 3)
преобразование массива (создание нового массива с другой структурой). Память под
массивы выделять динамически и для доступа к элементам использовать указатели.
Ввод-вывод данных организовать средствами iostream и iomanip.*/

/*Преобразование: 2D → 1D. Двумерный массив 5х3 вещественных чисел необходимо
выложить в один ряд по элементам слева направо и снизу вверх.
Инициализация: заполнить массив числами x[i][j] = sin(i–j) + cos(i+j).
Вывод на экран: на каждый элемент массива отвести 14 позиций.
[ 1 -0.3012 -1.325
 1.382 -0.4161 -1.831
 0.4932 -0.1485 -0.6536
 -0.8489 0.2557 1.125
 -1.41 0.4248 1.869 ]
=>
[ -1.41 0.4248 1.869 -0.8489 0.2557 1.125 0.4932 -0.1485 -0.6536 1.382
 -0.4161 -1.831 1 -0.3012 -1.325 ]*/

//прототип функции инициализации массива
void initializeArray(double** arr, size_t rows, size_t cols);

//прототип функции вывода двумерного массива
void printArray2D(double** arr, size_t rows, size_t cols);

//прототип функции вывода одномерного массива
void printArray1D(double* arr, size_t n);

//прототип функции преобразования массива
double* makeArray1D(double** arr, size_t rows, size_t cols);

//прототип функции освобождения памяти после одномерного массива
void freeArray1D(double* arr);

//прототип функции освобождения памяти после двумерного массива
void freeArray2D(double** arr, size_t rows);


int main()
{
	const size_t rows = 5;
	const size_t cols = 3;
	const size_t n = 15;

	//создание двумерного массива вещественных чисел
	double** arr2D = new double* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(arr2D + i) = new double[cols];
	}

	initializeArray(arr2D, rows, cols);
	printArray2D(arr2D, rows, cols);

	double* arr1D = makeArray1D(arr2D, rows, cols);
	printArray1D(arr1D, n);

	//очистка динамической памяти
	freeArray1D(arr1D);
	freeArray2D(arr2D, rows);
}

//заполнение массива элементами  x[i][j] = sin(i–j) + cos(i+j)
void initializeArray(double** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			*(*(arr + i) + j) = sin(i - j) + cos(i + j);      
		}
	}
}

//вывод двумерного массива
void printArray2D(double** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << setw(14) << *(*(arr + i) + j);
		}
		cout << endl;
	}
	cout << endl;
}

//создание одномерного массива из двумерного слева направо снизу вверх
double* makeArray1D(double** arr, size_t rows, size_t cols)
{
	size_t k = 0;
	double* arr1D = new double[rows * cols];
	for (int i = rows - 1; i >= 0; i--)
	{
		for (size_t j = 0; j < cols; j++)
		{
			arr1D[k] = *(*(arr + i) + j);
			k++;
		}
	}
	return arr1D;
}

//вывод одномерного массива 
void printArray1D(double* arr, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << *(arr + i) << setw(14);
	}
	cout << endl;
}

//очистка памяти после одномерного массива
void freeArray1D(double* arr)
{
	delete[] arr;
}

//очистка памяти псоле двумерного массива
void freeArray2D(double** arr, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete [] *(arr + i);
	}
	delete[] arr;
}