#include <stdlib.h>
#include <stdio.h>

#define ARRSIZE(arr) (sizeof(arr)/sizeof(*(arr)))

int compare(const void* a, const void* b) {
    int x1 = *(int*)a;
    int x2 = *(int*)b;
    if (x1 > x2) return  1;
    if (x1 < x2) return -1;
    int y1 = *(((int*)a)+1);
    int y2 = *(((int*)b)+1);
    if (y1 > y2) return  1;
    if (y1 < y2) return -1;
    return 0;
}



int main()
{

    int metal_num;
    printf("Dwse arithmo apo metal bands:");

    scanf("%d", &metal_num);


    int i,j;
    int matrix[metal_num*2][2];

    for(i=0;i<metal_num;i++){
        printf("Stigmi afiksis metal band %d:",i+1);
        scanf("%d", &matrix[i][0]);
        matrix[i][1]=1;
        printf("Stigmi apoxwrisis metal band %d:",i+1);
        scanf("%d", &matrix[i+metal_num][0]);
        matrix[i+metal_num][1]= -1;
    }

    int k,l,t,t1;


    for(k=0;k<metal_num-1;k++){
        for(i=0;i<metal_num-k-1;i++){
            if(matrix[i][0]<matrix[i+1][0]){
                t = matrix[i][0];
                matrix[i][0] = matrix[i+1][0];
                matrix[i+1][0] = t;
            }
            else if(matrix[i][0]==matrix[i+1][0]){
                if(matrix[i][1]<matrix[i+1][1]){
                    t1 = matrix[i][1];
                    matrix[i][1] = matrix[i+1][1];
                    matrix[i+1][1] = t1;
                }
            }
        }
    }


    int metals = 0;
    int maxcount = 0;
    int ora = 0;
    qsort(matrix, ARRSIZE(matrix), sizeof(*matrix), compare);
    for (i = 0; i < metal_num*2; i++){
        metals = metals + matrix[i][1];
        if (metals > maxcount){
            maxcount = metals;
            ora = matrix[i][0];
        }
    }

    printf("Ora pou prepei na paei : %d\n", ora);
    printf("Opou tha einai ekei :%d metal bands",maxcount);
    return 0;
}
