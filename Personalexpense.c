#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show_menu() 
{
  printf(" ________________________________  \n");
  printf("|| **Personal Expense Tracker**  ||\n");
  printf("||   Please choose an option:    ||\n");
  printf("||                               ||\n");
  printf("||     1. Add Expense            ||\n");
  printf("||     2. View Expenses          ||\n");
  printf("||     3. Delete Expenses        ||\n");
  printf("||     4. Exit                   ||\n");
  printf("||_______________________________||\n");
}

void buffer()
{
    while (getchar() != '\n'); 
}

void delete_expense(double price[], int categories[], char prodname[][50], int delete_choice, int *pCount)
{
    if (delete_choice < 0 || delete_choice >= *pCount)
    {
        printf("Invalid number of entries found.");
        return;
    }  
    for (int i = delete_choice; i < *pCount - 1; i++)
    {
        strcpy(prodname[i], prodname[i + 1]);
        price[i] = price[i + 1];
        categories[i] = categories[i + 1];
    }
    (*pCount)--;
    printf("Expense has been deleted.\n");  
    return;
}

int main()
{
    int options;
    int count = 0;
    int *pCount = &count;
    char prod_name[50][50];
    double price[50];
    int categories[50];
    char *category_name[] = {"Food", "Travel", "Shopping", "Bills", "Others"};    
    int i;

    do 
    {
        show_menu();
        scanf("%d", &options);
        buffer();

        switch (options) 
        {
            case 1:
            if (count < 50) 
            {
                printf("Please enter the name of the product: ");
                fgets(prod_name[count], sizeof(prod_name[count]), stdin);
               
               if (strlen(prod_name[count]) > 0 && prod_name[count][strlen(prod_name[count]) - 1] == '\n')
               {
                   prod_name[count][strlen(prod_name[count]) - 1] = '\0';
               }

                printf("Please enter the price of the product: ");
                scanf("%lf", &price[count]);
                buffer();
              
              do{
                  printf("Choose the category:\n");
                  printf("1. Food, 2. Travel, 3. Shopping 4. Bills, 5. Others\n");
                  scanf("%d", &categories[count]);
                  buffer();

                  if (categories[count] < 0 || categories[count] > 5)
                  {
                    printf("Invalid Category!\n");
                  }
                }
              while (categories[count] < 1 || categories[count] > 5);
           
                count++;
                printf("Expense added successfully!\n");
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
                    printf("%d. %s - %.2lf (Category: %s)\n", i + 1, prod_name[i], price[i], category_name[categories[i] - 1]);
                }
            } 
            break;

            case 3:
            if (count == 0)
            {
                printf("No expenses to delete.");
                break;
            }

            printf("\nYour Current Expenses:\n");
                for (i = 0; i < count; i++) 
                {              
                    printf("%d. %s - %.2lf (Category: %s)\n", i + 1, prod_name[i], price[i], category_name[categories[i] - 1]);
                }

            int delete_choice;
            printf("Choose a number that you want deleted:\n");
            scanf("%d", &delete_choice);
            buffer();
            
            if (delete_choice < 1 || delete_choice > count)
            {
                printf("Invalid Input!\n");
            }
            else
            {
             delete_expense(price, categories, prod_name, delete_choice - 1, pCount);
            }

            break;

            case 4: 
            printf("Exiting program now. Goodbye!");
            break;
        }
    }
    while (options != 4);
return 0; 
}
