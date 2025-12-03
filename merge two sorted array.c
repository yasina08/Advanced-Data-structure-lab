#include <stdio.h>

int main() {
    int a[50], b[50], merged[100];
    int n1, n2, i, j, k;

    
    printf("Enter number of elements in first sorted array: ");
    scanf("%d", &n1);
    printf("Enter elements (sorted) of first array:\n");
    for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    
    printf("Enter number of elements in second sorted array: ");
    scanf("%d", &n2);
    printf("Enter elements (sorted) of second array:\n");
    for(i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    i = 0;  
    j = 0;  
    k = 0;  

    // Merge process (like merge step in Merge Sort)
    while(i < n1 && j < n2) {
        if(a[i] < b[j])
            merged[k++] = a[i++];
        else
            merged[k++] = b[j++];
    }

    // Copy remaining elements (if any)
    while(i < n1)
        merged[k++] = a[i++];

    while(j < n2)
        merged[k++] = b[j++];


    printf("\nMerged Sorted Array: ");
    for(i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);

    return 0;
}
