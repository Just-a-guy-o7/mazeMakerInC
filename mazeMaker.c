#include<stdio.h>
#include<stdlib.h>

void printHori(int size){
    if(size==0){
        return;
    }
    printHori(size-1);
    printf("._");
}
void printVer(int size){
    if(size==0){
        return;
    }
    printVer(size-1);
    printf("| ");
}

int main(int argc, char const *argv[])
{   
//  int upper_bound=5;
//  int lower_bound=1;

//  int value = (rand() % (upper_bound - lower_bound + 1)
//                     + lower_bound);
 
    int size;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printHori(size-1);
        printf(".\n");
        printVer(size-1);
        printf("|\n");
    }
    printHori(size-1);
    printf(".\n");

    
}
