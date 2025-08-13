#include "allocation_table.h"

metadata allocation_table[BITMAP_SIZE] = {0}; 

int save_address(int address, int size){
    for(int i = 0; i < BITMAP_SIZE; i++){
        if(allocation_table[i].in_use == 0){
            allocation_table[i].address = address; 
            allocation_table[i].size = size; 
            allocation_table[i].in_use = 1; 
        }
        return 1; // Successful operation
    }
    return -1; // No space available
}

int free_address(int address){
    for(int i = 0; i < BITMAP_SIZE; i++){
        if(allocation_table[i].address == address){
            allocation_table[i].in_use = 0; 
        }
        return 1; // Successful operation
    }
    return -1; // No address found 
}


int get_data_size(int address){
    for(int i = 0; i < BITMAP_SIZE; i++){
        if(allocation_table[i].address == address && allocation_table[i].in_use == 1){
            return allocation_table[i].size; 
        }
    }
    return -1; // No address found 
}
