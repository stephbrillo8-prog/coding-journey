#include <stdio.h>

    int main(){
        
    int age;
    double height;
    float weight;
    char measure;
    float bmi;

    printf("Metric or Imperial?(M/I) ");
    scanf(" %c", &measure);

    if (measure == 'm' || measure == 'M') 
    {
        printf("Enter your age: "); 
        scanf("%d", &age);
        printf("Your age is %d years.\nNow type your height in meters: \n", age);
        scanf("%lf", &height);
        printf("Your height is %.2lf meters.\nNow type your weight:\n", height);
        scanf("%f", &weight);
        printf("Your weight is %.2f kilograms.\n", weight);
        bmi = weight / (height * height);
        printf("Your BMI is %f\n", bmi);
    }

    else if (measure == 'i' || measure == 'I')
    {
        printf("Enter your age: "); 
        scanf("%d", &age);
        printf("Your age is %d years.\nNow type your height in inches: \n", age);
        scanf("%lf", &height);
        printf("Your height is %.2lf inches.\nNow type your weight in lbs:\n", height);
        scanf("%f", &weight);
        printf("Your weight is %.2f lbs.\n", weight);
        bmi = weight * 703 / (height * height);
        printf("Your BMI is %f\n", bmi);
    }

    else 
        {
            printf("You have entered the wrong information.\n");
        }

    return 0;    
}