#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define F_OK 0
#define MAX_CHAR_BUFFER 255

/**
 * validator_file_exists - checks whether file exists from a given path
 * @path: string to the file path
 * @author: Putu Audi Pasuatmadi <audipasuatmadi@gmail.com>
*/
int validator_file_exists(char *path) {
    return access(path, F_OK) == 0;
}

/**
 * validator_file_extension_check - checks for extension name of a given file path
 * @path: string to the file path
 * @extension: string, name of the extension
 * @author: Putu Audi Pasuatmadi <audipasuatmadi@gmail.com>
 * @example: given path "/Sources.xml", and extension "xml", it will return 1 as
 * the extension matches
*/
int validator_file_extension_check(char *path, char *extension) {
    char *extensionBuffer = (char*)malloc(sizeof(char) * MAX_CHAR_BUFFER);
    char *extensionBufferStart = extensionBuffer;
    char *iterator = path;
    
    while (*iterator != '\0') {
        if (*iterator == '.') {
            extensionBuffer = extensionBufferStart;
            iterator++;
            continue;
        }
        *extensionBuffer = *iterator;
        extensionBuffer++;
        *extensionBuffer = '\0';
        
        iterator++;
    }
    
    if (strcmp(extensionBufferStart, extension) == 0) {
        return 1;
    }

    return 0;
}