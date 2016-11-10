#include <stdio.h>
#include <string.h>

extern int randomNumberGen(int seed); 

struct num_and_string
{
    int number;
    char *poetry; 
    struct num_and_string *next;
};

sturct num_and_string *ns_list;

int main(int argc, char* argv[])
{
    int random_number;
    int i, len;
    char filename[20];
    FILE *fp;


    for (i=0; i<10; i++)
       {
        random_number = randomNumberGen(i);
        printf("seed = %d, rand = %d\n", i, random_number);
       
        strcpy(filename, "file_");                                 //copies "file_" string into the character array called 'filename'
        len = strlen(filename);
        filename[len] = '0'+ i;                                       //overwrites /0 null character with an '0'
        filename[len + 1] = '\0';                               //appends \0/NULL at the end of the string
        strcat(filename, ".txt");                              //concats .txt at the end of our filename 
        printf("filename = %s\n",filename);

        fp = fopen(filename, "w");                          //opens (pointer to)'filename' in write mode  
        if ( fp == NULL )                                 //if null is returned, *fp is not valid
        {
            printf("Error opening file: %s\n", filename);
            return 1;                               
        }
        fprintf(fp, "%d\n", random_number);             //writes random_number into 'i'th' file
        fclose(fp);
    }
    
    create_list_of_numbers();
    
    return 0;
}

int randomNumberGen(int seed)
{
    int number;
    number = seed * 1103515245 + 12345;
    return (unsigned int)(number/65536) % 32768;
}

int creat
