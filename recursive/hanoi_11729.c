#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#hanoi 함수 생성
void hanoi(int n, char a, char b, char c) #판 개수, 기둥 1, 2, 3
{
	#만약 옮길 수 있는 판이 하나만 남았다면 출력
	if (n == 1)
		printf("%c %c\n", a, c);
	else
	{
		hanoi(n - 1, a, c, b);
		printf("%c %c\n", a, c);
		hanoi(n - 1, b, a, c);
	}
}

int main(void)
{
	int n, count = 1; #n, 1이 담겨 있는 count 변수 생성
	scanf("%d", &n); #n 입력받기
	for (int i = 0; i < n; i++) #이동 횟수 계산
		count *= 2;
	printf("%d\n", count - 1); #이동 횟수 출력
	hanoi(n, '1', '2', '3');
	return (0);
}
