#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];

    // check if the pointer works
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }


    unsigned char block[512];
    char filename[55];
    FILE *img = NULL;
    int count = -1;

    // here we are searching the file in 512 bytes blocks
    while (fread(block, 512, 1, inptr))
    {
        // check whether find a jpeg file or not
        if (
            block[0] == 0xff &&
            block[1] == 0xd8 &&
            block[2] == 0xff &&
            (block[3] & 0xf0) == 0xe0
        )
        {
            // check whether a jpeg file exist if yes close it
            if (img != NULL)

            {
                fclose(img);
            }

            count ++;
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
        }
        // if a jpeg file exists write the block in that file
        if (img != NULL)
        {
            fwrite(&block, 512, 1, img);
        }

    }

    fclose(img);
    fclose(inptr);
    return 0;
}