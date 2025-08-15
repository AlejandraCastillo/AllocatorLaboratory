#include "unity.h"
#include "../src/core/utils.h"
#include "../src/core/bitmap.h"

int bitmap_copy[BITMAP_SIZE] = {
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

void setUp(void) {
    for(int i = 0; i < BITMAP_SIZE; i++){
        bitmap[i] = bitmap_copy[i]; 
    }
}

void tearDown(void) {
    // Limpia después de cada test si quieres
}

void test_save_bitmap_state_copia_correctamente(void) {
    
    int copy_dest[BITMAP_SIZE];

    // Ejecutar la función
    save_bitmap_state(copy_dest);

    // Verificar que copy_dest y bitmap tengan lo mismo
    for (int i = 0; i < BITMAP_SIZE; i++) {
        TEST_ASSERT_EQUAL_INT(bitmap[i], copy_dest[i]);
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_save_bitmap_state_copia_correctamente);
    return UNITY_END();
}
