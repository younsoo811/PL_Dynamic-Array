//#include <stdio.h>
//#include <stdlib.h>
//
////c스타일
//int main()
//{
//	int *c, *d;
//
//	c = (int*)malloc(10 * sizeof(int));	//사이즈 10, 
//	d = (int*)malloc(10 * sizeof(int));	//사이즈 10
//
//
//	for (int i = 0; i < 10; i++) c[i] = i;	//0에서부터 9까지 값을 c에 꽉 차게 넣는다
//	for (int i = 0; i < 10; i++) d[i] = c[i];	//c에 있던걸 d에 복사
//	c = (int*)malloc(20 * sizeof(int));		//malloc을 이용해 사이즈 20개로 늘림 (처음에 넣던 c의 10개 데이터가 0으로 초기화됨)
//
//	for (int i = 0; i < 10; i++) c[i] = d[i];	//d에 백업했던 c의 값 불러오기
//	for (int i = 10; i < 20; i++) c[i] = i;	//c에 10부터 19까지 데이터 넣기
//
//	for (int i = 0; i < 20; i++)
//		printf("%d\n", c[i]);
//
//	free(c);
//	free(d);
//}

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

int SumOfStack = STACK_SIZE;
int stack[STACK_SIZE];  // 1차원 배열 스택 선언
int top = -1;               // top 초기화

// 스택이 공백 상태인지 확인하는 연산
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// 스택이 포화 상태인지 확인하는 연산
int isFull() {
	if (top == SumOfStack - 1) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(int item) {
	if (isFull()) {				// 스택이 포화 상태인 경우
		SumOfStack += STACK_SIZE;
		printf("top = %d", top);
		printf("  --- 스택 %d개", SumOfStack);
		stack[++top] = item;
		return;
	}
	else printf("top = %d", top); stack[++top] = item;	// top을 증가시킨 후 현재 top에 원소 삽입
}

// 스택의 top에서 원소를 삭제하는 연산
int pop() {
	if (isEmpty()) {	// 스택이 공백 상태인 경우
		printf("top = %d", top);
		printf("\n\n Stack is Empty!!\n");

		return 0;
	}
	else if (top%STACK_SIZE == 0 && SumOfStack>STACK_SIZE){	//스택사이즈는 최소 10이어야 한다.
		SumOfStack -= STACK_SIZE;
		printf("top = %d", top);
		printf("  --- 스택 %d개", SumOfStack);
		return stack[top--];
	}
	else printf("top = %d", top); return stack[top--];	// 현재 top의 원소를 삭제한 후 top 감소
}

// 스택의 원소를 출력하는 연산
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

void main(void) {
	int item;
	printf("\n** 순차 스택 연산 **\n");

	printf("\n--- 초기 스택 %d 개 ---\n", SumOfStack);
	printStack();
	for (int i = 0; i < 30; i++){
		push(i + 1); printStack();
	}
	printf("\n--- 총 스택 %d 개 ---\n", SumOfStack);

	for (int i = 0; i < 31; i++){
		printStack();	// 삭제
		item = pop();

		printf("\t pop  => %d", item);


	}


	printf("\n--- 최종 스택 %d 개 ---\n", SumOfStack);
	getchar();
}