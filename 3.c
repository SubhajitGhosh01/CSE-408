// K Closest Integers to X

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k, x;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &k, &x);

    int diff[n];
    for(int i = 0; i < n; i++) diff[i] = abs(arr[i] - x);

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(diff[i] > diff[j]) {
                int t = diff[i]; diff[i] = diff[j]; diff[j] = t;
                t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            }
        }
    }

    for(int i = 0; i < k; i++) printf("%d ", arr[i]);
    return 0;
}