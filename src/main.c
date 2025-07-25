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
    0,0,1,1,1,1,1,0, //5, 
    0,0,0,0,0,0,0,1, //8
    1,1,0,0,0,1,1,1, //3
    0,1,1,0,0,0,1,1, //3 
    1,1,1,0,0,0,0,0, //5
    1,0,0,0,0,0,0,1, //6
    1,1,1,1,1,0,0,0,
    0,0,1,1,1,1,1,0, //5, 1
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
    for(int i = 0; i < BITMAP_SIZE; i++){ //recorremos el bitmap
        if(bitmap[i] == 0){ //hasta encontrar un 0
            for(int j = 0; j < block_size; j++){ //entonces contamos ceros hasta que...
                if(bitmap[i+j] != 0){ //encontremos una celda ocupada
                    i += j; //entonces actualizamos i
                    j = block_size; //y salimos de este for 
                }
                else if (j == block_size-1){ // o hasta que tengamos un bloque del tamaño correcto
                    for(int k = 0; k < block_size; k++){ //entoences nos regresamos al incio del bloque
                        bitmap[i+k] =1; //y lo ocupamos con 1s
                    }
                    return i; //y devolvemos la direccion del bloque 
                }
            } 
        }
    }
    return -1; //no hay espacio disponible 
}


int main(int argc, char const *argv[])
{
    int old_bitmap[BITMAP_SIZE]; 
    save_bitmap_state(old_bitmap);  

    // prepare bitmap for testing
    int block_size = 7;
    int dir = allocate_block(block_size);
    
    if(dir != -1){
        printf("\n\nblockSize = %d \ndir = %d\n\n", block_size, dir);
        print_bitmap_comparison(old_bitmap);    
    }
    else {
        printf("Lo siento, no hay espacio en memoria");
    }

    return 0;
}