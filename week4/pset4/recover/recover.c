#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 512
//typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
// opens forensic file

    char *file = argv[1];
    FILE *raw_file = fopen(argv[1], "r");
    if (file == NULL)
    {
        // file could not be opened
        printf("Could not open %s.\n", file);
        return 1;
    }
    // variables
    bool found_jpg = false;  //flag to mark presence of a jpg
    int jpg_counter = 0;  //counter for number of jpg found
    uint8_t buffer[BLOCK_SIZE];  //buffer to store blocks of data from forensic file
    char jpg_name[8];  //array to store current jpg filename
    FILE *jpg_pointer = NULL;  //pointer to current jpg

    // read forensic file block by block
    //while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    while (fread(buffer, BLOCK_SIZE, 1, raw_file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (found_jpg)
            {
                fclose(jpg_pointer);
            }
            else
            {
                found_jpg = true;
            }
            // open new jpg image file
            sprintf(jpg_name, "%03d.jpg", jpg_counter);
            jpg_pointer = fopen(jpg_name, "w");
            if (jpg_pointer == NULL)
            {
                fclose(raw_file);
                printf("Could not create %s.\n", jpg_name);
                return 1;
            }
            //increment jpg counter
            jpg_counter++;
        }
        // if found, write current block to current jpg
        if (found_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, jpg_pointer);
        }
    }
    // close forensic image file and last jpg file if open
    fclose(raw_file);
    if (found_jpg)
    {
        fclose(jpg_pointer);
    }
    return 0;
}