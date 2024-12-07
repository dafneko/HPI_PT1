#include <stdio.h>
#include <wchar.h>

// Definiere die Konstanten W und H
#define W 60
#define H 20
 
static unsigned long long HIDDEN_IMAGE[] = {0ULL,0ULL,0ULL,0ULL,0ULL,65536ULL,30720ULL,13933011347254272ULL,34832949279009152ULL,35959059641270848ULL,35958989276578848ULL,17873969189472224ULL,8725870814429216ULL,3940726987555392ULL,1126939293122944ULL,0ULL,0ULL,0ULL,0ULL,0ULL};
 
static int IMAGE[H][W] = { 0 };
 
// void dump_bitmap(int data[H][W]) {
//     for (int y = 0; y < H; y++)
//     {
//         for (int x = 0; x < W; x++)
//         {
//             if (data[y][x])
//                 printf("#");
//             else
//                 printf(".");
//         }
//         printf("\n");
//     }
// }
 

 void dump_bitmap(int data[H][W]) {
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if (data[y][x])
                printf("\u2588");
            else
                printf(".");
        }
        printf("\n");
    }
}

void decode_image(void) { // (I'm trying to be sneaky here)
    int i=0; // bad code style, don't do this and don't modify this!
   
    for( ; i<W*H; i++)
        ((int*)IMAGE)[i]+=(HIDDEN_IMAGE[i/W]<<(077-i % W))>>077;
}
 
int main(void) {
    decode_image();
    dump_bitmap(IMAGE);
    return 0;
}