// Online C compiler to run C program online 
#include <stdio.h> 
void push(int a); 
int pop(); 
int stack[100]; 
int top =-1; 
void push(int a) 
{ 
    top=top+1; 
    stack[top]=a; 
} 
int pop(){ 
    int a=stack[top]; 
    top=top-1; 
    return a; 
} 
int main() { 
    printf("enter the number of elements in the binary tree\n"); 
    int n; 
    scanf("%d",&n); 
    int a[n]; 
    printf("enter the elements\n"); 
    for(int i=0;i<n;i++) 
    { 
        scanf("%d",&a[i]); 
    } 
     
    int i=0; 
   while (top!=-1 || (i<n && a[i] !=0)) 
    { 
    while (i<n && a[i]!=0){ 
       push(i); 
       i=2*i+1;       
        } 
       i=pop(); 
    printf("%d->",a[i]); 
i=2*i+2; 
 
    } 
    return 0; 
 
    // Write C code here 
 
    return 0; 
} 
