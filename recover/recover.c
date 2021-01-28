#include <stdio.h>
#include <stdlib.h>

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

    unsigned char *buffer = malloc(512); //Allocates buffer memory and stores the address
    int counter = 0; //
    FILE *output_pointer; //Holds the contents of a file
    char output[8]; //Declaration of output file name

    while (fread(buffer, 512, 1, input_pointer) == 1) //Reads through every block
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //Checks for new JPEG signature
        {
            if (counter > 0)
            {
                fclose(output_pointer); //Closes previous file if signature is found
            }

            sprintf(output, "%03i.jpg", counter); //Sends the formatted output name to "output"
            output_pointer = fopen(output, "w"); //Opens new image file and stores the recovered image

            if (output_pointer == NULL) // Checks if JPEG file is successfully created
            {
                fclose(input_pointer); //Closes file if JPEG is successfully created
                free(buffer); //Frees alocated buffer memory
                return 1;
            }

            counter++; //Updates the number of recovered files
        }

        if (counter == 0) //Skips if JPEG file is not found
        {
            continue;
        }

        fwrite(buffer, 512, 1, output_pointer); //Writes new image into current file
    }

    fclose(input_pointer);
    fclose(output_pointer);
    free(buffer); //Frees alocated buffer memory

    return 0;
}