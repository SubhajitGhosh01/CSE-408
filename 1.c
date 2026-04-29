// Longest Palindromic Substring (Two Pointer)

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    int n = strlen(s), start = 0, maxlen = 1;

    for(int i = 0; i < n; i++) {
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            if(r - l + 1 > maxlen) {
                start = l;
                maxlen = r - l + 1;
            }
            l--; r++;
        }
        l = i; r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            if(r - l + 1 > maxlen) {
                start = l;
                maxlen = r - l + 1;
            }
            l--; r++;
        }
    }

    for(int i = start; i < start + maxlen; i++) printf("%c", s[i]);
    return 0;
}