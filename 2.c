// Longest Common Prefix (Trie)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie {
    struct Trie* child[26];
    int isEnd;
} Trie;

Trie* create() {
    Trie* node = (Trie*)malloc(sizeof(Trie));
    for(int i = 0; i < 26; i++) node->child[i] = NULL;
    node->isEnd = 0;
    return node;
}

void insert(Trie* root, char* s) {
    Trie* temp = root;
    for(int i = 0; s[i]; i++) {
        int idx = s[i] - 'a';
        if(!temp->child[idx]) temp->child[idx] = create();
        temp = temp->child[idx];
    }
    temp->isEnd = 1;
}

int countChild(Trie* node, int* idx) {
    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(node->child[i]) {
            count++;
            *idx = i;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    char arr[n][100];
    Trie* root = create();

    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        insert(root, arr[i]);
    }

    Trie* temp = root;
    char res[100];
    int idx, k = 0;

    while(countChild(temp, &idx) == 1 && temp->isEnd == 0) {
        res[k++] = idx + 'a';
        temp = temp->child[idx];
    }
    res[k] = '\0';

    printf("%s", res);
    return 0;
}