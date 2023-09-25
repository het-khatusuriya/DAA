#include <stdio.h>
#include <string.h>
#define d 256 
void searchRabinKarp(char* text, char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;
    int prime = 101;
    for (int i = 0; i < M - 1; i++) {
        h = (h * d) % prime;
    }
    for (int i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % prime;
        t = (d * t + text[i]) % prime;
    }
    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == M) {
                printf("Pattern found at index %d\n", i);
            }
        }
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % prime;
            if (t < 0) {
                t = (t + prime);
            }
        }
    }
}
int main() {
    char text[100];
    char pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    printf("Occurrences of pattern in text:\n");
    searchRabinKarp(text, pattern);
    return 0; }
