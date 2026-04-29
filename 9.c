// Height Checker (Counting Sort)

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n], count[101]={0};

    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        count[arr[i]]++;
    }

    int idx=0, res=0;
    for(int i=0;i<=100;i++) {
        while(count[i]--) {
            if(arr[idx]!=i) res++;
            idx++;
        }
    }

    printf("%d",res);
    return 0;
}