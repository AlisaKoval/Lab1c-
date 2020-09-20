#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

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
    size_t maxlen;
	cout << "������� ���������� ��������, ������� ���� ��������� � ������:";
	cin >> maxlen;
	cout << endl;

	cout << "������������� ������ ������� strncat:" << endl;
	strncatMy(dest, src, maxlen);
	cout <<dest<< endl;
	cout << endl;

	cout << "������������� ���������� ������� strncat:" << endl;
	strncat(dest, src, maxlen);
	cout << dest << endl;
	cout << endl;

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