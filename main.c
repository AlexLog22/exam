#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    assert(a != NULL);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int count = 0;
    int *unique = (int *)malloc(n * sizeof(int));
    assert(unique != NULL);
    int *nonUnique = (int *)malloc(n * sizeof(int));
    assert(nonUnique != NULL);

    for (int i = 0; i < n; i++){
        int isUnique = 1;
        for (int j = i+1; j < n; j++){
            if (a[i] == a[j]) {
                isUnique = 0;
                break;
            }
        }
        if (!isUnique)
            nonUnique[count++] = a[i];
        else
            unique[i-count] = a[i];
    }

    printf("There are %d non-unique elements:\n", count);
    for (int i = 0; i < count; i++)
        printf("%d ", nonUnique[i]);

    free(a);
    free(unique);
    free(nonUnique);

    return 0;
}
