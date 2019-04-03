#include <stdio.h>

// 하노이의 탑

// 1. 기둥 1에서 N-1개의 원반을 기둥 2로 옮긴다.
// 2. 기둥 1에서 1개의 원반을 기둥 3으로 옮긴다.
// 3. 기둥 2에서 N-1개의 원반을 기둥 3으로 옮긴다.

// 원반을 from에서 to로 옮긴다.
void move(int from, int to) { // 출력을 위한 함수 ( 굳이 함수를 통해서 출력할 필요 없음
	printf("Move from %d to %d\n", from, to);
}

// n개의 원반을 from 에서 by를 거쳐 to로 옮긴다.
void hanoi(int n, int from, int by, int to) {
	if (n == 1)
		move(from, to);
	else {
		hanoi(n - 1, from, to, by);    // 1번  N-1개의 원반을 기둥3을 거쳐 2로 옮긴다.
		move(from, to);                // 2번 기둥 1에서 1개의 원반을 기둥 3으롱 롬긴다.
		hanoi(n - 1, by, from, to);    // 3번 기둥 2에서 N-1개의 원반을 기둥 3으로 옮긴다.
	}
}


void main(void) {

	int i;
	printf("나무의 개수를 입력하시오 : ");
	scanf_s("%d", &i);
	hanoi(i, 1, 2, 3);

	return 0;
}

/*
	ex) 입력 값으로 3을 했을 경우
	시작
	hanoi(3,1,2,3); - > 
	n = 3 이기 때문에 else문으로 hanoi(2, 1, 3 , 2 ) - > 
	n = 2 이기 때문에 else문으로 hanoi(1, 1 , 2 , 3) - >
	n = 1이기 때문에 1.move( 1 -> 3)  - > // 해당 재귀 끝
    2.move( 1 -> 2 ) ->  hanoi(1, 3 , 1 , 2 )
	n = 1 이기 때문에 3.move( 3 -> 2) -> //해당 재귀 끝
	4.move( 1 -> 3 ) -> hanoi(2,2,1,3)
	n = 2 이기 때문에 else문으로 hanoi(1,2,3,1) ->
	n = 1이기 때문에 5.move( 2 -> 1 ) ->
	6.move ( 2 -> 1 ) -> hanoi(1,1,2,3) ->
	n = 1이기 때문에 7.move( 1 -> 3 ) // 전체 재귀 끝
	그렇기에 해당 알고리즘이 성립됨을 알 수 있다.

	결과론 적으로
	N이전의 기둥들을 2번 기둥으로 옮기는 것이다
	여기서 N이 홀수냐 짝수냐에 따라서
	가장 작은 기둥이 3번기둥으로 가는 것이냐 2번 기둥으로 가는 것이냐가 결정된다.
	이를 해결하는 재귀함수가 위의 하노이 함수이다.
	예를 들어 N = 4일때와 N = 6일때를 비교해 보면 
	N= 4의 결과값이 N = 6의 결과값의 초반 부분과 완전히 동일하다 ( 4개의 기둥을 3으로 옮길때 까지)
	그 후 5번을 2번으로 이동 3번 기둥들을 2번으로 이동 후
	마지막 6번을 3번으로 이동시키고 2번기둥에 있는 전체를 3번으로 옮기는 것으로 끝나는 것이다.
*/
