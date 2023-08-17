#include <stdio.h>
#include <stdlib.h>

#define FEET_PER_ATMOSPHERE 33 //Feet per atmosphere constant
#define MAXIMAL_OXYGEN 1.4 //Maximal O2 pressure
#define CONTINGENCY_OXYGEN 1.6 //Contingency O2 pressure

int main(void) {

	int Depth, O2Percent;
	float AmbientPressure, O2Pressure;
	char O2Group;

	//Prompt user to input depth and O2 percentage
	printf("Enter depth and percentage O2\t: ");
	scanf("%d %d", &Depth, &O2Percent);

	//Calculate  ambient pressure, O2 pressure and group
    	AmbientPressure = (Depth/FEET_PER_ATMOSPHERE) + 1;
	O2Pressure = ((float)O2Percent/100) * AmbientPressure;
	O2Group = (char)((int)(O2Pressure * 10) + 'A');

	//Print calculated results
	printf("\nAmbient pressure\t\t: %.1f", AmbientPressure);
	printf("\nO2 pressure\t\t\t: %.2f", O2Pressure);
	printf("\nO2 group\t\t\t: %c", O2Group);

	/* Print true if calculated O2 pressure exceeds maximal O2 pressure 
	and contingency O2 pressure, false if it does not */  
	printf("\n\nExceeds maximal O2 pressure\t: ");
	printf("%s", (O2Pressure > MAXIMAL_OXYGEN) ? "true" : "false");
	printf("\nExceeds contingency O2 pressure : ");
	printf("%s", (O2Pressure > CONTINGENCY_OXYGEN) ? "true" : "false");

	return(EXIT_SUCCESS);

}
