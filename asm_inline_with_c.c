#include <stdio.h>

int sum(int x, int y);

int main() {
	int x, y;
	printf("\nIt is a simple addition program that shows the inter-relationship between assemby language and C Language\nIt shows how both can interact each other.\nThe need of assembly language embedded inside C program is because assembly much faster.\n\n");
	printf("Enter two operands[eg. 1 2]: ");
	scanf("%d %d", &x, &y);
	printf("%d + %d = %d\n", x, y, sum(x, y));
	return 0;
}

asm(
	"sum:;"
	"	pushq %rbp;"
	"	movq %rsp, %rbp;"
	"	subq $0x10, %rsp;"
	"	movq 24(%rbp), %rax;"
	"	addq 28(%rbp), %rax;"
	"	movq %rbp, %rbp;"
	"	leave;"
	"	ret;"
   );
