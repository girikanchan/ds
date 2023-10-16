#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    
    // Open a file for writing
    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return 1;
    }
    
    // Write data to the file
    fprintf(file, "This is some text that we are writing to the file.\n");
    
    // Close the file
    fclose(file);
    
    // Open the file for reading
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Could not open file for reading.\n");
        return 1;
    }
    
    // Read and print the data from the file
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    // Close the file
    fclose(file);
    
    // Open the file for appending
    file = fopen(filename, "a");
    
    if (file == NULL) {
        printf("Could not open file for appending.\n");
        return 1;
    }
    
    // Append data to the file
    fprintf(file, "This is some additional text appended to the file.\n");
    
    // Close the file
    fclose(file);
    
    return 0;
}
