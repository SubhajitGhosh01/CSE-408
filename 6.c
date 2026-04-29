// Kth Largest Element (Quickselect)

#include <stdio.h>

int partition(int arr[], int l, int r) {
    int pivot = arr[r], i = l;
    for(int j = l; j < r; j++) {
        if(arr[j] <= pivot) {
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            i++;
        }
    }
    int t = arr[i]; arr[i] = arr[r]; arr[r] = t;
    return i;
}

int quickselect(int arr[], int l, int r, int k) {
    if(l <= r) {
        int pi = partition(arr, l, r);
        if(pi == k) return arr[pi];
        else if(pi < k) return quickselect(arr, pi+1, r, k);
        else return quickselect(arr, l, pi-1, k);
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);

    printf("%d", quickselect(arr, 0, n-1, n-k));
    return 0;
}