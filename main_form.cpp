#include <stdio.h>
#define SIZE 255
struct {
	int size;
	char expression[SIZE];
} cal_exp;

int main(void) 
{
	char x = getchar();	cal_exp.size = 0;
	while(x!='\n'){
		cal_exp.expression[size++] = x;
		x = getchar();
	}

	key_add_pressed();
	
	return 0;

}
void key_add_pressed()
{
	char stack_sign[SIZE], stack_num[SIZE];
	int len = cal_exp.size;
	int len_num=0, len_sign=0; //point to top of stack which is to be pushed
	for (int i=0;i<len;i++) {
		if (cal_exp.expression[i]<='9' && cal_exp.expression[i]>='0') {
			stack_num[len_num++] = cal_exp.expression[i];
		} else {
			if (len_sign == 0 || (stack_sign[len_sign-1] == '(' && cal_exp.expression[i] != ')') || highPriority(stack_sign[len_sign-1],cal_exp.expression))
				stack_sign[len_sign++] = cal_exp.expression[i];
			if (stack_sign[len_sign-1]=='(' && cal_exp.expression[i]==')')
				len_sign--;
			if (highPriority(cal_exp.expression[i], stack_sign[len_sign-1]) || //栈中优先级更高
				(cal_exp.expression[i]==')' && stack_sign[len_sign-1]!=')') || //括号成对
				(cal_exp.expression[i] == '' && len_sign>0) //表达式空，仍剩余符号于栈
				) {
				char sign = stack_sign[--len_sign];
				int  num1  = stack_num[--len_num];
				switch(sign)
				{
					case '+':	stack_num[len_num-1] += num1;break;
					case '-':	stack_num[len_num-1] -= num1;break;
					case '*':	stack_num[len_num-1] *= num1;break;
					case '/':	stack_num[len_num-1] /= num1;break;
				}
			}	
		}
	}
}

//后者优先级大于前者
int highPriority(char stack, char exp)
{
	int a,b;
	switch(stack)
	{
		case '(' : a=3;break;
		case '*' : a=2;break;		
		case '/' : a=2;break;
		case '+' : a=1;break;
		case '-' : a=1;break;
		default  : a=0;break;
	}
	switch(exp)
	{
		case '(' : a=3;break;
		case '*' : a=2;break;		
		case '/' : a=2;break;
		case '+' : a=1;break;
		case '-' : a=1;break;
		default  : a=0;break;
	}
	return a < b;
}
