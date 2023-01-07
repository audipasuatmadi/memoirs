#include <stdio.h>

/**
 * printer_show_help - prints the help menu of the software
 * @author: Putu Audi Pasuatmadi <audipasuatmadi@gmail.com>
*/
void printer_show_help() {
    printf("memoirs commands:\n");
    printf("    -help => show commands available\n");
    printf("    -source => give the source of the mendeley output file\n");
    printf("    -out => give the destination of the mendeley output file\n");
}

/**
 * printer_show_mandatory_source_args - prints the mandatory source argument
 * @author: Putu Audi Pasuatmadi <audipasuatmadi@gmail.com>
*/
void printer_show_mandatory_source_args() {
    printf("-source path is mandatory, found none\n");
}

