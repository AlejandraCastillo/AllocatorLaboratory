#include <stdio.h>

#define BITMAP_SIZE 128 
int bitmap[BITMAP_SIZE] = {
    1,1,0,1,1,1,0,0, //1, 2
    1,0,0,0,0,0,0,1, //6
    1,1,0,0,0,1,1,1, //3
    0,1,1,0,0,0,1,1, //3 
    1,1,1,0,0,0,0,0, //5
    1,0,0,0,0,0,0,1, //6
    1,1,1,1,1,0,0,0,
    1,1,0,0,0,1,1,1, //3
    0,1,1,0,0,0,1,1, //3 
    1,1,1,0,0,0,0,0, //5
    1,0,0,0,0,0,0,1, //6
    1,1,1,1,1,0,0,0,
    0,0,1,1,1,1,1,0, //5, 1
    1,1,0,0,0,1,1,1, //3
    0,0,1,1,1,1,1,0, //5, 
    0,0,0,0,0,0,0,1, //8
};

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

void save_bitmap_state(int copy_dest[]){
    // copy de actual state of the bitmap
    for (int i = 0; i < BITMAP_SIZE; i++) {
        copy_dest[i] = bitmap[i];
    }
}

int allocate_block(int block_size){
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
                    return i; // Return the starting address
                }
            } 
        }
    }
    return -1; // No space available
}


int free_block(int block_dir, int block_size){
    if(block_dir+block_size-1 > BITMAP_SIZE){
        return -1; //goes out of bounds of the bitmap
    }

    if(bitmap[block_dir] == 0){
            return 1; //at least the start of the block is already free
    }

    for (int i = 0; i < block_size; i++){
        bitmap[block_dir + i] = 0;  
    }

    return 0; //all good
}


int main(int argc, char const *argv[])
{
    /* First Test of allocate_block() */

    int old_bitmap[BITMAP_SIZE]; 
    save_bitmap_state(old_bitmap);

    int block_size = 7;
    int dir = allocate_block(block_size);
    
    
    if(dir != -1){
        printf("\n\nAllocate memory");
        printf("\n\nblockSize = %d \ndir = %d\n\n", block_size, dir);
        print_bitmap_comparison(old_bitmap);    
    }
    else {
        printf("\nError: Not enough space in memory.\n");
    }
    
    /* First Test of free_block() */

    save_bitmap_state(old_bitmap);  
    
    int free_result = free_block(dir, block_size); 
    
    if(free_result == 0){
        printf("\n\nDesallocate memory");
        print_bitmap_comparison(old_bitmap);
    }
    else {
        if (free_result == -1)
            printf("Error: Attempted to free outside of memory bounds.\n");
        else if (free_result == 1)
            printf("Error: Block is already free.\n");
    }

    return 0;
}