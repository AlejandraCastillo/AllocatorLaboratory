#ifndef ALLOCATION_TABLE_H //si no esta definido... 
#define ALLOCATION_TABLE_H //... definelo 

#include "bitmap.h"

typedef struct metadata {
    int address;
    int size;
    int in_use;
} metadata; //se define desde aqui

extern metadata allocation_table[BITMAP_SIZE]; //debe definirse despues 

//firmas 
int save_address(int address, int size);
int free_address(int address);
int get_data_size(int address);

#endif //cierra la declaracion 