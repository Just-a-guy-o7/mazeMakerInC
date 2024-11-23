#include<stdio.h>
#include<stdlib.h>

int getRandomNumber(int upper_bound,int lower_bound){
    int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    return value;
}
void makePath( ){
    int alreadytaken=23;
    int flag=1;
    while(1){
        int choice=getRandomNumber(3,1);
        int temp=alreadytaken;
        while(temp!=0){
            if(temp%10==choice ){
                flag=0;
                break;
            }
            else{
                flag=1;
            }
            temp/=10;
        }
        printf("====================\nchoice :  %d  ",choice);
        if(flag==1){
            break;
        }
        else{
            flag=0;
        }
    }


}


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
    makePath();

}
