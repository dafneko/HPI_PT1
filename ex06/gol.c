#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
 
// Definiere die Konstanten W und H
#define W 30
#define H 10

#define FALSE 0
#define TRUE 1

#define ALIVE 1
#define DEAD 0
 
// Kopiere dump_bitmap hier hin
void dump_bitmap(int data[H][W]) {
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if (data[y][x])
                printf("\u2588");
            else
                printf(" ");
        }
        printf("\n");
    }
}
 
// Ein interessantes Start Bild
static unsigned int FUN[] = {18874371,34603011,67633152,67633152,34603012,18874373,12582918,0,805306368,817889280};
 
void initialize(int data[H][W]) { // (I'm trying to be sneaky here)
    int i=0; // bad code style, don't do this and don't modify this!
    for(;i<W*H;i++)((int*)data)[i]=(FUN[i/W]<<(037-i%W))>>037;
}

// Gibt 1 zurück wenn die Zelle an der Stelle (x, y) lebt, 0 sonst
// Nach der Torus Eigenschaft, soll diese Funktion auch Zugriffe "außerhalb" des
// Spielfelds korrekt behandeln.
int isAlive(int x, int y, int data[H][W]) {
    if (data[y][x] == ALIVE)
        return ALIVE;
    return DEAD;
}
 
// Gibt die Anzahl der lebenden Nachbar-Zellen zurück.
// int aliveNeighborCount(int x, int y, int data[H][W]) {
//     int count;

//     count = 0;
//     if (data[y][(x + 1) % W] == ALIVE)
//         count++;
//     if (data[y][(x + W - 1) % W] == ALIVE)
//         count++;
//     if (data[(y + 1) % H][x] == ALIVE)
//         count++;
//     if (data[(y + H - 1) % H][x] == ALIVE)
//         count++;
//     if (data[(y + 1) % H][(x + 1) % W] == ALIVE)
//         count++;
//     if (data[(y + H - 1) % H][(x + 1) % W] == ALIVE)
//         count++;
//     if (data[(y + 1) % H][(x + W - 1) % W] == ALIVE)
//         count++;
//     if (data[(y + H - 1) % H][(x + W - 1) % W] == ALIVE)
//         count++;            
//     return (count);
// }

int aliveNeighborCount(int x, int y, int data[H][W]) {
    int count;

    count = 0;
    for (int cur_y = -1; cur_y <= 1; cur_y++)
    {
        for (int cur_x = -1; cur_x <= 1; cur_x++)
        {
            if (cur_x == 0 && cur_y == 0)
                continue;
            if (data[(y + H + cur_y) % H][(x + W - cur_x) % W] == ALIVE)
                count++;            
        }
    }
    return (count);
}
 
// Gibt zurück, ob die Zelle an der Stelle (x, y) in der nächsten Runde am Leben
// sein soll.
int shouldBeAlive(int x, int y, int old[H][W]) {
    int neighbours;

    neighbours = aliveNeighborCount(x, y, old);
    if (isAlive(x, y, old) && neighbours >= 2 && neighbours < 4)
        return ALIVE;
    else if (!isAlive(x, y, old) && neighbours == 3)
        return ALIVE;
    return(DEAD);
}
 
// Berechne das nächste Spielfeld. In old steht das aktuelle Spielfeld, dieses
// sollte nicht verändert werden. In new soll das neue Spielfeld geschrieben
// werden.
void simulate(int old[H][W], int new[H][W]) {

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if (shouldBeAlive(x, y, old))
                new[y][x] = ALIVE;
            else
                new[y][x] = DEAD;            
        }
    }
}

int input_error(int ac, char *input)
{
    if (ac > 2)
    {
        printf("Only enter the number of times the game should be simulated.\n");
        return (EXIT_FAILURE);
    }
    if (strlen(input) > 19)
        return (EXIT_FAILURE);
    while (*input)
    {
        if (!isdigit(*input))
        {
            printf("Enter a positive integer.\n");
            return (EXIT_FAILURE);
        }
        input++;
    }
    return (EXIT_SUCCESS);
}

void run_simulation(int gen, int old[H][W], int new[H][W])
{
    while (gen > 0)
    {
        printf("\033[H\033[2J");
        simulate(old, new);
        dump_bitmap(new);
        usleep(140000);
        memcpy(old, new, sizeof(int) * H * W);
        gen--;
    }
}

int main(int argc, char* argv[]) {
    int old[H][W];
    int new[H][W];

    long long num;
    if (argc <= 1)
    {
        printf("Enter a positive integer.\n");
        return (EXIT_SUCCESS);
    }
    if (input_error(argc, argv[1]))
        return (EXIT_FAILURE);
    num = atoll(argv[1]);
    initialize(old);
    dump_bitmap(old);
    run_simulation(num, old, new);
    return 0;
}