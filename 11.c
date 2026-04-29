// Longest Common Subsequence (DP)

#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    scanf("%s %s",a,b);

    int n=strlen(a), m=strlen(b);
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0 || j==0) dp[i][j]=0;
            else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else {
                if(dp[i-1][j] > dp[i][j-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i][j-1];
            }
        }
    }

    printf("%d",dp[n][m]);
    return 0;
}