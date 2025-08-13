#include <stdio.h>
#include "core/bitmap.h"
#include "core/utils.h"
#include "allocators/level1.h"


int main()
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