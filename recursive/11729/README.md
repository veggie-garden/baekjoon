# 문제 설명
[문제 링크](https://www.acmicpc.net/problem/11729)

하노이의 탑은 기둥에 꽂혀있는 원판들을 다른 기둥으로 옮기는 게임입니다.

하노이의 탑은 규칙이 있는데:
  1. 한 번에 하나의 원반만 옮길 수 있다.
  2. 작은 원반 위에 큰 원반을 올릴 수 없다.

간단히 머리 속으로 생각해봅시다. 
첫번째 기둥으로 from이라 하고, 두번째 기둥을 by, 세번째 기둥을 to라고 하겠습니다. 
가장 작은 원반을 1, 중간 크기의 원반을 2, 가장 큰 원반을 3이라 하겠습니다.
그리고 우리에겐 이 3개의 원반이 from에 꽂혀져 있습니다.


그럼 이동은 아래와 같이 되겠지요:
  1. from에서 1을 to로 옮긴다.
  2. from에서 2를 by로 옮긴다.
  3. to에서 1을 by로 옮긴다. (2의 위로 1을 옮긴다.)
  4. from에서 3을 to로 옮긴다.
  5. by에서 1을 from으로 옮긴다.
  6. by에서 2를 to로 옮긴다. (3의 위로 2를 옮긴다.)
  7. from에서 1을 to로 옮긴다. (2의 위로 1을 옮긴다.)
  

위를 간단히 정리하자면 아래와 같이 됩니다:
  1. 가장 큰 원반 3을 제외한 모든 원반을 by로 옮긴다.
  2. 3을 to로 옮긴다.
  3. 3을 제외한 모든 원반을 to로 옮긴다.


위의 과정에서 원반의 수가 몇 개가 주어지든, 위의 과정을 반복할 뿐, 해결 방식에서의 변화는 없습니다.


그래서 정리하자면 아래와 같이 됩니다:
  1. from에 있는 가장 큰 원반을 제외한 모든 원반(n - 1)개를 by로 옮긴다.
  2. from에 있는 가장 큰 원반을 to로 옮긴다.
  3. by에 있는 가장 큰 원반을 제외한 모든 원반(n - 1)개를 to로 옮긴다.


같은 과정을 반복하기 때문에 재귀를 사용해서 풀면 됩니다.

## 문제 풀이
그럼 규칙을 알았으니, 함수를 만들어 봅시다.  
c:
```c
void hanoi(int n, char from, char by, char to)
{
  ...
}
```
python:
```python
def hanoi(n, first, second, thrid) #파이썬은 from이라는 함수가 이미 존재하기에 first, second, thrid 이라는 변수명으로 대체합니다.
```

재귀 함수에서 중요한 것은 탈출 조건입니다. 
단계별로 옮길 수 있는 원반이 하나만 남았을 때, 재귀를 탈출하게 만드면 됩니다.
이 말을 정리하자면, n - 1개의 원반을 계속해서 이동하며 재귀를 구성한 것이기 때문에, 이동할 수 있는 원반이 1개가 남았을 경우, 즉 n이 1이 된다면 탈출하게 만들면 됩니다.  
c:
```c
if (n == 1)
{
	printf("%c %c\n", from, to);
	return;
}
```
python:
```python
if n == 1:
        print(first, thrid)
        return;
```

탈출 조건을 만들었으니, 중간 이동하는 과정을 만들어야겠죠.
중간 이동하는 과정은 위에서 설명한대로 아래와 같습니다:
  1. from에 있는 가장 큰 원반을 제외한 모든 원반(n - 1)개를 by로 옮긴다.
  2. from에 있는 가장 큰 원반을 to로 옮긴다.
  3. by에 있는 가장 큰 원반을 제외한 모든 원반(n - 1)개를 to로 옮긴다.


단계별로 정리하겠습니다.


1. from에 있는 가장 큰 원반을 제외한 모든 원반(n - 1)개를 by로 옮긴다.
hanoi(int n, char from, char by, char to) 함수를 설명하자면, n개의 원반을, 이 기둥에서, 이 기둥을 통해, 이 기둥으로 옮긴다 라고 할 수 있죠. 
우리는 그럼 from에 있는 n-1개의 원반을, by로 옮겨야 합니다. 그럼 아래와 같이 정리할 수 있습니다.
from에 있는 가장 큰 원반을 제외한 모든 원반(n - 1)개를 by로 옮긴다 => hanoi(n - 1, from, to, by)  
c:
```c 
hanoi(n - 1, from, to, by)
```
python:
```python
hanoi(n - 1, first, thrid, second)
```

2. from에 있는 가장 큰 원반을 to로 옮긴다.
위의 코드를 통해서 n-1개의 원반이 모두 by로 옮겨졌습니다.
그래서 마지막 가장 큰 원반만 남았습니다. 옮기죠.  
c:
```c 
printf("%c %c\n", from, to); 
```
python:
```python
print(first, thrid)
```
3. by에 있는 가장 큰 원반을 제외한 모든 원반(n - 1)개를 to로 옮긴다.
가장 큰 원반을 옮겼으니, 우리는 다시 n-1개의 원반을 to로 옮겨야 합니다. 옮깁시다.  
c:
```c 
hanoi(n - 1, by, from, to); 
```
python:
```python
hanoi(n - 1, second, first, thrid)
```
  
정리하면 이렇게 됩니다:  
c:
```c
else
	{
		hanoi(n - 1, from, to, by);
		printf("%c %c\n", from, to);
		hanoi(n - 1, by, from, to);
	}
```
python:
```python
 else:
        hanoi(n-1, first, thrid, second)
        print(first, thrid)
        hanoi(n-1, second, first, thrid)
```

### 최종 코드
그래서 지금까지 나온 코드를 모두 합치면 이렇게 됩니다.  
c:
```c
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
```
python:
```python
def hanoi(n, first, second, thrid):
    if n == 1:
        print(first, thrid)
        return;
    else:
        hanoi(n-1, first, thrid, second)
        print(first, thrid)
        hanoi(n-1, second, first, thrid)
```

자, 이제 함수를 사용하기 위해서 main문을 만들겠습니다.  
c:
```c
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
	 * 더 자세히 알고 싶다면 하노이의 탑 이동 순서라고 검색
	 
	 * 만약 for문으로 쓰기 싫다면 pow라는 함수가 있다. math.h 라는 라이브러리를 불러오면 사용할 수 있다. 
	 * 사용 예시
	   int count = pow(2, N)- 1;
	   print("%d\n", count);
	*/
	
	hanoi(n, '1', '2', '3');
	return (0);
}
```
python으로 하면 이렇게 됩니다.
```python
n = int(input())
count = 1
for i in range(n):
    count *= 2
print(count - 1)
hanoi(n, '1', '2', '3')
```
## 실행
코드를 실행시키면 다음과도 같은 실행 순서로 실행될 것입니다:
  1. hanoi(3, '1', '2', '3') 			//hanoi(3, '1', '2', '3')
  2. hanoi(2, '1', '3', '2') 			//hanoi(n-1, from, to, by)
  3. hanoi(1, '1', '2', '3')			//hanoi(n-1, from, to, by)
  4. printf("%c %c\n", from, to); return; 	//n이 1이 되었기에 if문의 printf를 실행, 3번 종료
  5. printf("%c %c\n", from, to); 		//2번으로 돌아감. 2번 종료. 그 밑의 printf를 실행
  6. hanoi(1, '3', '1', '2') 			//hanoi(n-1, by, from, to)
  7. printf("%c %c\n", from, to); return;	//n이 1이 되었기에 if문의 printf를 실행, 6번 종료
  8. printf("%c %c\n", from, to);		//1번으로 되돌아감. 1번 종료. 그 밑의 printf를 실행. 
  9. hanoi(2, '2', '1', '3')			//hanoi(n-1, by, from, to)
  10. hanoi(1, '2', '3', '1')			//hanoi(n-1, from, to, by)
  11. printf("%c %c\n", from, to); return;	//n이 1이 되었기에 if문의 printf를 실행, 10번 종료
  12. printf("%c %c\n", from, to);		//9번으로 되돌아감. 9번 종료. 그 밑의 printf를 실행.
  13. hanoi(1, '1', '2', '3')			//hanoi(n-1, by, from, to)
  14. printf("%c %c\n", from, to); return;	//n이 1이 되었기에 if문의 printf를 실행. 13번 종료.
  
  정리하자면:
  
  <img src="/recursive/11729/11729.png" width="60%" background="white">
  
  이렇게 됩니다. 
  
  이진 트리 진행 순서에 맞게, 왼쪽부터 실행되고 오른쪽으로 진행됩니다. 
  
  이상 11729번 문제 풀이를 마치겠습니다.
