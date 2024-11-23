#include<stdio.h>
#include<stdlib.h>

int getRandomNumber(int upper_bound,int lower_bound){
    int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    return value;
}
int checkIfPossible(int togo[2],int current[2],int walls[][2]){
    int removingWall[2];
    if((togo[0]!=current[0])){
        if(togo[0]>current[0]){
            removingWall[0]=togo[0]-current[0];
        }
        else{
            removingWall[0]=current[0]-togo[0];
        }
        removingWall[1]=togo[1];
    }
    else{
        if(togo[1]>current[1]){
            removingWall[1]=togo[1]-current[1];
        }
        else{
            removingWall[1]=current[1]-togo[1];
        }
        removingWall[0]=togo[0];
    }
    for(int i=0;i<sizeof(walls)/sizeof(walls[0]);i++){
        if(walls[i][0]==-1){
            return 0;
        }
    }
    return 1;
    
}
int makePath(int facing,int size,int current[2],int path[][2],int vertiwalls[][2] ,int horiwalls[][2]  ){
    int alreadytaken=0;
    int flag=1;
    int choice=0;
    while(1){
        choice=getRandomNumber(3,1);
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
        if(flag==1){
            break;
        }
        else{
            flag=0;
        }
    }
    int togo[2];
    int result;
    
    int freeHoriVal=0;
    int freeVertiVal=0;
    int freePathVal=0;
    for(int i=0;i<sizeof(path)/sizeof(path[0]);i++){
        if(path[i][0]==-1){
            freePathVal=i;
            break;
        }
    }for(int i=0;i<sizeof(horiwalls)/sizeof(horiwalls[0]);i++){
        if(horiwalls[i][0]==-1){
            freeHoriVal=i;
            break;
        }
    }
    for(int i=0;i<sizeof(horiwalls)/sizeof(horiwalls[0]);i++){
        if(vertiwalls[i][0]==-1){
            freeVertiVal=i;
            break;
        }
    }

    if((facing=='r' && choice==2) || (facing=='u' && choice==3) || (facing='d' && choice==1)){
        togo[0]=current[0];
        togo[1]=current[1]+1;
        result=checkIfPossible(togo,current,vertiwalls);
        if(result==1){
            facing='r';
            if(current[0]==0){
                horiwalls[freeHoriVal][0]=1;
                horiwalls[freeHoriVal][1]=current[1]+1;
            }
            else if(current[0]==size-1){
                horiwalls[freeHoriVal][0]=size;
                horiwalls[freeHoriVal][1]=current[1]+1;
            }
            else{
                horiwalls[freeHoriVal][0]=current[0]+1;
                horiwalls[freeHoriVal++][1]=current[1]+1;
                horiwalls[freeHoriVal][0]=current[0];
                horiwalls[freeHoriVal++][1]=current[1]+1;
            }
        }
    }
    else if((facing=='d' && choice==2) || (facing=='r' && choice==3) || (facing='l' && choice==1)){
        togo[0]=current[0]-1;
        togo[1]=current[1];
        result=checkIfPossible(togo,current,horiwalls);
        if(result==1){
            facing='d';
            if(current[1]==0){
                vertiwalls[freeVertiVal][0]=current[0]+1;
                vertiwalls[freeVertiVal][1]=1;
            }
            else if(current[1]==size-1){
                vertiwalls[freeVertiVal][0]=current[0]+1;
                vertiwalls[freeVertiVal][1]=size;
            }
            else{
                vertiwalls[freeVertiVal][0]=current[0]+1;
                vertiwalls[freeVertiVal++][1]=current[1];
                vertiwalls[freeVertiVal][0]=current[0]+1;
                vertiwalls[freeVertiVal][1]=current[1]+1;

            }
        }
    }
    else if((facing=='l' && choice==2) || (facing=='d' && choice==3) || (facing='u' && choice==1)){
        togo[0]=current[0];
        togo[1]=current[1]-1;
        result=checkIfPossible(togo,current,vertiwalls);
        if(result==1){
            facing='l';
            if(current[0]==0){
                horiwalls[freeHoriVal][0]=1;
                horiwalls[freeHoriVal][1]=current[1]-1;
            }
            else if(current[0]==size-1){
                horiwalls[freeHoriVal][0]=size;
                horiwalls[freeHoriVal][1]=current[1]-1;
            }
            else{
                horiwalls[freeHoriVal][0]=current[0];
                horiwalls[freeHoriVal++][1]=current[1]-1;
                horiwalls[freeHoriVal][0]=current[0]+1;
                horiwalls[freeHoriVal][1]=current[1]-1;
            }
        }
    }
    else if((facing=='u' && choice==2) || (facing=='l' && choice==3) || (facing='r' && choice==1)){
        togo[0]=current[0]+1;
        togo[1]=current[1];
        result=checkIfPossible(togo,current,horiwalls);
        if(result==1){
            facing='u';
            if(current[1]==0){
                vertiwalls[freeVertiVal][0]=current[0]-1;
                vertiwalls[freeVertiVal][1]=1;
            }
            else if(current[1]==size-1){
                vertiwalls[freeVertiVal][0]=current[0]-1;
                vertiwalls[freeVertiVal][1]=size;
            }
            else{
                vertiwalls[freeVertiVal][0]=current[0]-1;
                vertiwalls[freeVertiVal++][1]=current[1];
                vertiwalls[freeVertiVal][0]=current[0]-1;
                vertiwalls[freeVertiVal][1]=current[1]+1;
            }
        }
    }
    if (result==1){
        if((togo[0]==size)  && (togo[1]==size)){
            path[0][0]=-2;
            path[0][1]=-2;
            return path;
        }
        current[0]=path[freePathVal][0]=togo[0];
        current[1]=path[freePathVal][1]=togo[1];
        path=makePath(facing,size,current,path,vertiwalls,horiwalls);
        
    }
    else if(alreadytaken>10){
        return path;
    }
    else if(alreadytaken>1){
        alreadytaken+=choice*10;
    }
    else{
        alreadytaken+=choice;
    }
}


int main(int argc, char const *argv[])
{ 
    int size;
    scanf("%d",&size);
    int horiwalls[size*(size+1)][2];
    int verticalwalls[size*(size+1)][2];
    int path[size*size][2];
    int horicount=0,vertcount=0;
    
    for(int i=0;i<size*size;i++){
        path[i][0]=-1;
        path[i][1]=-1;
    }

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
    for(;horicount<(size*(size+1));horicount++){
        horiwalls[horicount][0]=horiwalls[horicount][1]=-1;
        verticalwalls[vertcount][0]=verticalwalls[vertcount][1]=-1;
    }
}
