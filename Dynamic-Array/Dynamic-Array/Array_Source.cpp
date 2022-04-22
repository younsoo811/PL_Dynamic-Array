#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

int SumOfStack = STACK_SIZE;	//�� ���� ������
int *stack;				// 1���� �迭 ���� ����
int *stack_B;			// ����� ���� ���
int top = -1;			// top �ʱ�ȭ
int pop_B;				// pop �� ���

// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// ������ ��ȭ �������� Ȯ���ϴ� ����
int isFull() {
	if (top == SumOfStack - 1) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(int item) {
	if (isFull()) {				// ������ ��ȭ ������ ���
		SumOfStack += STACK_SIZE;	//�� ������ ���� ������ ��ŭ ����

		//malloc�� �̿��� ���� ������ 10�� ������ ������ �����Ҵ� (ó���� �ִ� stack�� �����Ͱ� 0���� �ʱ�ȭ��)
		stack = (int*)malloc(SumOfStack * sizeof(int));		
		for (int i = 0; i < SumOfStack - STACK_SIZE; i++) {
			stack[i] = stack_B[i];	//stack_B�� ����ߴ� stack�� �� �ҷ�����
		}

		//malloc�� �̿��� (���) ������ 10�� ������ ������ �����Ҵ� (ó���� �ִ� stack_B�� �����Ͱ� 0���� �ʱ�ȭ��)
		stack_B = (int*)malloc(SumOfStack * sizeof(int));	
		for (int i = 0; i < SumOfStack - STACK_SIZE; i++) {
			stack_B[i] = stack[i];	//stack�� �ٽ� (���)stack_B�� ���
		}

		printf("\n  !! ���� %d�� �����Ͽ����ϴ� !!\n", STACK_SIZE);
		stack[++top] = item;	// top�� ������Ų �� ���� top�� ���� ����
		stack_B[top] = stack[top];	//stack �迭 �� ���
		return;
	}
	else {
		stack[++top] = item;
		stack_B[top] = stack[top];
	}
}

// ������ top���� ���Ҹ� �����ϴ� ����
int pop() {
	if (isEmpty()) {	// ������ ���� ������ ���

		printf("\n\n Stack is Empty!!\n");

		return 0;
	}
	else if (top % STACK_SIZE == 0 && SumOfStack > STACK_SIZE){	//���û������ �ּ� 10�̾�� �Ѵ�.
		SumOfStack -= STACK_SIZE;	//�� ������ ���� ������ ��ŭ ����

		pop_B = stack[top--];	//pop�� ���

		stack = (int*)malloc(SumOfStack * sizeof(int));		//malloc�� �̿��� ���� ������ ������ ������ �����Ҵ�
		for (int i = 0; i < SumOfStack; i++) stack[i] = stack_B[i];	//d�� ����ߴ� c�� �� �ҷ�����

		printf("\n  !! ���� %d�� ���ҵǾ����ϴ� !!\n", STACK_SIZE);
		return pop_B;
	}
	else {
		return stack[top--];	// ���� top�� ���Ҹ� ������ �� top ����
	}
}

// ������ ���Ҹ� ����ϴ� ����
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");

	printf("top = %d", top);
}

void main(void) {
	int item;	//pop() ��ȯ�� �����ϴ� ����
	int data;	//push, pop �Ҷ� ����� �����ϴ� ����

	stack = (int*)malloc(STACK_SIZE * sizeof(int));	//������ 10, 
	stack_B = (int*)malloc(STACK_SIZE * sizeof(int));	//������ 10

	printf("\n** ���� ���� ���� **\n");

	printf("\n--- �ʱ� ���� %d �� ---\n", SumOfStack);
	printStack();

	//push
	while(1){
		printf("\n\n push�� ���ڸ� �Է��ϼ��� (0 �Է½� �Է��� �����մϴ�): ");
		scanf("%d", &data);
		if (data == 0){
			break;
		}
		push(data); printStack();
	}
	printf("\n--- push ���� ���� ���� %d �� ---\n", SumOfStack);

	//pop
	while(1){

		printf("\n\n Pop �Ͻðڽ��ϱ�? (Yes: 1, No: 0): ");
		scanf("%d", &data);

		if (data == 0){
			break;
		}
		else if (data == 1){
			item = pop();	// ����	
			if (item == 0){	//top�� -1�̸� while�� ������
				break;
			}
			printStack();
			printf("\t pop  => %d", item);
		}
		else{
			printf("\n\n----�ٽ� �Է����ּ���! (1 �Ǵ� 0 �� �Է�)----");
		}
	}

	printf("\n\n--- ���� ���� %d �� ---\n\n", SumOfStack);

	//�������� �Ҵ�� ���� ȸ��
	free(stack);
	free(stack_B);
}