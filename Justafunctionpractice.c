#include <stdio.h>

    void sklubdub(char name[50]) 
    {
        printf("\n");
        printf("Happy Birthday to you!\n");
        printf("Happy Birthday to you!\n");
        printf("Happy Birthday, dear %s", name);
        printf("Happy Happy Birthday to you!!!\n");
    }

    int main() {
    int i, j;
    char name[50]; 

    printf("What is the name of the birthday celebrant?\n");
    fgets(name, sizeof(name), stdin);
    
    printf("How many greetings do you want?\n");
    scanf("%d", &i);

    for (j = 1; j <= i; j++)
    {
        sklubdub(name);
    }
   
return 0;
}