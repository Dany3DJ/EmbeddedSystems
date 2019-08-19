#include<stdio.h>
#include<stdlib.h>
char controls[]= {'w','s','f','x','i','k','h','p'};
/*Default controls
    0 Accelerate w
    1 Brake s
    2 Handbrakes f
    3 Switch engine on/off x
    4 Gear up i
    5 Gear down k
    6 Horn h
    7 Toggle sports mode p
 */

struct car
{
    int speed;              //current speed
    int cgear;              //current gear
    int maxspeed;           //maximum allowable speed relative to the gear
    int rpm;                //current rpm
    int enginestate;        //engine on or off
    int horn;
    int maxrpm;             //maximum rpm (default is 8000)
    int mode;
} car;


void refresh(void);
void geardown(void);
void brakes(void);
void brake(void);
void display(void);
void setmaxspeed(int x);
void gearup(void);
void horn(void);
void acc(void);
void startengine(void);
void engineoff(void);
void rpmrevup(void);
void rpmcool(void);
void rpmslowcool(void);
void delay1(void);
void delay2(void);
void sportmode(void);
void controlmenu(void);

//The function responsible for displaying the grid
void display(void)
{
    if (car.enginestate==1)
    {
        printf("Engine ON\t\t");
    }
    else if (car.enginestate==0)
    {
        printf("Engine OFF");
    }
    if (car.rpm>6500)
    {
        printf(" Warning");
    }
    printf("\n");
    printf("Gear \t Speed \t\t RPM \t\t");
    if (car.mode==1)
        printf("Sports Mode ON");
    else
        printf("Sports Mode OFF");
    if (car.horn==1)
    {
        printf("\t\t Horn ON");
    }
    printf("\n");
    for (char i=-1; i<6; i++)
    {
        if (i<0)
        {
            printf("R");
            if (i==car.cgear)
            {
                printf(" <-");
            }
            printf("\t %d Km/h \t %d",car.speed,car.rpm);
        }
        else
        {
            printf("%d",i);
            if (i==car.cgear)
            {
                printf(" <-");
            }
        }
        printf("\n");
    }

}
//Function to set the max speed allowable to current gear
void setmaxspeed(int x)
{
    switch (x)
    {
    case -1:
        car.maxspeed=30;
        break;
    case 0:
        car.maxspeed=0;
        break;
    case 1:
        car.maxspeed=50;
        break;
    case 2:
        car.maxspeed=100;
        break;
    case 3:
        car.maxspeed=150;
        break;
    case 4:
        car.maxspeed=200;
        break;
    case 5:
        car.maxspeed=250;
        break;
    }

}
//Hand brakes function
void brakes(void)
{
    while (car.speed>car.maxspeed)
    {
        car.speed--;
        refresh();
    }
}
//Gearing up
void gearup(void)
{
    if (car.cgear >0)
    {
        rpmcool();
        if (car.speed>0)
        {
            for (int i=0; i<15; i++)
            {
                car.speed=car.speed-1;
                refresh();
            }
        }
    }
    if (car.cgear == -1)
    {
        rpmcool();
        while (car.speed>0)
        {
            car.speed=car.speed-1;
            refresh();
        }
    }
    if (car.cgear<5)
    {
        car.cgear++;
        setmaxspeed(car.cgear);
        refresh();
        rpmcool();
    }
}
//Gearing down
void geardown(void)
{
    if (car.cgear>-1)
    {
        system("cls");
        car.cgear--;
        setmaxspeed(car.cgear);
        brakes();
        refresh();
    }
}
void horn(void)
{
    ;
    car.horn=1;
    refresh();
    Beep(300,1500);
    car.horn=0;
    refresh();
}
//Accelerating function
void acc(void)
{
    if (car.speed<car.maxspeed)
    {
        car.speed++;
        if (car.mode==1)
        {
            delay1();
        }
        else if (car.mode==0)
        {
            delay2();
        }

    }
    refresh();
}
//Engine start
void startengine(void)
{
    car.maxrpm = 8000;
    setmaxspeed(car.cgear);
    car.enginestate=1;
    refresh();
    for (int i=0; i<=40; i++)
    {
        car.rpm=i;
        car.rpm=car.rpm*25;
        refresh();
    }
}
//Engine off
void engineoff(void)
{
    car.enginestate=0;
    car.maxspeed=0;
    car.cgear=0;
    setmaxspeed(car.cgear);
    refresh();
    rpmslowcool();
    brakes();

}
//Building rpm
void rpmrevup(void)
{
    if (car.rpm<car.maxrpm-130)
    {
        switch (car.cgear)
        {
        case -1:
            car.rpm=car.rpm+130;
            break;
        case 0:
            car.rpm=car.rpm+110;
            break;
        case 1:
            car.rpm=car.rpm+90;
            break;
        case 2:
            car.rpm=car.rpm+75;
            break;
        case 3:
            car.rpm=car.rpm+60;
            break;
        case 4:
            car.rpm=car.rpm+45;
            break;
        case 5:
            car.rpm=car.rpm+35;
            break;
        }
        refresh();
    }

}
//cooling the rpm
void rpmcool(void)
{
    while (car.rpm>2300)
    {
        car.rpm=car.rpm-400;
        refresh();
    }
}
void rpmslowcool(void)
{
    while (car.rpm>=250)
    {
        car.rpm=car.rpm-250;
        refresh();
    }
    car.rpm=0;
    refresh();
}
void delay1(void)
{
    for (int i=0; i<500000; i++);
}
void delay2(void)
{
    for (int i=0; i<25000000; i++);
}
//Refreshing the screen
void refresh(void)
{
    system("cls");
    display();
}
//Brakes
void brake(void)
{
    if (car.speed>0)
    {
        car.speed--;
        rpmcool();
        refresh();
    }
}
void sportmode(void)
{
    if (car.mode == 0)
    {
        car.mode=1;
    }
    else if (car.mode==1)
    {
        car.mode=0;
    }
    refresh();
}
void printcontrols(void)
{
    int i=0;
    printf("Accelerate \t\t%c\n",controls[i]);
    i++;
    printf("Brake \t\t\t%c\n",controls[i]);
    i++;
    printf("Handbrakes \t\t%c\n",controls[i]);
    i++;
    printf("Switch engine on/off \t%c\n",controls[i]);
    i++;
    printf("Gear up \t\t%c\n",controls[i]);
    i++;
    printf("Gear down \t\t%c\n",controls[i]);
    i++;
    printf("Horn \t\t\t%c\n",controls[i]);
    i++;
    printf("Toggle sports mode \t%c\n",controls[i]);
    i=0;

}
void redefinecontrols(void)
{
    for (int i=0; i<8; i++)
    {
        controls[i]=' ';
    }
    system("cls");
    for (int i=0; i<8; i++)
    {
        system("cls");
        printcontrols();
        controls[i]=getch();
        system("cls");
        printcontrols();
    }
}
