#include <stdio.h>
#include <string.h>

extern int randomNumberGen(int seed); 

int main(int argc, char* argv[])
{
    int random_number;
    int i, len;
    char filename[20];
  /*  
    strcpy(filename, "file_");                                 //copies "file_" string into the character array called 'filename'
    len = strlen(filename);
    printf("filename = %s length = %d\n", filename, len);      //outputs (prints)%string stored in 'filename'
    filename[len] = '0'+ 1;                                       //overwrites /0 null character with an '0'
    filename[len + 1] = '\0';                                  //appends \0/NULL at the end of the string
    len = strlen(filename);
    printf("filename = %s length = %d\n", filename, len);
    
    strcat(filename, ".txt");                                  //concats .txt at the end of our filename 
    printf("filename = %s length = %d\n", filename, strlen(filename));
    */
    for (i=0; i<10; i++)
    {
        random_number = randomNumberGen(i);
        printf("seed = %d, rand = %d\n", i, random_number);
        
        strcpy(filename, "file_");                                 //copies "file_" string into the character array called 'filename'
        len = strlen(filename);
        filename[len] = '0'+ i;                                       //overwrites /0 null character with an '0'
        filename[len + 1] = '\0';                                  //appends \0/NULL at the end of the string
        strcat(filename, ".txt");                                  //concats .txt at the end of our filename 
        printf("filename = %s\n",filename);
    
    }
    return 0;
}

int randomNumberGen(int seed)
{
    int number;
    number = seed * 1103515245 + 12345;
    return (unsigned int)(number/65536) % 32768;
}
