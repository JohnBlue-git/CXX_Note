#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file;
    
    // Read file
    file = fopen("sample.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);  // Print the line to the console
    }
    puts("");

    fclose(file);

    // Append to file
    /*
    file = fopen("sample.txt", "a");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    const char *lineToAppend = "This is a new line to append.\n";
    if (fputs(lineToAppend, file) == EOF) {
        perror("Error writing to file");
        fclose(file);
        return EXIT_FAILURE;
    }
    
    fclose(file);
    */

    // Rewind the file pointer to the beginning
    rewind(file);
    
    // Write to file
    /*
    file = fopen("sample.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    const char *lineToWrite = "This is a new line to append.\n";
    if (fputs(lineToWrite, file) == EOF) {
        perror("Error writing to file");
        fclose(file);
        return EXIT_FAILURE;
    }
    
    fclose(file);
    */
    
    // for just string:
    //fputs();
    
    // for formated string:
    //if ( fprintf(file, "Name: %s\n", name) < 0 {
    //    ...
    //}

    // Open the file
    file = fopen("sample.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    // Caculate file size
    fseek(file, 0, SEEK_END);// Move the file pointer to the end of the file
    printf("The size of the file is: %ld bytes\n", ftell(file));// Get the current position (which is the size of the file)

    // Rewind the file pointer to the beginning
    rewind(file);
    
    // Close the file
    fclose(file);    
    
    return 0;
}
