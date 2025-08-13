#ifndef ALLOCATOR_H //si no esta definido... 
#define ALLOCATOR_H //... definelo 

// Funciones que cualquier allocator debe implementar
int allocate_block(int block_size);
int free_block(int block_address);

#endif