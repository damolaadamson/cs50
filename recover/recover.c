#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2) // Checks to make sure there is exactly one command line argument
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *input_file = argv[1];
    FILE *input_pointer = fopen(input_file, "r"); //Opens and reads the input file
    if (input_pointer == NULL) //Checks if file is executable
    {
        printf("Could not open file %s.\n", input_file);
        return 1;
    }

    uint8_t buffer[BLOCKSIZE];  //Allocates buffer memory and stores the address
    int counter = 0; //Counts the number of jpeg files
    FILE *output_pointer = NULL; //Holds the contents of a file
    char filename[8]; //Declaration of output file name

    while (fread(buffer, sizeof(uint8_t), BLOCKSIZE, input_pointer)) //Reads through every block
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //Checks for new JPEG signature
        {
            if (output_pointer != NULL)
            {
                fclose(output_pointer); //Closes previous file if  jpg signature is found
            }

            sprintf(filename, "%03i.jpg", counter); //Sends the formatted output name to "filename"
            output_pointer = fopen(filename, "w"); //Opens new image file and stores the recovered image
            counter++; //Updates the number of recovered files
        }
            if (output_pointer != NULL) // Checks if JPEG file is successfully created
            {
                fwrite(buffer, sizeof(buffer), 1, output_pointer); //Writes new image into current file
            }
    }
    fclose(input_pointer);
    fclose(output_pointer);
    return 0;
}
