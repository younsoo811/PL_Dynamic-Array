//#include <stdio.h>
//#include <stdlib.h>
//
////c��Ÿ��
//int main()
//{
//	int *c, *d;
//
//	c = (int*)malloc(10 * sizeof(int));	//������ 10, 
//	d = (int*)malloc(10 * sizeof(int));	//������ 10
//
//
//	for (int i = 0; i < 10; i++) c[i] = i;	//0�������� 9���� ���� c�� �� ���� �ִ´�
//	for (int i = 0; i < 10; i++) d[i] = c[i];	//c�� �ִ��� d�� ����
//	c = (int*)malloc(20 * sizeof(int));		//malloc�� �̿��� ������ 20���� �ø� (ó���� �ִ� c�� 10�� �����Ͱ� 0���� �ʱ�ȭ��)
//
//	for (int i = 0; i < 10; i++) c[i] = d[i];	//d�� ����ߴ� c�� �� �ҷ�����
//	for (int i = 10; i < 20; i++) c[i] = i;	//c�� 10���� 19���� ������ �ֱ�
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
		SumOfStack += STACK_SIZE;
		
		stack = (int*)malloc(SumOfStack * sizeof(int));		//malloc�� �̿��� ������ 20���� �ø� (ó���� �ִ� c�� 10�� �����Ͱ� 0���� �ʱ�ȭ��)
		for (int i = 0; i < SumOfStack-STACK_SIZE; i++) stack[i] = stack_B[i];	//d�� ����ߴ� c�� �� �ҷ�����

		printf("  --- ���� %d��", SumOfStack);
		stack[++top] = item;
		
		return;
	}
	else {
		stack[++top] = item;	// top�� ������Ų �� ���� top�� ���� ����
		stack_B[top] = stack[top];	//stack �迭 �� ���
	}
}

// ������ top���� ���Ҹ� �����ϴ� ����
int pop() {
	if (isEmpty()) {	// ������ ���� ������ ���
		
		printf("\n\n Stack is Empty!!\n");

		return 0;
	}
	else if (top % STACK_SIZE == 0 && SumOfStack > STACK_SIZE){	//���û������ �ּ� 10�̾�� �Ѵ�.
		SumOfStack -= STACK_SIZE;

		pop_B = stack[top--];	//pop�� ���

		stack = (int*)malloc(SumOfStack * sizeof(int));		//malloc�� �̿��� ������ 20���� �ø� (ó���� �ִ� c�� 10�� �����Ͱ� 0���� �ʱ�ȭ��)
		for (int i = 0; i < SumOfStack; i++) stack[i] = stack_B[i];	//d�� ����ߴ� c�� �� �ҷ�����
		
		printf("  --- ���� %d��", SumOfStack);
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
	int item;
	int data;

	stack = (int*)malloc(STACK_SIZE * sizeof(int));	//������ 10, 
	stack_B = (int*)malloc(STACK_SIZE * sizeof(int));	//������ 10

	printf("\n** ���� ���� ���� **\n");

	printf("\n--- �ʱ� ���� %d �� ---\n", SumOfStack);
	printStack();
	for (int i = 0; i < 30; i++){
		printf("\n\n �����͸� �Է��ϼ��� (0 �Է½� �Է��� �����մϴ�): ");
		scanf("%d", &data);
		if (data == 0){
			break;
		}
		push(data); printStack();
		
	}
	printf("\n--- push ���� ���� ���� %d �� ---\n", SumOfStack);

	for (int i = 0; i < 31; i++){
		
		item = pop();	// ����		
		printStack();	


		printf("\t pop  => %d", item);
		if (top == -1){
			break;
		}

	}
	
	printf("\n\n--- ���� ���� %d �� ---\n\n", SumOfStack);

	free(stack);
	free(stack_B);
	getchar();
}