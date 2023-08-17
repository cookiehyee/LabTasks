#include <stdio.h>
#include <stdlib.h>

#define HIGH_RATE 0.25 //High tax rate for stinking rich and quite rich tax groups
#define MEDIUM_RATE 0.10 //Medium tax rate for miami rich tax group
#define LOW_RATE 0.03 //Low tax rate for the average and realistic tax groups 
#define MAXIMAL_TAX 50000 //Maximal tax amount 

//Function prototypes 
void inputIncomeDeductions(float *Income, float *Deductions);
float computeTaxableIncome(float Income, float Deductions);
char chooseTaxGroup(float TaxIncome);
float computeTax(char Group, float TaxIncome);
void displayOutput(float Income, float Deductions, float TaxIncome, char Group, float Tax);

int main(void) { 

	float Income, Deductions;
	float TaxableIncome, Tax;
	char TaxGroup;

	//Prompt user to input income and deductions
	inputIncomeDeductions(&Income, &Deductions);

	//Compute taxable income based on income and deductions
	TaxableIncome = computeTaxableIncome(Income, Deductions);
	
	//Choose tax group based on taxable income
	TaxGroup = chooseTaxGroup(TaxableIncome);

	//Compute tax owed based on tax group and taxable income 
	Tax = computeTax(TaxGroup, TaxableIncome);

	//Display user tax details
	displayOutput(Income, Deductions, TaxableIncome, TaxGroup, Tax);
	
	return(EXIT_SUCCESS);
	
}

//Function to prompt user to input income and deductions
void inputIncomeDeductions(float *Income, float *Deductions) {

	float Amount;	

	//Prompt user to input income or deduction amount
	printf("Enter next amount : ");
	scanf("%f", &Amount);

	while(Amount != 0) { //While user input is not 0
		
		if (Amount > 0) { //Increment income by input if it is positive
			*Income += Amount; 
		}

		else { //Increment deductions by absolute value of input if it is negative
			*Deductions += (Amount * -1); //Multiply by -1 to get absolute value
		}

		//Prompt user to input the next income or deduction amount
		printf("Enter next amount : ");
 		scanf("%f", &Amount);

	}

}

//Function to compute and return taxable income based on income and deductions
float computeTaxableIncome(float Income, float Deductions) {

	if(Income >= Deductions) { //If income is greater than deductions
		return (Income - Deductions); //Taxable income = income - deductions
	}

	return 0; //Return 0 otherwise 

}

//Function to choose and return tax group based taxable income
char chooseTaxGroup(float TaxIncome) {
	
	//Stinking rich if taxable income is greater than or equal to $500000
	if (TaxIncome >= 500000) { 
		return 'S';
	}

	//Quite rich if taxable income is greater than or equal to $200000
	else if (TaxIncome >= 200000) { 
		return 'Q';
	} 

	//Miami rich if taxable income is greater than or equal to $100000
	else if (TaxIncome >= 100000) {
		return 'M';
	}
	
	//Average tax group if taxable income is greater than or equal to $50000
	else if (TaxIncome >= 50000) {
		return 'A';
	}

	//Realistic tax group if taxable income is greater than or equal to $20000
	else if (TaxIncome >= 20000) {
		return 'R';
	}

	//Poor tax group if taxable income is lesser than $20000
	else { 
		return 'P';
	}

}

//Function to compute and return tax owed based on tax group and taxable income 
float computeTax(char Group, float TaxIncome) {

	float TaxOwed = 0; //Tax owed initalized to 0

	//Calculate tax owed based on diferent tax rates depending on tax group
	switch(Group) {

		case 'S': //Stinking rich  
		case 'Q': //Quite rich 
			TaxOwed = TaxIncome * HIGH_RATE; //Apply high tax rate
			break;

		case 'M': //Miami rich
			TaxOwed = TaxIncome * MEDIUM_RATE; //Apply medium tax rate
			break;

		case 'A': //Average tax group
		case 'R': //Realistic tax group
			TaxOwed = TaxIncome * LOW_RATE; //Apply low tax rate
			break;

		case 'P': //Poor tax group
			break; //Amount of tax owed is unchanged at $0

		default: 
			printf("Error!\n"); //Print error if tax group does not exist
	
	}

	//If tax owed exceeds maximal tax amount of $50000
	if (TaxOwed > MAXIMAL_TAX) {
		TaxOwed = MAXIMAL_TAX; //Update tax owed to the maximal tax amount
	}

	return TaxOwed; //return computed amount of tax owed

}


//Function to display output of income, deductions, taxable income, tax group and tax owed
void displayOutput(float Income, float Deductions, float TaxIncome, char Group, float Tax) {

	printf("\nIncome         = $%9.2f", Income); //Print user income
        printf("\nDeductions     = $%9.2f", Deductions); //Print user deductions
        printf("\nTaxable income = $%9.2f", TaxIncome); //Print user taxable income
        printf("\nTax group      = %c", Group); //Print user tax group
        printf("\nTax owed       = $%9.2f", Tax); //Print user tax owed

}
