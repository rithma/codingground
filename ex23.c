#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int randomNumberGen(int seed); 

struct num_and_string
{
    int number;
    char *poetry; 
    struct num_and_string *next;
};

struct num_and_string *ns_list;

int main(int argc, char* argv[])
{
    int random_number;
    int i, len;
    char filename[20];
    FILE *fp;
    
    ns_list = NULL;               //initialize list indicating that the list is empty


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

int create_list_of_numbers()
{
    FILE *fp;
    int i, random_number, len;
    char filename[20];
    
    for(i=0; i<10; i++)
    {
        strcpy(filename, "file_");                                 //copies "file_" string into the character array called 'filename'
        len = strlen(filename);
        filename[len] = '0'+ i;                                       //overwrites /0 null character with an '0'
        filename[len + 1] = '\0';                               //appends \0/NULL at the end of the string
        strcat(filename, ".txt");                              //concats .txt at the end of our filename 
        printf("filename = %s\n",filename);

        fp = fopen(filename, "r");                          //opens (pointer to)'filename' in write mode  
        if ( fp == NULL )                                 //if null is returned, *fp is not valid
        {
            printf("Error opening file: %s\n", filename);
            return 1;                               
        }
        fscanf(fp, "%d", &random_number);             //passes adress of random mnumber into our fp
        add_number_to_list(random_number);
        
        fclose(fp);
        
    }
}











int add_number_to_list(int number)
{
    struct num_and_string *new_node;
    
    new_node = (struct num_and_string *)malloc(sizeof(struct num_and_string));
    if(new_node == NULL)
    {
        printf("error allocating memory: %d\n", number);
        return 1;
    }
    
    new_node->number = number;
    new_node->poetry = NULL;
    new_node->next = NULL;          //when new element is added, the next element is always NULL
 
    if (ns_list == NULL)  //the list is empty
    {
        ns_list = new_node;
        return 0;
    }
    else                     //list is not empty
    {                        //we want to traverse to the end of the listand add the new node to the end of the list 
        temp_node = ns_list;       //(NS LIST IS LIST HEAD)

        while (temp_node->next != NULL)  //while not null,  hop to the next
        {
            temp_node = temp_node->next;
        }    
        
        //Here, temp_node is the last element of the list
        
        temp_node->next = new_node;
    }                        
    return 0;
}



// for(temp_node=ns_list; temp_node->next != NULL; temp_node->next);
