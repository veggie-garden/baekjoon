#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, char from, char by, char to)
{
	if (n == 1)
  	{
		printf("%c %c\n", from, to);
    		return;
  	}
	else
	{
		hanoi(n - 1, from, to, by);
		printf("%c %c\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main(void)
{
	int n, count = 1;
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		count *= 2;
	printf("%d\n", count - 1);
	hanoi(n, '1', '2', '3');
	return (0);
}
