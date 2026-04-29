// Rotate String (String Matching)

#include <stdio.h>
#include <string.h>

int main() {
    char s[200], goal[200], temp[400];
    scanf("%s %s", s, goal);

    strcpy(temp, s);
    strcat(temp, s);

    if(strstr(temp, goal)) printf("1");
    else printf("0");

    return 0;
}