#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define token types
typedef enum {
    KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    FLOAT_LITERAL,
    OPERATOR,
    DELIMITER,
    COMMENT,
    ERROR
} TokenType;

// Define a structure for tokens
typedef struct {
    TokenType type;
    char lexeme[100]; // Assume a maximum token length of 100 characters
} Token;

// Function to check if a string is a keyword
bool isKeyword(char *str) {
    char *keywords[] = {"int", "float", "if", "else", "while", "for", "return"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    
    return false;
}

// Function to recognize and tokenize input
Token* tokenize(char *input, int *numTokens) {
    Token *tokens = malloc(strlen(input) * sizeof(Token));
    *numTokens = 0;
    
    char buffer[100]; // Buffer to store characters
    int bufferIndex = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        
        // Check for whitespace characters
        if (isspace(c)) {
            continue;
        }
        
        // Check for alphabetic characters (identifiers or keywords)
        if (isalpha(c)) {
            buffer[bufferIndex++] = c;
            while (isalnum(input[i + 1])) {
                buffer[bufferIndex++] = input[++i];
            }
            buffer[bufferIndex] = '\0';
            Token token;
            token.type = isKeyword(buffer) ? KEYWORD : IDENTIFIER;
            strcpy(token.lexeme, buffer);
            tokens[(*numTokens)++] = token;
            bufferIndex = 0; // Reset buffer
        }
        
        // Check for numeric literals (integers or floats)
        else if (isdigit(c)) {
            buffer[bufferIndex++] = c;
            while (isdigit(input[i + 1]) || input[i + 1] == '.') {
                buffer[bufferIndex++] = input[++i];
            }
            buffer[bufferIndex] = '\0';
            Token token;
            if (strchr(buffer, '.') == NULL) {
                token.type = INTEGER_LITERAL;
            } else {
                token.type = FLOAT_LITERAL;
            }
            strcpy(token.lexeme, buffer);
            tokens[(*numTokens)++] = token;
            bufferIndex = 0; // Reset buffer
        }
        
        // Check for operators and delimiters
        else if (strchr("+-*/=<>!&|(),;{}", c)) {
            buffer[bufferIndex++] = c;
            buffer[bufferIndex] = '\0';
            Token token;
            token.type = OPERATOR;
            strcpy(token.lexeme, buffer);
            tokens[(*numTokens)++] = token;
            bufferIndex = 0; // Reset buffer
        }
        
        // Check for comments
        else if (c == '/' && input[i + 1] == '/') {
            while (input[i] != '\n' && input[i] != '\0') {
                i++;
            }
        }
        
        // Handle other characters as errors
        else {
            buffer[bufferIndex++] = c;
            buffer[bufferIndex] = '\0';
            Token token;
            token.type = ERROR;
            strcpy(token.lexeme, buffer);
            tokens[(*numTokens)++] = token;
            bufferIndex = 0; // Reset buffer
        }
    }
    
    return tokens;
}

int main() {
    char input[1000];
    printf("Enter C code: \n");
    fgets(input, sizeof(input), stdin);
    
    int numTokens;
    Token *tokens = tokenize(input, &numTokens);
    
    printf("Tokens:\n");
    for (int i = 0; i < numTokens; i++) {
        printf("Type: %d, Lexeme: %s\n", tokens[i].type, tokens[i].lexeme);
    }
    
    free(tokens);
    return 0;
}
