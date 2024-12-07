#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum selection
{
    end,
    scissors,
    rock,
    paper
 } selection;
 
enum gameResult
{
    draw,
    win,
    loose
 };
 
enum gameResult game(enum selection player, enum selection computer)
{
    if (computer == player)
        return draw;
    switch (player)
    {
    case scissors:
        if (computer == paper)
            return win;
        return loose;
    case rock:
        if (computer == scissors)
            return win;
        return loose;         
    case paper:
        if (computer == rock)
            return win;        
        return loose;
    // default case should never happen. Still the Compiler demands all cases to be handled:
    default:
        return -1;
    }
}
 
int main(void)
{
    srand(time(NULL));
    printf("Anleitung:\n0 = Beenden, 1 = Schere, 2 = Stein, 3 = Papier\n");
    int computer, selection;
 
    do
    {
        printf("Aktion? ");
        fflush(stdout);
        scanf("%d", &selection);
 
        if (selection < 0 || selection > 3)
        {
            printf("Ungültige Eingabe!\n");
            continue;
        }
 
        if (selection != end)
        {
            computer = 1 + rand() % 3;
 
            enum gameResult result = game(selection, computer);
            printf("computer action: %i\n", computer);
            switch (result)
            {
            case loose:
                printf("Du hast verloren!\n");
                break;
            case win:
                printf("Du hast gewonnen!\n");
                break;
            case draw:
                printf("Unentschieden!\n");
                break;
            }
        }
    } while (selection != 0);
 
    return 0;
}