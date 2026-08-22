#include <stdio.h> 
 
void push(int); 
int pop(); 
 
int stack[100]; 
int top = -1; 
 
void push(int a) 
{ 
    top++; 
    stack[top] = a; 
} 
 
int pop() 
{ 
    int a = stack[top]; 
    top--; 
    return a; 
} 
 
int main() 
{ 
    int n; 
 
    printf("Enter the number of elements in the binary tree\n"); 
    scanf("%d", &n); 
 
    int a[n]; 
 
    printf("Enter the elements\n"); 
 
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]); 
 
    int i = 0; 
    int lastVisited = -1; 
 
    while (i < n || top != -1) 
    { 
        while (i < n && a[i] != -1) 
        { 
            push(i); 
            i = 2*i + 1; 
        } 
 
        if (top != -1) 
        { 
            int current = stack[top]; 
            int right = 2*current + 2; 
 
            if (right < n && a[right] != -1 && lastVisited != right) 
            { 
                i = right; 
            } 
            else 
            { 
                i = pop(); 
                printf("%d->", a[i]); 
                lastVisited = i; 
                i = n; 
            } 
        } 
    } 
 
    return 0; 
} 