#define _CRT_SECURE_NO_WARNINGS //избавиться от ошибок
#include<stdio.h>

void main() {
	int a = 5;
	//double b = 10.7;
	int b = 6;
	int res;
	//res = a;
	//res = (int)b;
	printf("res = %d", res);
	res = a + b; //важен порядок выполнения операции(справо налево)
	res = a - b - 5 + a;
	res = a / b; //5/6=0 
	res = a % b; //1 остаток, с double будет дробь если разные типы приводится к double %lf
	res = -a; //-1*a
	res = +a; //для цифровых типов ничего не происходит, char работает
	res = +'a';
	res = ++a; //префиксный прибавляет 1, использовать так
	res = a++; //постфиксный сначала результат, затем выводит a+1, с минусами так же
	printf("a = %lf\n", a);
	printf("res = %lf", res);
	
	//логические операторы
	int a = 0;
	int b = 0;
	int res = 0;
	res = a;
	printf("a = %d\t//табуляция", a); // \t - знак табуляции
	printf("b = %d\t//табуляция", b);
	printf("res = %d\t//табуляция", res+a) //сначала посчитает затем вывод;
	res = a == b != c < a !(a < b) //не меньше 
		&& //и 
		|| //или

	printf("size b = %d", sizeof(b)); //узнать размер переменной
}