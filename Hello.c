//По текстовому файлу составить статистику длин строк и вывести строки в порядке возрастания их длин.
#define	    _CRT_SECURE_NO_WARNINGS
#include						<stdio.h>
#include						<locale.h>
#define		LEN					1000
#define		NUM_OF_STRINGS		256
struct SRT
{
	int		lenght;	//Длина строки
	char	*adr;	//Адрес строки
};
int main()
{
	setlocale(LC_ALL, "Russian");
	struct SRT lines[NUM_OF_STRINGS];	//Массив структур
	struct SRT tmp;						//Временная структура
	int		   i;
	int		   j;
	int        n;						//Счетчик строк
	char       str[NUM_OF_STRINGS][LEN];//Буффер текста
	char	   *ptr;
	int        counter;
	//Начальные определения переменных и чтение из файла
	i = 0;
	j = 0;
	n = 0;
	counter = 0;
	FILE *fpin;
	fpin = fopen("input.txt", "r");
	if (fpin == NULL)//Проверка корректности открытия файла
		return 1;
	while (ptr = fgets(str[i], sizeof(str[i]), fpin))//Анализ строк в файле
	{
		sscanf(str[i], "%[^\n]", str[i]);
		while (*ptr)								//Пока *ptr!='\0'
		{
			counter++;
			ptr++;
		}
		n++;										//Считаем количество строк в файле
		//Запись информации в соответствующие поля структуры
		lines[i].adr = str[i];
		lines[i].lenght = counter;
		//Выводим статистику по длине строк
		printf("In string %d symbols %d\n", i , lines[i++].lenght);
		counter = 0;
	}
	for (i = 0; i < n - 1; i++)						//Сортировка массива структур по длине строк файла методом "пузырька"
		for (j = i + 1; j < n; j++)
		{
			if (lines[i].lenght > lines[j].lenght)
			{
				tmp = lines[i];
				lines[i] = lines[j];
				lines[j] = tmp;
			}
		}
	printf("\n");
	//Вывод строк в порядке возрастания их длин
	for (i = 0; i < n; i++)
	{
		puts(lines[i].adr);
	}
	fclose(fpin);
	return 0;
}