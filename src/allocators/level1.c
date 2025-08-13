#include "level1.h"

int allocate_block(int block_size){

    //verify that the size is valid
    if(block_size > BITMAP_SIZE || block_size < 1){
        return -2; //invalid size
    }

    // Traverse bitmap looking for free spaces
    for(int i = 0; i < BITMAP_SIZE; i++){ 
        if(bitmap[i] == 0){ 
            // Check if the free block has the right size
            for(int j = 0; j < block_size; j++){ 
                if(bitmap[i+j] != 0){ 
                    i += j; 
                    j = block_size; 
                }
                else if (j == block_size-1){
                    // Mark the block as occupied
                    for(int k = 0; k < block_size; k++){ 
                        bitmap[i+k] = 1; 
                    }
                    if(save_address(i, block_size)==-1){
                        return -1; // No space available
                    } 
                    return i; // Return the starting address
                }
            } 
        }
    }
    return -1; // No space available
}


int free_block(int block_address){

    int block_size = get_data_size(block_address); 

    if (block_size < 1 || block_size > BITMAP_SIZE){
        return 0; // invalid address
    }

    if(block_address < 0 || block_address+block_size-1 > BITMAP_SIZE){
        return -1; //goes out of bounds of the bitmap
    }

    if(free_address(block_address)==-1){
        return -1; // No address found 
    } else {
        for (int i = 0; i < block_size; i++){
            bitmap[block_address + i] = 0;  
        }
    }

    return 1; //all good
}
