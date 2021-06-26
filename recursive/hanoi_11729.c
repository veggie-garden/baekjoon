#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//hanoi 함수 생성
//판 개수, 기둥 from은 시작하는 기둥, by는 거쳐가는 기둥, to는 최종 도착하는 기둥
void hanoi(int n, char from, char by, char to)
{
	//만약 옮길 수 있는 판이 하나만 남았다면 출력
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
	int n, count = 1;
	scanf("%d", &n); 
	
	//이동 횟수 계산 
	for (int i = 0; i < n; i++)
		count *= 2;
	printf("%d\n", count - 1);
	/*
	 * 한 원반을 다른 기둥으로 옮길 때 걸리는 최소 이동 횟수가 2^n - 1 번이다. 
	 * 그럼 원반이 3개라면 총 2^3 -1 번 이동한다. 
	 * 그래서 for문으로 2의 제곱을 구한 후, -1을 하는 것이다.
	 
	 * 만약 for문으로 쓰기 싫다면 pow라는 함수가 있다. math.h 라는 라이브러리를 불러오면 사용할 수 있다. 
	 * 사용 예시
	   int count = pow(2, N)- 1;
	   print("%d\n", count);
	*/
	
	hanoi(n, '1', '2', '3');
	return (0);
}
