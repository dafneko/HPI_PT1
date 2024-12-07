#include <stdio.h>
#include <stdbool.h>

typedef enum coor
{
    lx1 = 2,
	rx1 = 6,
	ty1 = 2,
	by1 = 5,
 
	lx2 = 4,
	rx2 = 8,
	ty2 = 3,
	by2 = 7
} size;

bool is_in_rect(int x, int y, int lx, int ty, int rx, int by)
{
    if ((x >= lx && x <= rx) && (y >= ty && y <= by))
        return true;
	return false;
}


/*
    The first approach allows the overlapping part to be printed.
    It only needs to put spaces between the empty coordinates, 
    like (0,0) and (1,1). We use the OR logic gate to ensure asterisks are
    printed within the coordinates of both rectangles but not the empty space.
    With the second shape, we want to replace the overlapping part of the two rectangles
    with spaces instead. That's why I use the AND logic gate, since it's true only 
    when the point lies within both coordinates - just like in the Venn diagrams of 
    both logic gates.
    
    I additionally use a boolean variable "layover" as part of the condition, 
    so the same function can handle both cases with just one extra variable. 
    If the user allows overlap, it's set to true. Since we want to skip the first if condition, 
    layover is negated with NOT (!layover == 0), so the condition will only be met when 
    layover is not allowed,!layover == 1.
*/
void print_rect(int width, int height, bool layover)
{
        for (int y = 0; y <= height; y++)
        {
            for (int x = 0; x <= width; x++)
            {
                if (!layover && (is_in_rect(x, y, lx1, ty1, rx1, by1) && is_in_rect(x, y, lx2, ty2, rx2, by2)))
                    printf(" ");
                else if (is_in_rect(x, y, lx1, ty1, rx1, by1) || is_in_rect(x, y, lx2, ty2, rx2, by2))
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
}

int main()
{
    /*
	int lx1 = 2;
	int rx1 = 6;
	int ty1 = 2;
	int by1 = 5;
 
	int lx2 = 4;
	int rx2 = 8;
	int ty2 = 3;
	int by2 = 7;
    */

    print_rect(10, 10 , true);
    print_rect(10, 10, false);
	return 0;
}
