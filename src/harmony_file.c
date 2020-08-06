#include <stdio.h>
#include <stdlib.h>

#include "harmony_file.h"

/**
 * Reads the contents of a file into a char buffer.
 * Returns 0 for a success.
 */
int harmony_readIntoBuffer(const char* path, char **buffer)
{
    FILE *fp;
    size_t fsz;
    long off_end;
    int rc;

    fp = fopen(path, "rb");
    if (fp == NULL)
        return 1;

    rc = fseek(fp, 0L, SEEK_END);
    if (rc != 0)
        return 1;

    if (0 > (off_end = ftell(fp)))
        return 1;

    fsz = (size_t) off_end;

    *buffer = malloc(fsz + 1);
    if (*buffer == NULL)
        return 1;

    rewind(fp);

    if (fsz != fread(*buffer, 1, fsz, fp))
    {
        free(*buffer);
        return 1;
    }

    if (fclose(fp) == EOF)
    {
        free(*buffer);
        return 1;
    }

    (*buffer)[fsz] = '\0';

    return 0;
}
