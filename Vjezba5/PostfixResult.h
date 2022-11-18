#ifndef PostfixResult_h
#define PostfixResult_h

int PostfixResult(char* file, double* result) {
    char* buffer = NULL;
    int status = 0;

    buffer = readFromFile(file);
    if (buffer == NULL) {
        return FILE_DIDNT_OPEN_ERROR;
    }
    status = Postfiks(buffer, result);
    if (status != EXIT_SUCCESS) {
        return POSTFIX_ERROR;
    }

    return SUCCESS;
}

#endif