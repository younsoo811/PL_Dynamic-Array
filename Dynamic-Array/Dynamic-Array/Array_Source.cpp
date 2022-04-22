#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

int SumOfStack = STACK_SIZE;	//총 스택 사이즈
int *stack;				// 1차원 배열 스택 선언
int *stack_B;			// 선언된 스택 백업
int top = -1;			// top 초기화
int pop_B;				// pop 값 백업

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
		SumOfStack += STACK_SIZE;	//현 스택을 스택 사이즈 만큼 증가

		//malloc을 이용해 스택 사이즈 10개 증가한 값으로 동적할당 (처음에 넣던 stack의 데이터가 0으로 초기화됨)
		stack = (int*)malloc(SumOfStack * sizeof(int));		
		for (int i = 0; i < SumOfStack - STACK_SIZE; i++) {
			stack[i] = stack_B[i];	//stack_B에 백업했던 stack의 값 불러오기
		}

		//malloc을 이용해 (백업) 사이즈 10개 증가한 값으로 동적할당 (처음에 넣던 stack_B의 데이터가 0으로 초기화됨)
		stack_B = (int*)malloc(SumOfStack * sizeof(int));	
		for (int i = 0; i < SumOfStack - STACK_SIZE; i++) {
			stack_B[i] = stack[i];	//stack값 다시 (백업)stack_B에 백업
		}

		printf("\n  !! 스택 %d개 증가하였습니다 !!\n", STACK_SIZE);
		stack[++top] = item;	// top을 증가시킨 후 현재 top에 원소 삽입
		stack_B[top] = stack[top];	//stack 배열 값 백업
		return;
	}
	else {
		stack[++top] = item;
		stack_B[top] = stack[top];
	}
}

// 스택의 top에서 원소를 삭제하는 연산
int pop() {
	if (isEmpty()) {	// 스택이 공백 상태인 경우

		printf("\n\n Stack is Empty!!\n");

		return 0;
	}
	else if (top % STACK_SIZE == 0 && SumOfStack > STACK_SIZE){	//스택사이즈는 최소 10이어야 한다.
		SumOfStack -= STACK_SIZE;	//현 스택을 스택 사이즈 만큼 감소

		pop_B = stack[top--];	//pop값 백업

		stack = (int*)malloc(SumOfStack * sizeof(int));		//malloc을 이용해 스택 사이즈 감소한 값으로 동적할당
		for (int i = 0; i < SumOfStack; i++) stack[i] = stack_B[i];	//d에 백업했던 c의 값 불러오기

		printf("\n  !! 스택 %d개 감소되었습니다 !!\n", STACK_SIZE);
		return pop_B;
	}
	else {
		return stack[top--];	// 현재 top의 원소를 삭제한 후 top 감소
	}
}

// 스택의 원소를 출력하는 연산
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");

	printf("top = %d", top);
}

void main(void) {
	int item;	//pop() 반환값 저장하는 변수
	int data;	//push, pop 할때 명령을 저장하는 변수

	stack = (int*)malloc(STACK_SIZE * sizeof(int));	//사이즈 10, 
	stack_B = (int*)malloc(STACK_SIZE * sizeof(int));	//사이즈 10

	printf("\n** 순차 스택 연산 **\n");

	printf("\n--- 초기 스택 %d 개 ---\n", SumOfStack);
	printStack();

	//push
	while(1){
		printf("\n\n push할 숫자를 입력하세요 (0 입력시 입력을 종료합니다): ");
		scanf("%d", &data);
		if (data == 0){
			break;
		}
		push(data); printStack();
	}
	printf("\n--- push 이후 최종 스택 %d 개 ---\n", SumOfStack);

	//pop
	while(1){

		printf("\n\n Pop 하시겠습니까? (Yes: 1, No: 0): ");
		scanf("%d", &data);

		if (data == 0){
			break;
		}
		else if (data == 1){
			item = pop();	// 삭제	
			if (item == 0){	//top이 -1이면 while문 끝낸다
				break;
			}
			printStack();
			printf("\t pop  => %d", item);
		}
		else{
			printf("\n\n----다시 입력해주세요! (1 또는 0 만 입력)----");
		}
	}

	printf("\n\n--- 최종 스택 %d 개 ---\n\n", SumOfStack);

	//동적으로 할당된 영역 회수
	free(stack);
	free(stack_B);
}