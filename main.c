#include "airline.h"

int main()
{
	int seats[SIZE];
	int seatType, assignSeatSuccess, place, replaceSeatSuccess;
	int firstClassCtr = 1, economyCtr = 6, adios = 0;
	
	initSeats(seats, SIZE);
	do
	{
		system("cls");
		printf("Welcome to MGM Airlines!\n\n");
		displaySeats(seats, SIZE);
		
		if(firstClassCtr == 6 && economyCtr == 11)
		{
			exitmessage();
			adios = 1;
		}
		else
		{
			printf("\n\nPlease type 1 for \"first class\"");
			printf("\nPlease type 2 for \"economy\" :");
			scanf("%d", &seatType);
		
			assignSeatSuccess = assignSeat(seats, seatType);
		
			if(assignSeatSuccess == 1)
			{
				if(seatType == 1)
				{
					boardPass(firstClassCtr);
					sleep(1);
					firstClassCtr++;
				}
				else
				{
					boardPass(economyCtr);
					sleep(1);
					economyCtr++;
				}
			}
			else
			{
				if(seatType == 1)
				{
					printf("\nAll of the seats in the First Class section is already full. Is it acceptable to be placed in the Economy section? (1 for yes/any other number for no): ");
					scanf("%d", &place);
			
					if(place == 1)
					{
						replaceSeatSuccess = assignSeat(seats, 2);
						boardPass(economyCtr);
						sleep(1);
						economyCtr++;
					}
					else
					{
						exitmessage();
						sleep(1);
						adios = 1;
					}
					
				}
				else if(seatType == 2)
				{
					printf("\nAll of the seats in the Economy section is already full. Is it acceptable to be placed in the First Class section? (1 for yes/any other number for no): ");
					scanf("%d", &place);
			
					if(place == 1)
					{
						replaceSeatSuccess = assignSeat(seats, 1);
						boardPass(firstClassCtr);
						sleep(1);
						firstClassCtr++;
					}
					else
					{
						exitmessage();
						sleep(1);
						adios = 1;
					}
				}
			}
	    }	
	}while(adios == 0);
}

