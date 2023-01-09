#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printer.h"
#include "validator.h"

#define SOURCE_PATH_BUFFER_MAX 255
#define SOURCE_PATH_EXTENSION "xml"
#define OUT_PATH_BUFFER_MAX 255
#define DEFAULT_OUT_PATH "./Out-Sources.xml"
#define PRINT_STREAM stderr
#define BUFSIZE 1024
#define LOOKUP_TAG "SourceType"


/**
 * memoirs - the main entrypoint for the memoirs software.
 * The sole purpose of this software is as a personal tool to make the mendeley reference manager
 * software compatible with my Microsoft Word, at which it wasn't compatible due to some incompatibilities
 * at the output XML that the Mendeley Reference Manager outputs.
 * @author: Putu Audi Pasuatmadi <audipasuatmadi@gmail.com>
*/
int main(int argc, char **argv) {
    if (argc == 1) {
        printer_show_help();
        return 0;
    }
    
    int showHelp = 0;
    int hasSourcePath = 0;
    int hasOutPath = 0;
    char *sourcePath;
    char *outPath;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "help") == 0) {
            printer_show_help();
            return 0;
        }
        if (strcmp(argv[i], "-source") == 0) {
            if (i + 1 == argc) {
                printer_show_help();
                return 0;
            }
            hasSourcePath = 1;
            sourcePath = argv[i+1];
            i++;
            continue;
        }
        if (strcmp(argv[i], "-out") == 0) {
            if (i + 1 == argc) {
                printer_show_help();
                return 0;
            }
            hasOutPath = 1;
            outPath = argv[i+1];
            i++;
            continue;
        }
    }

    if (!hasSourcePath) {
        printer_show_mandatory_source_args();
        printer_show_help();
        return 0;
    }

    if (!hasOutPath) {
        outPath = DEFAULT_OUT_PATH;
    }

    if (!validator_file_exists(sourcePath)) {
        fprintf(PRINT_STREAM, "source file %s not found", sourcePath);
        return 0;
    }

    if (!validator_file_extension_check(sourcePath, SOURCE_PATH_EXTENSION)) {
        fprintf(PRINT_STREAM, "source file invalid extension, should be .xml, found %s", sourcePath);
        return 0;
    }

    FILE *fp = fopen(sourcePath, "r");
    if (fp == NULL) {
        fprintf(PRINT_STREAM, "source file error, cannot open");
        return 0;
    }

    FILE *tfp = fopen(outPath, "w");
    if (tfp == NULL) {
        fprintf(PRINT_STREAM, "out file error, cannot open");
        return 0;
    }

    char *buffer = (char*)malloc(sizeof(char) * BUFSIZE);
    char *writeBuffer;
    char *writeBufferStart;
    int isSourceType = 0;

    char *iterator;
    while(fgets(buffer, BUFSIZE, fp) != NULL) {
        iterator = buffer;
        isSourceType = 1;
        while (*iterator != '<') {
            if (*iterator == '\0' || *iterator == '\n') {
                isSourceType = 0;
                break;
            }
            iterator = iterator + 1;
        }
        
        if (!isSourceType) {
            fprintf(tfp, "%s", buffer);
            continue;
        }

        if (!(*(iterator+3) == 'S' && *(iterator+9) == 'T' && *(iterator+13) == '>')) {
            fprintf(tfp, "%s", buffer);
            continue;
        }
        
        writeBufferStart = (char*)malloc(sizeof(char) * BUFSIZE);
        writeBuffer = writeBufferStart;

        iterator = iterator + 14;
        while (*iterator != '<') {
            if (*iterator == ' ') {
                iterator = iterator + 1;
                continue;
            }
            *writeBuffer = *iterator;
            writeBuffer = writeBuffer + 1;
            iterator = iterator + 1;
        }
        *writeBuffer = '\0';
        fprintf(tfp, "    %s%s%s\n", "<b:SourceType>", writeBufferStart, "</b:SourceType>");   
        writeBuffer = writeBufferStart;
        free(writeBufferStart);     
    }

    fclose(fp);
    fclose(tfp);
    return 0;
}