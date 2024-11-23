#include<stdio.h>
#include<stdlib.h>



int main(int argc, char const *argv[])
{ 
    int size;
    scanf("%d",&size);
    int horiwalls[size*size+1][2];
    int verticalwalls[size*size+1][2];
    int path[size*size][2];
    int horicount=0,vertcount=0;

    for(int i=0;i<size;i++){
        horiwalls[horicount][0]=0;
        horiwalls[horicount++][1]=i;
        horiwalls[horicount][0]=size;
        horiwalls[horicount++][1]=i;
        verticalwalls[vertcount][0]=i; 
        verticalwalls[vertcount++][1]=0; 
        verticalwalls[vertcount][0]=i; 
        verticalwalls[vertcount++][1]=size; 
    }
    


}
