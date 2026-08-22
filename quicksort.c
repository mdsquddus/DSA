#include <stdio.h> 
void push(int); 
int pop(); 
int stack[100]; 
int top=-1; 
int a[9]={2,5,8,0,6,1,7,11,4}; 
void quicksort(); 
void push(int a) { 
    top=top+1; 
    stack[top]=a; 
} 
int pop() 
{ 
    int a=stack[top]; 
    top=top-1; 
    return a; 
} 
void quicksort() 
{ 
    while (top !=-1) 
    { 
        int high = pop(); 
        int low = pop(); 
        int i=low -1; 
        int pivot=high; 
        int j=low; 
        if(low<high) 
        { 
            for(int k=low;k<high;k++) 
            { 
                if(a[j]<a[pivot]) 
                { 
                    i=i+1; 
                    int temp=a[i]; 
                    a[i]=a[j]; 
                    a[j]=temp; 
                } 
            j=j+1; 
            } 
            int temp=a[i+1]; 
            a[i+1]=a[pivot]; 
            a[pivot]=temp; 
            if(low<i) 
            { 
            push(low); 
            push(i); 
            } 
           if(i+2<high) 
           { 
            push(i+2); 
            push(high); 
           } 
        } 
    } 
} 
int main() { 
    // Write C code here 
     
    push(0); 
    push(8); 
    quicksort(); 
    for (int i=0;i<=8;i++) 
    { 
        printf("%d ", a[i]); 
    } 
    return 0; 
}