#include <stdio.h>
/* ************************************************************************
 * Необходимор реализовать функцию rotate, которая сдвигает содержимое
 * массива влево на заданное число позиций (циклический сдвиг).
 *
 * На вход функция принимает массив, его размер и величину сдвига. Например,
 * если на вход функции подан массив:
 *	int a[] = { 1, 2, 3, 4, 5 };
 * и требуется циклически сдвинуть его влево на 2 позиции, то на выходе мы
 * получим числа в таком порядке: 3, 4, 5, 1, 2.
 *
 * Обратите внимание, что величина сдвига может быть нулевой, а может быть
 * и больше размера массива, все эти случаи нужно учесть.
 *
 * Основная часть программы уже готова, необходимо реализовать только
 * функцию.
 * ***********************************************************************/
void rotate (int * a, unsigned size, int shift);		//сдвигаем массив
void rotate1 (int * a, unsigned size, int shift);
void prtarr (int a[], unsigned size);						//выводим на экран

int main (void)
{
	int MAX = 4;										//размер массива
	int m[MAX];											//массив
	int i;
	int shift = -1;									//величина сдвига
	while (shift < 0)									//получаем размер сдвига
	{
		printf("Введите величину сдвига: ");
		scanf("%i", &shift);
		getchar();
	}
	for(i=0; i<MAX; i++){ m[i] = i+1; }			//заполняем массив
	prtarr(m, MAX);									//выводим на экран
	printf("\nпервый способ\n\n");
	rotate(m, MAX, shift);							//сдвигаем массив
	printf("\nвторой способ\n\n");
	for(i=0; i<MAX; i++){ m[i] = i+1; }			//заполняем массив
	rotate1(m, MAX, shift);							//сдвигаем массив
	return 0;
}
//-------------------------------------------------------------------------
void prtarr (int a[], unsigned size)
{
	int i;
	int d = size-1;
	for(i=0; i<size; i++)
	{
		printf("%i", a[i]);
		if (i < d) printf(" ");
	}
	printf("\n");
}
//-------------------------------------------------------------------------
void rotate (int * a, unsigned size, int shift)
{
	int i, j, tmp;

	if(shift == 0) { return; }
	if(shift > size) { shift %= size; }
	if(shift > 0 && shift <= size)
	{
		for(i = 0; i < shift; i++)
		{
			tmp = a[0];
			for(j = 0; j < size - 1; j++)
			{
				a[j] = a[j + 1];
				prtarr(a, size);
				a[j + 1] = tmp;
				prtarr(a, size);
			}
		}
	}
	return;
}
//-------------------------------------------------------------------------
void rotate1 (int * a, unsigned size, int shift)
{
	if (shift >= size) shift = shift % size;
	if (shift > 0)
	{
		int tmp, i, j;
		for(i=0; i<shift; i++)
		{
			tmp = a[0];
			for(j=1; j<size; j++)
			{
				a[j-1] = a[j];
				prtarr(a, size);
			}
			a[size-1] = tmp;
			prtarr(a, size);
		}
	}
}
