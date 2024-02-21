#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    char ch;
    char filetype[10] = ""; // Initialize to empty string
    int in_word = 0; // Flag to track if we're in a word

    while ((ch = fgetc(file)) != EOF) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (in_word) {
                wordCount++;
                in_word = 0; // Reset the flag since we encountered a space
            }
        } else {
            in_word = 1; // We are in a word
        }
    }

    // Count the last word if the file didn't end with space or newline
    if (charCount > 0) {
        wordCount++;
    }

    // Find the file extension
    char *dot = strrchr(argv[1], '.');
    if (dot) {
        strcpy(filetype, dot + 1); // Copy the file extension to the 'filetype' array
    } else {
        strcpy(filetype, "Unknown"); // If no extension found, mark it as 'Unknown'
    }

    printf("Filename: %s\n", argv[1]);
    printf("Filetype: %s\n", filetype);
    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", wordCount);
    printf("Characters: %d\n", charCount);

    fclose(file);

    return 0;
}
