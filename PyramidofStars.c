#include <stdio.h>
#include <windows.h>

int main(void)
{

    int rows, cols, num;

    printf("Enter the number of rows you want:");
    scanf("%d", &num);

    printf("Printing...\n");
    Sleep(2500);
    system("cls");

    for (rows = 1; rows <= num; rows++)
    {
        for (cols = 1; cols <= 2*num-1; cols++) 
        {
            if (cols >= num - (rows - 1) && cols <= num + (rows -1))
            {
             printf("+");
            }
            else
            {
             printf(" ");
            }
        
        }
       printf("\n");
    }
    return 0;
}