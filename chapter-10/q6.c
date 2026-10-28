#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //for exit()

/* Reverse Polish Notation (RPN). operators are placed after their operands instead of between their operands. 1 + 2 would be
written 1 2 + in RPN, and 1 + 2 * 3 would be written 1 2 3 * +. RPN expressions can easily be evaluated using a stack. The algorithm involves reading the operators and operands in an expression from left to right, performing the following actions:
When an operand is encountered, push it onto the stack.  (OPERATORS ONLY APPLY TO PREVIOUS 2 OPERANDS)
When an operator is encountered, pop its operands from the stack, perform the operation on those operands, and then push the result onto the stack.
Write a program that evaluates RPN expressions. The operands will be single-digit integers.
The operators are +,-, *, /, and =. The = operator causes the top stack item to be displayed;
afterwards, the stack is cleared and the user is prompted to enter another expression. The process continues until the user enters a character that is not an operator or operand:
Enter an RPN expression: 1 2 3 * + =
Value of expression: 7
Enter an RPN expression: 5 8 * 4 9 - / =
Value of expression: -8
Enter an RPN expression: g
If the stack overflows, the program will display the message Expression is too complex and terminate. If the stack underflows (because of an expression such as 1 2++), the program will display the message Not enough operands in expression and terminate. Hints: Incorporate the stack code from Section 10.2 into your program. Use scanf(" %c", &ch) to read the operators and operands. */

// from section 10.2:
#define STACK_SIZE 100
/* external variables */
int contents[STACK_SIZE];
int top = 0;
void make_empty(void)
{
    top = 0;
}
bool is_empty(void)
{
    return top == 0;
}
bool is_full(void)
{
    return top == STACK_SIZE;
}
void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(1); // unlike return, exit can be used anywhere in program. it terminates the program and 1 indicates error
}

void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(1);
}
void push(int i) // add item to top of stack
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}
int pop(void) // remove topmost item
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

int main()
{
    char ch;
    int operand1, operand2;

    for (;;) // infinite loop until non operand or non operator char
    {
        make_empty();                        // reset the stack at the start of each new expression loop so old data doesn't carry over
        printf("Enter an RPN expression: "); // prompts for new expression
        while (scanf(" %c", &ch) == 1)       // keeps going until = or invalid character
        {
            if (ch >= '0' && ch <= '9') // if ch is an operand
            {
                push(ch - '0'); // convert to integer and push to stack
            }
            else
            {
                switch (ch)
                {
                case '+':
                    operand2 = pop();          // top value
                    operand1 = pop();          // second top value
                    push(operand1 + operand2); // second top value + top value  (order matters for - and /)
                    break;
                case '-':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 - operand2);
                    break;
                case '*':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 * operand2);
                    break;
                case '/':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 / operand2);
                    break;
                case '=':
                    printf("Value of expression: %d\n", pop());
                    // Clear stack for the next expression and break inner loop
                    make_empty();
                    goto next_expression; // jumps out of the inner loop to wherever next_expression: is
                default:
                    // character that aren't operands or operators
                    return 0;
                }
            }
        }
    next_expression:;
    }
    return 0;
};
