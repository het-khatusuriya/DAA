#include <stdio.h>
#include <string.h>

// Function to find the longest common subsequence of two strings
void findLCS(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a 2D array to store the length of LCS
    int dp[len1 + 1][len2 + 1];

    // Build the dp table to store the length of LCS
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // Find the length of LCS
    int lcsLength = dp[len1][len2];

    // Create a character array to store the LCS
    char lcs[lcsLength + 1];
    lcs[lcsLength] = '\0';

    int i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[lcsLength - 1] = str1[i - 1];
            i--;
            j--;
            lcsLength--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    findLCS(str1, str2);

    return 0;
}
