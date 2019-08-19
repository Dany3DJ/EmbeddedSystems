#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Car.h"
extern char controls[];

void main()
{
mainmenu:
    system("cls");
    printf("Press %c to start the engine \n",controls[3]);
    printf("Press C to go to controls menu \n\n");
    display();
    if (getch()=='c')
    {
        system("cls");
        printf("Press E to redefine controls \n");
        printf("Press Q to quit controls menu \n\n");
        printcontrols();
        if (getch() == 'e')
        {
            redefinecontrols();
            goto mainmenu;
        }
        if (getch()=='q')
        {
            goto mainmenu;
        }
    }
    if (getch()== controls[3])
    {
        startengine();
        while (1)
        {
            if (getch()== controls[7])
            {
                sportmode();
            }

            if (getch()== controls[6])
            {
                horn();
            }
            if (getch() == controls[4])
            {
                gearup();
            }
            if (getch() == controls[5])
            {
                geardown();
            }
            if (getch()== controls[3])
            {
                engineoff();
                delay1();
                goto mainmenu;
            }
            if (getch()== controls[2])
            {
                brakes();
            }
            while (getch() == controls[0])
            {
                acc();
                rpmrevup();
            }
            while (getch()== controls[1])
            {
                brake();
            }
        }
    }

}
