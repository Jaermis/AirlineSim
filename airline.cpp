#include<stdio.h>
#include"testing.h"

void initSeats(int seats[], int size) // initialize seats to 0
{
	int i;
	
	for(i = 0;i < size; i++)
		seats[i] = 0;
}

void displaySeats(int seats[], int size) // displays seats
{
	int i;
	
	printf("First Class Section: ");
	for(i = 0; i < (size/2); i++)
	{
		printf("[%d] ", seats[i]);
	}
	printf("\nEconomy Section:     ");
	for(i = (size/2); i < size; i++)
	{
		printf("[%d] ", seats[i]);
	}
}

int assignSeat(int st[], int seatType) //assigns seats
{
	int firstClass, economyClass;
	
		if(seatType == 1)
		{
			firstClass = assignFirstClass(st, 10);
		
			if(firstClass != -1)
				return 1;
			else
				return 0;
		
		}
		else if(seatType == 2)
		{
			economyClass = assignEconomy(st, 10);
				
			if(economyClass != -1)
				return 1;
					else
				return 0;
		}
}


int assignFirstClass(int seats[], int size) //assigns in first class seats
{
	int i, noSeat = 0;
	
	for(i = 0; i < 5; i++)
	{
		if(seats[i] == 0)
		{
			noSeat = 0;
			seats[i] = 1;
			return i;
		}
		else
			noSeat = 1;
	}
	
	if(noSeat == 1)
		return -1;
}

int assignEconomy(int seats[], int size) //assigns in economy seats
{
	int i, noSeat = 0;
	
	for(i = 5; i < 10; i++)
	{
		if(seats[i] == 0)
		{
			noSeat = 0;
			seats[i] = 1;
			return i;
		}
		else
			noSeat = 1;
	}
	
	if(noSeat == 1)
		return -1;
}

void boardPass(int seat) //prints board pass
{
	if(seat < 5)
		printf("\n\nBoarding Pass\nFirst Class Section\nSeat#%d\n\n", seat);
	else
		printf("\n\nBoarding Pass\nEconomy Section\nSeat#%d\n\n", seat);
}

void exitmessage() // exit message
{
	printf("Sorry. All of the seats are already taken, or your desired seat is already full. Thank You For Visiting MGM Airlines. Mabuhay!\n\n");
}

