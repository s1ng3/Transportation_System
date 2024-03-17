#include "bus_transport.h"

void discount()
{
    printf("What year were you born?\n");
    int birth;

    do {
        scanf("%d",&birth);
        if(birth>2016)
        printf("Haha, nice joke, now tell me your real age.");
    } while(birth>2016);

    if(2022-birth<18)
        printf("Oh, you are a pupil. You enter free.");
    else if(2022-birth>=18 && 2022-birth<65)
        printf("Ah, I see you are an adult. You have to pay the full price ticket.");
    else if(2022-birth>=65)
        printf("I see you are an elder. You enter free.");

}

void creating_bus(int a[21][5],int v)
{
    printf("\n~~~~~~~~~~~~~~~~~\n");

    for(int i=1; i<=20; i++)
    {
        printf("| ");
        for(int j=1; j<=4; j++)
        {
            if(a[i][j]==9)
                printf(" ");
            else if(a[i][j]==1 || a[i][j]==5)
                printf(" ");
            else if(a[i][j]==6 || a[i][j]==2)
                printf(" ");
            else if(a[i][j]==3 || a[i][j]==7)
                printf(" ");
            else if(a[i][j]==4 || a[i][j]==8)
                printf(" ");
            else if(a[i][j]==0)
                printf(" ");

            if(j%2==0 && j!=4)
                printf("%d   ",a[i][j]);
            else
                printf("%d ",a[i][j]);
        }
        printf("|");

        printf("\n");
    }
    printf("~~~~~~~~~~~~~~~~~\n\n");
}

void numbering_seats(int a[21][5], int v)
{
    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=4; j++)
            a[i][j]=i+j-v;
        v-=3;
    }
}

int check(int a[21][5], int seat)
{
    int rest=seat%4;
    int cat=seat/4;

    if(rest%4==0)
    {
        rest=4;
        cat--;
    }

    if(a[cat+1][rest]==0)
        return 0;
    a[cat+1][rest]=0;

    return 1;
}

void run_bus_transport()
{
    int a[21][5]= {0},v=1,seat;
    char choice,c2;

    numbering_seats(a,v);

    printf("Hello stranger, welcome to our bus! Would you like to reserve a seat? (y/n)\n");

    scanf("%c",&choice);
    discount();
    while (choice == 'y')
    {
        creating_bus(a,v);
        printf("Which seat would you like to reserve?\n");
        printf("I would like to reserve the seat with the number: ");
        scanf("%d",&seat);

        if(check(a,seat))
        {
            printf("\nSeat available. Thank you for your reservation.\n");
            creating_bus(a,v);
            printf("Would you like to reserve another seat?(y/n)\n");
            scanf(" %c",&choice);

        }
        else
            printf("\n Unfortunately that seat is unavailable.");
    }
    if(choice=='n')
        printf("\nAlright then, see you next time. :) \n");
}

void ticket_man();