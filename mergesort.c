#include <stdio.h> 
 
int main() 
{ 
     
 
    int n; 
    printf("enter the number of elements in the array\n"); 
    scanf("%d",&n); 
    int a[n]; 
    int b[n]; 
 
    printf("enter\n"); 
    for (int i=0;i<n;i++) 
    { 
        scanf("%d",&a[i]); 
    } 
 
    int s = 1; 
 
    while (s < n) 
    { 
        int z = 0; 
 
        for (int i = 0; i < n; i = i + (2 * s)) 
        { 
            int j = i; 
            int k = i + s; 
            if(k>n) 
            { 
                k=n; 
            } 
            int mid = k; 
            int l = k + s; 
            if(l>n) 
            { 
                l=n; 
            } 
 
            while (j < mid && k < l) 
            { 
                if (a[j] <= a[k]) 
                { 
                    b[z] = a[j]; 
                    j++; 
                } 
                else 
                { 
                    b[z] = a[k]; 
                    k++; 
                } 
 
                z++; 
            } 
 
            while (j < mid) 
            { 
                b[z] = a[j]; 
                j++; 
                z++; 
            } 
 
            while (k < l) 
            { 
                b[z] = a[k]; 
                k++; 
                z++; 
            } 
        } 
 
        for (int i = 0; i < n; i++) 
        { 
            a[i] = b[i]; 
        } 
 
        s = s * 2; 
    } 
 
    for (int i = 0; i < n; i++) 
    { 
        printf("%d ", b[i]); 
    } 
 
    return 0; 
}