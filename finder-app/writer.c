#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]) {
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <file> <string>", argv[0]);
        closelog();
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    char *content = argv[2];

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file %s", filename);
        closelog();
        return EXIT_FAILURE;
    }

    // Write content to file
    fprintf(file, "%s\n", content);
    fclose(file);

    // Log message with syslog
    syslog(LOG_DEBUG, "Writing \"%s\" to %s", content, filename);

    closelog();
    return EXIT_SUCCESS;
}
