#include <stdio.h>
#include <string.h>
#include <libgen.h> // for basename()

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) { // Open the file to be scanned
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    char ch;
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
    char filetype[10] = ""; 
    char *dot = strrchr(filename, '.');
    if (dot) {
        strcpy(filetype, dot + 1); // Copy the file extension to the filetype array
    } else {
        strcpy(filetype, "Unknown"); // If no extension found, mark it as 'Unknown'
    }

    // Extract filename from the full path
    char *base_name = basename((char *)filename);

    fseek(file, 0, SEEK_END);
    long int fsize = ftell(file);

    printf("Filename: %s\n", base_name);
    printf("Filetype: %s\n", filetype);
    printf("Filesize: %ld bytes\n", fsize);
    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", wordCount);
    printf("Characters: %d\n", charCount);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename1> [<filename2> ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        processFile(argv[i]);
        printf("\n"); // Add a newline between each file's statistics
    }

    return 0;
}
