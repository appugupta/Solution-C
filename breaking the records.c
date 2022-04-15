#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int min;
    int countmin = 0;
    int max;
    int countmax = 0;
    int *score = malloc(sizeof(int) * n);
    for(int score_i = 0; score_i < n; score_i++){
       scanf("%d",&score[score_i]);
    }
    min = max = score[0];
    for (int i = 1; i < n; i++){
        if (score[i] > max){
            countmax++;
            max = score[i];
        }
        if (score[i] < min){
            countmin++;
            min = score[i];
        }
    }
    printf("%d %d", countmax, countmin);
    return 0;
}