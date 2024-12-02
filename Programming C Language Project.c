#include <stdio.h>

int main()
{
    double lengthofyard;
    double widthofyard;
    double lengthofhouse;
    double widthofhouse;
    double yard;
    double house;
    double totalarea;
    double cuttingrate;
    double timerequire;

    start:

    printf("Welcome to C Programming Project\n");
    printf("--------------------------------\n");
    printf("Developers : Vansh Thakur | Prajwal Chahuhan\n");
    printf("--------------------------------\n");

    printf("This System will do the following work : \n");
    printf("program that takes the length and width of a rectangular yard\n");
    printf("and the length and width of a rectangular house situated in the yard.\n");

    printf("Enter the Length of the yard (in feet) : ");
    scanf("%lf", &lengthofyard);

    printf("Enter the Width of the yard (in feet) : ");
    scanf("%lf", &widthofyard);

    printf("Enter the Length of the house (in feet) : ");
    scanf("%lf", &lengthofhouse);

    printf("Enter the Width of the house (in feet) : ");
    scanf("%lf", &widthofhouse);

    yard = lengthofyard * widthofyard;
    house = lengthofhouse * widthofhouse;

    totalarea = yard - house;

    if(totalarea < 0)
    {
        printf("Error : House area can't be larger than Yard Area. Please Fill the details again as per requirements.\n");
        goto start;
    }

    printf("Input the Time Required for grass cutting (square feet per second ) : ");
    scanf("%lf", &cuttingrate);

    timerequire = totalarea / cuttingrate;

    printf("Time Required to cut the grass field : %.2lf seconds \n", timerequire);

    int choice;
    printf("To Re-Use this system, Kindly Type 1 and Enter. Otherwise, Type 2 to Exit the Program");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
                {
                    printf("Thanks for choosing the option. Restarting the program again\n\n");
                    goto start;
                }
        case 2:
                {
                    printf("Program has been ended successfully");
                    goto end;
                }
        end:
        return 0;
    }

}