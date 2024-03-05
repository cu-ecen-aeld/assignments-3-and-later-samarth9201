#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
    // Required 3 arguments.
    if(argc != 3){
        fprintf(stderr, "Required 3 arguments, %d received.\n", argc);
        exit(1);
    }

    char*writeFile = argv[1];
    char*str = argv[2];

    // Open File
    FILE * file = fopen(writeFile, "w");
    if(file == NULL){
        // Error if file cannot be opened
        syslog(LOG_ERR, "unable to open File: %s", writeFile);
        perror("fopen");
        exit(1);
    }

    // Write to File
    fprintf(file, "%s", str);
    fclose(file);

    // Log
    openlog(NULL, 0, LOG_USER);
    syslog(LOG_DEBUG, "Writing \"%s\" to file %s", str, writeFile);
    closelog();

    return 0;
}