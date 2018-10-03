#include <iostream>
#include <string>
#include <Windows.h>
#include <locale.h>
#include <fstream>

using namespace std;

int sum_arr(int n, ...) {
	int *p = &n;
	int sum = 0;
	for (int i = 1; i < n+1; i++)
		sum += p[i];
	return sum;
}

//template<class T>
double sum2(double a, ...) {
	double* p = &a;
	double sum = 0;
	while (*p) {		
		sum += *p;
		p++;
	}
	return sum;
}

template <typename T>
T oper(char o, T arg, ...) {
	va_list p;
	/*T sum = 0;
	T prod = 1;
	int count = 0;
	T k = arg;
	__crt_va_start(p, arg);
	do {
		if (o == 's' || o == '+') {
			sum += k;
			count++;
		}
		else if (o == '*') {
			prod *= k;
		}
	} while (k = __crt_va_arg(p, T)); //пока не ноль - передвигаемся*/

	
	int count = 1;
	T k = arg;
	T sum = k;
	T prod = k;
	__crt_va_start(p, arg);
	while (k = __crt_va_arg(p, T)) {
		if (o == 's' || o == '+') {
			sum += k;
			count++;
		}
		else if (o == '*') {
			prod *= k;
		}
	} 

	__crt_va_end(p); // "закрыли" указатель
	if (o == 's')
		return (sum / count);
	else if (o == '+')
		return sum;
	else if (o == '*')
		return prod;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	int n;
	cin >> n;

	switch (n)
	{
	case 1:
	{
		char arr[30] = "HeLLo DiNaRRa";
		for (int i = 0; i < 30; i++) {
			if (arr[i] >= 65 && arr[i] <= 90) {
				arr[i] = arr[i] + 32;
			}
		}

		for (int i = 0; i < 30; i++)
			cout << arr[i];
		cout << endl;

	}
	break;

	case 2:
	{
		
		char arr[100] = "HeLLo DiNaRRa, Привет ДиНАРА";
		for (int i = 0; i < strlen(arr); i++) {
			if (arr[i] >= 65 && arr[i] <= 90) {
				arr[i] = arr[i] + 32;
			}
			else if (arr[i] >= -64 && arr[i] <= -33) {
				arr[i] = arr[i] + 32;
			}
		}

		for (int i = 0; i < strlen(arr); i++)
			cout << arr[i];
		cout << endl;
	}
	break;

	case 3:
	{
		//cout << sum2(1.2, 2.5, 7.5, 5.5, 0.0);
		//cout << oper('*', 2, 1, 4, 5, 5, 0) << endl;

		char arr[100] = "4+7-2-8";
		int sum = int(arr[0]-48);
		for (int i = 1; i < strlen(arr)-1; i++) {			
			if (arr[i] == '+')
				sum += int (arr[i + 1]-48);
			else if (arr[i] == '-')
				sum -= int(arr[i + 1]-48);
		}
		cout << sum << endl;

	}
	break;

	case 4:
	{
		//из двоичной в десятичную
		char arr[100] = "10111001";
		int sum = 0;
		for (int i = 0; i < strlen(arr); i++) {
			int prod = 1;
			prod *= int(arr[i] - 48)*pow(2, strlen(arr) - 1 - i);
			sum += prod;
		}		
		//cout << sum << endl;

		char buff[30];
		_itoa_s(sum, buff, 10); //перевод из числового формата в строковый
		for (int i = 0; i < strlen(buff); i++)
			cout << buff[i];
		cout << endl;
	}
	break;

	case 5:
	{
		//из десятичной в двоичную
		char arr[100] = "59";			
		int s=0;
		for (int i = 0; i < strlen(arr); i++) {
			s += int(arr[i] - 48)*pow(10, strlen(arr) - 1 - i);
		}		
		
		int h = 0;
		//int tmp[100];
		char tmp[100];
		while(s>0) {
			tmp[h++] = char(s % 2+48);
			s = s / 2;
		}		

		for (int i = h - 1; i >= 0; i--)
			cout << tmp[i];
		cout << endl;
	}
	break;

	case 6:
	{
		//копирование медиафайлов
		ifstream in_f("glutton2.jpg", ios::binary);
		ofstream out_f("out.jpg", ios::binary);

		char c;
		while (in_f.get(c)) {
			out_f << c;
		}
	}
	break;
	}
	
	system("pause");
	return 0;
}