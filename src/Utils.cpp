#include <Utils.h>

#include <stdio.h>
#include <malloc.h>

char* readFileToString(const char* filename) {
    FILE* file = fopen(filename, "rb");

    if (!file) {
        printf("Could not open file %s.", filename);
        return "";
    }

    // Calculate the length of the file
    fseek (file, 0, SEEK_END);
    long length = ftell (file);

    // Go back to the start of the file
    fseek (file, 0, SEEK_SET);

    // Allocate a char array of required length
    char* string = (char*)malloc(length);

    if (string)
		fread (string, 1, length, file);

    fclose (file);

    return string;
}