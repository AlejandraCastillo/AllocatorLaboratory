#include <stdio.h>
#include "utils.h"



void save_bitmap_state(int copy_dest[]){
    // copy de actual state of the bitmap
    for (int i = 0; i < BITMAP_SIZE; i++) {
        copy_dest[i] = bitmap[i];
    }
}

void print_bitmap_comparison(int old_bitmap[]){ 
    // headers 
    printf("\n         Before         \t\t          After\n");

    // content 
    for(int i = 0;  i < BITMAP_SIZE/8; i++){ 
        // the old bitmap
        for(int j = 0; j < 8; j++){
            if(old_bitmap[(8*i)+j] == 0){
                printf("[ ]"); 
            }
            else {
                printf("[x]");
            }
        }
        printf("\t\t"); 
        // the updated bitmap
        for(int j = 0; j < 8; j++){
            if(bitmap[(8*i)+j] == 0){
                printf("[ ]"); 
            }
            else {
                printf("[x]");
            }
        }
        printf("\n"); 
    }
}