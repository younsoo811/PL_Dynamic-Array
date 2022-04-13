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
int stack[STACK_SIZE];  // 1���� �迭 ���� ����
int top = -1;               // top �ʱ�ȭ

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
		printf("top = %d", top);
		printf("  --- ���� %d��", SumOfStack);
		stack[++top] = item;
		return;
	}
	else printf("top = %d", top); stack[++top] = item;	// top�� ������Ų �� ���� top�� ���� ����
}

// ������ top���� ���Ҹ� �����ϴ� ����
int pop() {
	if (isEmpty()) {	// ������ ���� ������ ���
		printf("top = %d", top);
		printf("\n\n Stack is Empty!!\n");

		return 0;
	}
	else if (top%STACK_SIZE == 0 && SumOfStack>STACK_SIZE){	//���û������ �ּ� 10�̾�� �Ѵ�.
		SumOfStack -= STACK_SIZE;
		printf("top = %d", top);
		printf("  --- ���� %d��", SumOfStack);
		return stack[top--];
	}
	else printf("top = %d", top); return stack[top--];	// ���� top�� ���Ҹ� ������ �� top ����
}

// ������ ���Ҹ� ����ϴ� ����
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

void main(void) {
	int item;
	printf("\n** ���� ���� ���� **\n");

	printf("\n--- �ʱ� ���� %d �� ---\n", SumOfStack);
	printStack();
	for (int i = 0; i < 30; i++){
		push(i + 1); printStack();
	}
	printf("\n--- �� ���� %d �� ---\n", SumOfStack);

	for (int i = 0; i < 31; i++){
		printStack();	// ����
		item = pop();

		printf("\t pop  => %d", item);


	}


	printf("\n--- ���� ���� %d �� ---\n", SumOfStack);
	getchar();
}