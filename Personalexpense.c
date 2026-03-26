#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Personal Expense Tracker in C - Built using C standard - Brillo

To implement:
1. Total expenses and category-wise expenses? - DONE
2. Date and time of expense? - To be implemented,  Seen as comments in structs
3. amount of expenses - DONE 
4. Save to file and load from file? - To be implemented, Seen as comments in main function
5. Dynamic memory allocation for expenses - To be implemented

To learn:
1. Structs 
2. Linked lists for dynamic memory allocation, deletion and insertion of expenses
3. malloc and free functions for dynamic memory allocation
*/

typedef struct 
{
    char prod_name[50];
    double price;
    int categories;
  //  Date date;
} Expense;

/*typedef struct 
{
    int day;
    int month;
    int year;
} Date;*/

void show_menu() 
{
  printf(" _________________________________ \n");
  printf("||                               ||\n");
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

int delete_expense(Expense expenses[], int delete_choice, int *pCount)
{
    if (delete_choice < 0 || delete_choice >= *pCount)
    {
        return 0;
    }  
    for (int i = delete_choice; i < *pCount - 1; i++)
    {
        expenses[i] = expenses[i + 1];
    }
    (*pCount)--;
    return 1;
}

int main()
{
    //FILE *file = fopen("expenses.txt", "a+");
    int options;
    Expense expenses[50];
    int count = 0;
    int *pCount = &count;
    char *category_name[] = {"Food", "Travel", "Shopping", "Bills", "Others"};    
    int i;
    double total_expenses = 0.0;
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
                fgets(expenses[count].prod_name, sizeof(expenses[count].prod_name), stdin);
               
                if (strlen(expenses[count].prod_name) > 0 && expenses[count].prod_name[strlen(expenses[count].prod_name) - 1] == '\n')
                {
                    expenses[count].prod_name[strlen(expenses[count].prod_name) - 1] = '\0';
                }

                do
                {
                  printf("Please enter the price of the product: ");
                  scanf("%lf", &expenses[count].price);
                  buffer();
                      
                  if (expenses[count].price >= 0)
                  {
                    break;
                  }
                    printf("Price can only be in numbers!");
                }
                while (expenses[count].price < 0);
                
                do
                {
                    printf("Choose the category:\n");
                    printf("1. Food, 2. Travel, 3. Shopping 4. Bills, 5. Others\n");
                    scanf("%d", &expenses[count].categories);
                    buffer();
  
                    if (expenses[count].categories < 0 || expenses[count].categories > 5)
                    {
                      printf("Invalid Category!\n");
                    }
                }
                while (expenses[count].categories < 1 || expenses[count].categories > 5);
           
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
                    printf("%d. %s - %.2lf (Category: %s)\n", i + 1, expenses[i].prod_name, expenses[i].price, category_name[expenses[i].categories - 1]);
                } 
            } 

            for (i = 0; i < count; i++)
            {
             total_expenses += expenses[i].price;
            }

            printf("Total Expenses: %.2lf\n", total_expenses);
            printf("Number of Expenses: %d\n", count);
            total_expenses = 0.0;
            
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
                    printf("%d. %s - %.2lf (Category: %s)\n", i + 1, expenses[i].prod_name, expenses[i].price, category_name[expenses[i].categories - 1]);
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
                if (delete_expense(expenses, delete_choice - 1, pCount) == 1)
                {
                    printf("Expense has been deleted.\n");
                }
                else
                {
                    printf("Invalid number of entries found.");
                }
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
