#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 16

int merge_sort(int* arr, int a, int b);

int main()
{
    int stream[ARRAY_SIZE];
    for(int iter=0;iter<ARRAY_SIZE;iter++)
    {
        stream[iter] = rand();
        printf("%d,",stream[iter]);
    }
    printf("\n");
    merge_sort(stream,0, sizeof(stream)/sizeof(int));
    for(int iter=0;iter<ARRAY_SIZE;iter++)
    {
        printf("%d,",stream[iter]);
    }
    return;
}
int merge_sort(int* arr, int a, int b)
{
    int *Lh;
    int *Rh;
    int c = 0;
    if (b - a > 1){
        c = (a + b + 1)/2; 
        merge_sort(arr,a,c);
        merge_sort(arr,c,b);
        Lh = malloc((c-a)*sizeof(int));
        Rh = malloc((b-c)*sizeof(int));
        memcpy(Lh,&(*(arr+a)),sizeof(int)*(c-a));
        memcpy(Rh,&(*(arr+c)),sizeof(int)*(b-c));
        // for(int iter = 0; iter < (c-a); iter++){
        //     *(Lh+iter) = *(arr + a + iter);
        // }
        // for(int iter = 0; iter < (b-c); iter++){
        //     *(Rh+iter) = *(arr + c + iter);
        // }
        merge(Lh,Rh,arr,c-a,(b-c),a,b);
    }
    return 0;
}

int merge(int* Lh, int* Rh, int* arr, int i, int j, int a, int b)
{
    if (a < b){
        if(j <= 0 || (i > 0 && *(Lh + i - 1) > *(Rh + j - 1))){
            *(arr + b - 1) = *(Lh + i - 1);
            i--;
        }
        else{
            *(arr + b - 1) = *(Rh + j - 1);
            j--;
        }
        merge(Lh,Rh,arr,i,j,a,b-1);
    }
    return;
}
