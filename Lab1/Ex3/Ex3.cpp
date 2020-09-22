#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


//���������� ������, ���-2, 4 �������

/*�������� ���� ������ ����������� ������� ��������� ����� �� ����� cstring, �
������������ � ���������. � ������� main �� �������� ������ ������������������
��������� ������ ��� ����������� �������, ��� � ����������� ������. ����-�����
������ ������������ ���������� cstdio.*/

/*������� strncat.
������ char* strncat(char* dest, const char* src, size_t maxlen).
������� ����������� maxlen �������� ������ src � ������ dest*/

//�������� ������� strncatMy
char* strncatMy(char* dest, const char* src, size_t maxlen);

int main()
{
	setlocale(LC_ALL, "Rus");
	const size_t size = 120;
	char dest[size] = "������-�����������";
	char src[size] = " ���������";
    
	printf( "������� ���������� ��������, ������� ���� ��������� � ������:\n");
	size_t maxlen = getchar();
	printf("\n");

	printf( "������������� ������ ������� strncat:\n");
	strncatMy(dest, src, maxlen);
	printf(dest);
	printf("\n\n");

	printf("������������� ���������� ������� strncat:\n");
	strncat(dest, src, maxlen);
	printf( dest );
	printf("\n\n");

}

// ���� ������� strncatMy, ������������� maxlen �������� �� ������ src � ������ dest
char* strncatMy(char* dest, const char* src, size_t maxlen)
{
	size_t ind = strlen(dest);               // ���������� ��������� ����� ������, � ������� ����� ��������� �������
	for (size_t i = 0; i <= maxlen; i++)     //����������� ������ ���������� �������� � �����
	{
		dest[ind + i] = src[i];
		if (i == maxlen)                      //����� �� ������� �� ���������� �������, ��������� �� ��������� ������
			dest[strlen(dest) + i] = '\0';
	}	
	return dest;
}