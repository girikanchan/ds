#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_TOKENS 100

// Function to check if a character is a delimiter or not
bool isDelimiter(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == ';' || ch == '=');
}

// Function to tokenize the input string
int tokenize(char input[], char tokens[][MAX_TOKENS], int *numTokens) {
    int i = 0;
    int tokenIndex = 0;
    *numTokens = 0;

    while (input[i] != '\0') {
        if (!isDelimiter(input[i])) {
            int tokenLen = 0;
            while (!isDelimiter(input[i]) && input[i] != '\0') {
                tokens[tokenIndex][tokenLen] = input[i];
                tokenLen++;
                i++;
            }
            tokens[tokenIndex][tokenLen] = '\0';
            tokenIndex++;
            (*numTokens)++;
        } else {
            i++;
        }
    }

    return tokenIndex;
}

int main() {
    char input[] = "int a = 2;";
    char tokens[MAX_TOKENS][MAX_TOKENS];
    int numTokens = 0;

    int numExtractedTokens = tokenize(input, tokens, &numTokens);

    printf("Tokens:\n");
    for (int i = 0; i < numExtractedTokens; i++) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
    }

    printf("Total tokens: %d\n", numExtractedTokens);

    return 0;
}