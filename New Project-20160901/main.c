#include <stdio.h>

extern int randomNumberGen(int seed); 

int main(int argc, char* argv[])
{
    int random_number;
    int i;
    char filename[20];
    
    for (i=0; i<1000; i++)
    {
    random_number = randomNumberGen(i);
    printf("seed = %d, rand = %d\n", i, random_number);
    }
    return 0;
}

int randomNumberGen(int seed)
{
    int number;
    number = seed * 1103515245 + 12345;
    return (unsigned int)(number/65536) % 32768;
}
