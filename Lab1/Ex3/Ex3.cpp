#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


//Криворучко Ксения, ИВТ-2, 4 вариант

/*Написать свой аналог стандартной функции обработки строк из файла cstring, в
соответствии с вариантом. В функции main на тестовых данных продемонстрировать
результат работы как стандартной функции, так и собственной версии. Ввод-вывод
данных организовать средствами cstdio.*/

/*Функция strncat.
Формат char* strncat(char* dest, const char* src, size_t maxlen).
Функция приписывает maxlen символов строки src к строке dest*/

//прототип функции strncatMy
char* strncatMy(char* dest, const char* src, size_t maxlen);

int main()
{
	setlocale(LC_ALL, "Rus");
	const size_t size = 120;
	char dest[size] = "физико-технический";
	char src[size] = " факультет";
    
	printf( "Введите количество символов, которые надо приписать к строке:\n");
	size_t maxlen = getchar();
	printf("\n");

	printf( "Использование личной функции strncat:\n");
	strncatMy(dest, src, maxlen);
	printf(dest);
	printf("\n\n");

	printf("Использование встроенной функции strncat:\n");
	strncat(dest, src, maxlen);
	printf( dest );
	printf("\n\n");

}

// своя функция strncatMy, приписывающая maxlen символов из строки src к строке dest
char* strncatMy(char* dest, const char* src, size_t maxlen)
{
	size_t ind = strlen(dest);               // запоминаем начальную длину строки, к которой нужно приписать символы
	for (size_t i = 0; i <= maxlen; i++)     //приписываем нужное количество символов в цикле
	{
		dest[ind + i] = src[i];
		if (i == maxlen)                      //когда мы доходим до последнего символа, указываем на окончание строки
			dest[strlen(dest) + i] = '\0';
	}	
	return dest;
}