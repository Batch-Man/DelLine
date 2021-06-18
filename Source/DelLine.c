#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 16384

void Help()
{
    printf("\nDelete a line in a text file...\nv.1.0 Created by Kvc - www.batch-man.com\n\n");
    printf("\nSYNTAX:");
    printf("\nCall DelLine [File] [LineNumber]\n\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Error: missing arguments\n");
        Help();
        return 1;
    }
    if (!strcmp(argv[1], "/?"))
    {
        Help();
        return 0;
    }
    char *file_open = argv[1];
    /* File pointer to hold reference of input file */
    FILE *fTemp, *fOut;
    int i = 0, j = 0;

    char buffer[BUFFER_SIZE];
    fTemp = fopen(argv[1], "r");
    if (fTemp == NULL)
    {
        fprintf(stderr, "%s: %s", file_open, strerror(errno));
        return errno;
    }
    fOut = fopen(".temp", "w");

    /* fopen() return NULL if unable to open file in given mode. */

    int count = 0;

    while ((fgets(buffer, BUFFER_SIZE, fTemp)) != NULL)
    {
        count++;

        /* If current line is line to read */
        if (count == atoi(argv[2]))
        {
            //do nothing... as this line needs to be deleted!
        }
        else
        {
            fputs(buffer, fOut);
        }
    }

    fclose(fTemp);
    fclose(fOut);

    remove(argv[1]);
    rename(".temp", argv[1]);

    return 0;
}
