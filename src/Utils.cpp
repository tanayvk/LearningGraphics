#include <Utils.h>

#include <stdio.h>
#include <malloc.h>

char* readFileToString(char* filename) {
    FILE* file = fopen(filename, "rb");

    if (!file) {
        printf("Could not open file %s.", filename);
        return "";
    }

    // Calculate the length of the file
    fseek (file, 0, SEEK_END);
    long length = ftell (file);
    printf("%d", length);

    // Go back to the start of the file
    fseek (file, 0, SEEK_SET);

    // Allocate a char array of required length
    char* string = (char*)malloc(length + 1);

    if (string)
		fread (string, 1, length, file);

    string[length] = '\0';

    fclose (file);

    return string;
}