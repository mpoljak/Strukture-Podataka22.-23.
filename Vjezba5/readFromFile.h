#ifndef readFromFile_h
#define readFromFile_h


int readFromFile(char* filename)
{
    FILE* file = NULL;
    int size = 0;
    char* buffer = NULL;

    file = fopen(filename, "r");
    if (!file) {
        printf("\nFile does not exist.");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);

    buffer = (char*)calloc(size + 1, sizeof(char));
    if (!buffer) {
        perror("\nMemory allocation error!");
        return NULL;
    }

    rewind(file);
    fread(buffer, sizeof(char), size, file);
    printf("|%s|\n", buffer);
    fclose(file);

    return buffer;
}
#endif