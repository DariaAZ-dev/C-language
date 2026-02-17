#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void initialt(int *tab, int taille, int max_val) {
    for (int i = 0; i < taille; i++) {
        // rand() % max_val donne un nombre entre 0 et max_val - 1
        tab[i] = rand() % max_val;
    }}

int is_sorted(int *tab,int taille){
    int i=0;
    int j=1;
    while (i<taille && j<taille){
        if (tab[i]>tab[j]){
            return 1;
        }
        i++;
        j++;
    }
    return 0;
}

int main(void){
    int ex[6]={2,5,6,4,1,2};
    int ex2[5]={1,2,3,4,5};
    int i=is_sorted(ex,6);
    int j= is_sorted(ex2,5);
    printf("%d,%d",i,j);
    //for (int i = 0; i < 6; i++) {
    //printf("%d ", ex[i]);
    return 0;
}