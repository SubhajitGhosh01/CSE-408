// Merge K Sorted Lists

#include <stdio.h>
#include <stdlib.h>

int main() {
    int k;
    scanf("%d", &k);
    int total = 0;
    int arr[1000];

    for(int i = 0; i < k; i++) {
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; j++) scanf("%d", &arr[total++]);
    }

    for(int i = 0; i < total-1; i++) {
        for(int j = i+1; j < total; j++) {
            if(arr[i] > arr[j]) {
                int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            }
        }
    }

    for(int i = 0; i < total; i++) printf("%d ", arr[i]);
    return 0;
}