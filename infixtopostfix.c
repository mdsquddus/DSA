#include <stdio.h> 
#include<string.h>
#include <ctype.h>

void push(char a); 
char pop(); 
char stack[100]; 
int top =-1; 
void push(char a) 
{ 
    top=top+1; 
    stack[top]=a; 
} 
char pop(){ 
    char a=stack[top]; 
    top=top-1; 
    return a; 
} 
int main()
{
    char infix[100];

    scanf("%99s",infix);
    //printf("%s",infix);
    //printf("%d",strlen(infix));
    for (int i=0;i<strlen(infix);i++)
    {
        if (isdigit(infix[i])) {
            printf("%c",infix[i]);
        
        }
        else if(infix[i]=='(')
        {
            push('(');
        }
        else if(top==-1)
        {
            push(infix[i]);
        }
     else {
        if((stack[top]=='+'|| stack[top]=='-') && (infix[i]=='/' || infix[i]=='*'))
        {
            push(infix[i]);
        }
        else if((infix[i]=='+' || infix[i]=='-') && (stack[top]=='+' || stack [top]=='-'))
        {
            printf("%c",pop());
            //pop();
            push(infix[i]);
        }
        else if((infix[i]=='+'|| infix[i]=='-') && (stack[top]=='*' || stack [top]=='/'))
        {
            printf("%c",pop());
            if(stack[top]=='+' || stack[top]=='-')
            {
                printf("%c",pop());            
            }
            push(infix[i]);
        }   
        else if((infix[i]=='*' || infix[i]=='/') && (stack[top]=='*' || stack [top]=='/'))
        {
            printf("%c",pop());
            push(infix[i]);
        }
        else if(stack[top]=='(')
        {
            push(infix[i]);
        }
        else
        {
            if(infix[i]==')')
            {
                while(stack[top]!='(')
                {
                    printf("%c",pop());
                }
                pop();
            }
            
        }
    }
    }
    while(top!=-1)
    {
        if (stack[top]=='(')
        {
            char d=pop();
        }
        
       printf("%c",pop());
    }
    return 0;
}