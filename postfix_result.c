#include <stdio.h> 
#include<string.h>
#include <ctype.h>

char a[100];
int k=0;
int ans[100];

void push(char a); 
char pop(); 

void push1(int a); 
int pop1(); 


int top =-1; 
void push1(int a) 
{ 
    top=top+1; 
    ans[top]=a; 
} 


int pop1(){ 
    int a=ans[top]; 
    top=top-1; 
    return a; 
} 

char stack[100]; 

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
            do
            {
            printf("%c",infix[i]);
            a[k]=infix[i];
            k=k+1;
            i++;
            } while (isdigit(infix[i]));
            a[k]='#';
            k++;
            i--;
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
            a[k]=stack[top];
            k=k+1;
            printf("%c",pop());
            //pop();
            push(infix[i]);
        }
        else if((infix[i]=='+'|| infix[i]=='-') && (stack[top]=='*' || stack [top]=='/'))
        {
            a[k]=stack[top];
            k=k+1;
            printf("%c",pop());
            if(stack[top]=='+' || stack[top]=='-')
            {
                a[k]=stack[top];
                k=k+1;
                printf("%c",pop());            
            }
            push(infix[i]);
        }   
        else if((infix[i]=='*' || infix[i]=='/') && (stack[top]=='*' || stack [top]=='/'))
        {
            a[k]=stack[top];
            k=k+1;
            printf("%c",pop());
            push(infix[i]);
        }
        
        else if(infix[i]==')')
            {
            
                while(stack[top]!='(')
                {
                    a[k]=stack[top];
                    k++;
                    printf("%c",pop());
                }
                pop();
            
        }
        else 
        {
        if(stack[top]=='(')
        {
            push(infix[i]);
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
        a[k]=stack[top];
        k++;
       printf("%c",pop());
    }
    printf("\nthe 2nd part start here");
   // printf("%s",infix);
  int b, c;

for (int i = 0; i < strlen(a); i++)
{
    if (isdigit(a[i]))
    {
        int num = 0;

        while (isdigit(a[i]))
        {
            num=num*10+(a[i] - '0');
            i++;
        }

        push1(num);
    }
    else if (a[i] == '#')
    {
        continue;
    }
    else
    {
        b = pop1();
        c = pop1();

        if (a[i] == '+')
            b = c + b;
        else if (a[i] == '-')
            b = c - b;
        else if (a[i] == '*')
            b = c * b;
        else if (a[i] == '/')
            b = c / b;

        push1(b);
    }
}
    printf("\n%d",ans[top]);
    return 0;
}