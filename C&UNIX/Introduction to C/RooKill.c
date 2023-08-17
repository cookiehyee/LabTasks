#include <stdio.h>
#include <stdlib.h>

#define AUS_ROAD_WIDTH 0.01 //Average Australian road width
#define ROAD_KILL_CONSTANT 1.47 //Roadkill probability constant

int main(void) { //Main function

	int NumRoos;
	float RoadLength, SquareLength;
	float RooDensity, RoadArea, NumKills; //Variables to be calculated

	//Prompt user to enter side of square in km
	printf("Enter side of square in km  : ");
	scanf("%f", &SquareLength);

	//Prompt user to enter road length in km
	printf("Enter roads length in km    : ");
	scanf("%f", &RoadLength);

	//Prompt user to enter number of kangaroos
	printf("Enter number of 'roos       : ");
	scanf("%d", &NumRoos);

	//Calculation for kangaroo density
	RooDensity = (SquareLength * SquareLength) / NumRoos;

	//Calculation for road surface area
	RoadArea = RoadLength * AUS_ROAD_WIDTH;

	//Calculation for expected number of kangaroo kills
	NumKills = (RoadArea/RooDensity) * ROAD_KILL_CONSTANT;
	
	//Print calculated expected number of kangaroo kills with one decimal place
	printf("Expected number of kills is : %.1f", NumKills);

	return(EXIT_SUCCESS); //Return EXIT_SUCCESS

}
