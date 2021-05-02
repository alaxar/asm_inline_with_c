#include <stdio.h>

long int sum(int x, int y);
long int stack_pointer = 0;
long int base_pointer = 0;
long int program_counter = 0;
long int rax = 0, rbx = 0, rcx = 0, rdx = 0, rdi = 0, rsi = 0;

int main() {
	int x, y;
	printf("\nIt is a simple addition program that shows the inter-relationship between assemby language and C Language\nIt shows how both can interact each other.\nThe need of assembly language embedded inside C program is because assembly much faster.\n\n");
	asm("movq %%rsp, %%rax" : "=a"(stack_pointer));
	asm("movq %%rbp, %%rbx" : "=b"(base_pointer));
	asm("leaq (%%rip), %%rcx" : "=c"(program_counter));
	printf("\nStack Pointer Address: 0x%p\nBase Pointer Address: 0x%p\nInstruction Pointer(PC): 0x%p\n", stack_pointer, base_pointer, program_counter);
	printf("Size of Stack frame: %d\n", base_pointer - stack_pointer);
	printf("Address of .text segment: 0x%p\n", 
	printf("\n");
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
