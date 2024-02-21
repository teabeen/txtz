#include <stdio.h>
#include <string.h>
#include <libgen.h>

void processFile(const char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename1> [filename2] [filename3] ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        processFile(argv[i]);
    }

    return 0;
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    // Process the file
    // ...

    printf("\nStatistics for %s:\n", filename);
    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", wordCount);
    printf("Characters: %d\n", charCount);

    fclose(file);
}
