#include "Header.h"

int main(int argc, const char * argv[]) {
    
    int n=0;
    printf("N = ");
    scanf("%d", &n);
    
    int arr[n];
    int *p = arr;
    fillArr(n, p);
    for (int i=0; i<n; i++) {
        printf("%d\n", arr[i]);
    }
    
    printf("\nNumber of elements bigger than average: %d\n", bigAver(n, p));
    
    printf("Sum of elements after the first negative: %d\n\n",afterNegative(n, p));
    return 0;
}
