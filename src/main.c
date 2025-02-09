#include <stdio.h>
#include <stdlib.h>

int count_words(FILE *file) {
    int words = 0;
    char prev = ' ';
    char c;

    while ((c = fgetc(file)) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t') && prev != ' ' && prev != '\n' && prev != '\t') {
            words++;
        }
        prev = c;
    }
    return words;
}

int count_lines(FILE *file) {
    int lines = 0;
    char c;
    
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    return lines;
}

int count_characters(FILE *file) {
    int characters = 0;
    while (fgetc(file) != EOF) {
        characters++;
    }
    return characters;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int words, lines, characters;
    
    words = count_words(file);
    rewind(file);  // Reset file pointer for next function
    lines = count_lines(file);
    rewind(file);
    characters = count_characters(file);

    fclose(file);

    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    printf("Characters: %d\n", characters);

    return 0;
}

