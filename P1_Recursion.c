#include<stdio.h>
void recursion(int position, int max, int count){
    if(position >= max)
        return;

    printf("Current Position: %d\n", position);

    if(count % 2 == 0)
        recursion(position + 2, max, count + 1);
    else
        recursion(position + 4, max, count + 1);
}

int main(){
    recursion(0, 10, 0);
    return 0;
}

