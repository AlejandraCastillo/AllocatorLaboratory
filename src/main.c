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

typedef struct metadata {
    int address; 
    int size; 
    int in_use;  
} metadata;

metadata allocation_table[BITMAP_SIZE]; 

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


int main(int argc, char const *argv[])
{
    /* First Test of allocate_block() */

    int old_bitmap[BITMAP_SIZE]; 
    save_bitmap_state(old_bitmap);

    int block_size = 7;
    int address = allocate_block(block_size);
    
    
    if(address != -1){
        printf("\n\nAllocate memory");
        printf("\n\nblockSize = %d \naddress = %d\n\n", block_size, address);
        print_bitmap_comparison(old_bitmap);    
    }
    else {
        printf("\nError: Not enough space in memory.\n");
    }
    
    /* First Test of free_block() */

    save_bitmap_state(old_bitmap);  
    
    int free_result = free_block(address); 
    
    if(free_result == 1){
        printf("\n\nDesallocate memory");
        print_bitmap_comparison(old_bitmap);
    }
    else {
        if (free_result == -1)
            printf("Error: Attempted to free outside of memory bounds.\n");
        else if (free_result == 0)
            printf("Error: invalid address.\n");
    }

    return 0;
}