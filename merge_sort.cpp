#include <stdio.h>
#include <stdlib.h>


#define sz 100
#define INF ((2^31)-1)


long num,data[sz];


void merge(long p,long q,long r) //void merge(long start,long mid,long last)
{
    long left[sz],right[sz],i,j,k;
    long n1 = q-p+1, n2 = r-q;

    for(i=1; i<=n1; i++) left[i]=data[p+i-1];
    for(i=1; i<=n2; i++) right[i]=data[q+i];

    left[n1+1]=INF;
    right[n2+1]=INF;
    i=j=1;


    for(k=p; k<=r; k++)
    {
        if(left[i]<=right[j])
        {
            data[k]=left[i];
            i++;
        }
        else
        {
            data[k]=right[j];
            j++;
        }
    }
}
//hi hle

void merge_sort(long p,long r)  //merge_sort(long star_point,long end_point)
{
    long q;

    if(p<r)
    {
        q=(p+r)/2;  //mid index
        merge_sort(p,q);
        merge_sort(q+1,r);

        merge(p,q,r);
    }
}


int main()
{
    int i;
    printf("Give the number of elements : ");
    while(scanf("%ld",&num)==1)
    {
        for(i=1; i<=num; i++)   //starts from index 1
            scanf("%ld",&data[i]);

        merge_sort(1,num);

        printf("\n\nSorted data are given in due order : \n");
        for(i=1; i<=num ; i++)
            printf("%ld\t",data[i]);
    }
    return 0;
}
