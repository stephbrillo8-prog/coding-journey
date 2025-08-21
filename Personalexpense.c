#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void showmenu() 
{
    printf("Personal Expense Tracker\n");
    printf("Please choose an option:\n");
    printf("\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expenses\n");
    printf("4. Exit\n");
}

void buffer()
{
    while (getchar() != '\n'); 
}

int main()
{

    int options;
    int count = 0;
    char prodname[50][50];
    double price[50];
    int categories[50];
    int len, i;

    do 
    {
        showmenu();
        scanf("%d", &options);
        buffer();

        switch (options) 
        {
            case 1:
            if (count < 50) 
            {
                printf("Please enter the name of the product: ");
                fgets(prodname[count], sizeof(prodname[count]), stdin);
               
                if (strlen(prodname[count]) > 0 && prodname[count][strlen(prodname[count]) - 1] == '\n')
                {
                    prodname[count][strlen(prodname[count]) - 1] = '\0';
                }

                printf("Please enter the price of the product: ");
                scanf("%lf", &price[count]);
                buffer();

                printf("Choose the category:\n");
                printf("1. Food, 2. Travel, 3. Shopping 4. Bills, 5. Others\n");
                scanf("%d", &categories[count]);
                buffer();

                if (categories[count] < 1 || categories[count] > 5)
                {
                printf("invalid category. please try again.\n"); 
                continue;
                }
                count++;
                printf("Expense added successfully!");
            }
            else
            {
                printf("You have exceeded the maximum amount of expenses.\n");
            }
            break;

            case 2:
            if (count == 0) 
            {
                printf("No expenses to show.\n");
            } 
            else 
            {
                printf("Expenses:\n");
                for (i = 0; i < count; i++) 
                {
                printf("%d. %s - %.2lf (Category: %d)\n", i + 1, prodname[i], price[i], categories[i]);
                }
            }   
            break;

            case 3:
            printf("This feature is yet to be implemented, thank you!\n");
            break;

            case 4: 
            printf("Exiting program now. Goodbye!");
            break;
        }
    }while (options != 4);

return 0; 
}
