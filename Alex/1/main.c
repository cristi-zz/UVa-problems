#include <stdio.h>
#include <stdlib.h>


int calculate(int i, int j);
int cycle(int n);
int main()
{

    int iOrig,jOrig,tmp,i,j;
    while(scanf("%d %d\n",&iOrig,&jOrig)==2)
    {
        i = iOrig;
        j = jOrig;
        if(i>j){
            tmp = j;
            j = i;
            i = tmp;
        }
        int max = calculate(i,j);
        printf("%d %d %d\n",iOrig,jOrig,max);
    }

    return 0;
}

int cycle(int n)
{
    int counter = 1;

    while(n!=1)
    {
        n = n%2 ? 3*n+1 : n/2;
        counter++;
    }

    return counter;
}

int calculate(int i, int j)
{
    int counter;
    int max = cycle(i);
    for(counter=i+1; counter<=j; counter++)
    {
        int tMax = cycle(counter);
        max = (max<tMax) ? tMax : max;
    }
    return max;
}
