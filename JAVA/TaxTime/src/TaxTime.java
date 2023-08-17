import java.util.Scanner;

public class TaxTime {

    //Declare final tax rate per tax group
    final static double RICH_RATE = 0.25;
    final static double MIAMI_RATE = 0.10;
    final static double AVG_REAL_RATE = 0.03;

    //Declare income bracket per tax group
    final static double STINKING_RICH = 500000;
    final static double QUITE_RICH = 200000;
    final static double MIAMI_POOR = 100000;
    final static double AVERAGE = 50000;
    final static double REALISTIC = 20000;

    public static void main(String[] args) {

        //Income and deductions initialized to zero
        double income = 0;
        double deductions = 0;
        double amount, taxableIncome, tax;
        char taxGroup;

        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter next amount : ");
        amount = keyboard.nextInt();

        //Receive user input until 0 is entered
        while(amount != 0) {

            if (amount > 0) {
                income += amount;
            }

            else {
                deductions += Math.abs(amount);
            }

            System.out.print("Enter next amount : ");
            amount = keyboard.nextInt();

        }

        taxableIncome = computeTaxableIncome(income, deductions);
        taxGroup = chooseTaxGroup(taxableIncome);
        tax = calculateTax(taxGroup, taxableIncome);

        //Method to print all computations regarding tax
        displayOutput(income, deductions, taxableIncome, taxGroup, tax);

    }

    public static double computeTaxableIncome(double aIncome, double aDeductions) {

        if (aIncome >= aDeductions) {
            return aIncome - aDeductions; //Taxable income = income - deductions
        }

        else { //If income is smaller than deductions, taxable income is 0
            return 0;
        }

    }

    public static char chooseTaxGroup(double tIncome) {

        //if statement used to assign tax group
        if (tIncome >= STINKING_RICH) {
            return 'S';
        }

        else if (tIncome >= QUITE_RICH) {
            return 'Q';
        }

        else if (tIncome >= MIAMI_POOR) {
            return 'M';
        }

        else if (tIncome >= AVERAGE) {
            return 'A';
        }

        else if (tIncome >= REALISTIC) {
            return 'R';
        }
C
        else
            return 'P';
        }

    }

    public static double calculateTax(char tGroup, double tIncome) {

        //switch statement used to return calculated tax based on tax group
        switch(tGroup) {    
            

            case 'S':
            case 'Q':
                return tIncome * RICH_RATE;

            case 'M':
                return tIncome * MIAMI_RATE;

            case 'A':
            case 'R':
                return tIncome * AVG_REAL_RATE;

            case 'P':
                return tIncome * 0;

            default:
                System.out.println("Error!");
                return 0;

        }

    }

    public static void displayOutput(double aIncome, double aDeductions,
                                     double tIncome, char tGroup, double tOwed) {

        System.out.println("\nIncome\t\t\t=  $" + aIncome);
        System.out.println("Deductions\t\t=  $" + aDeductions);
        System.out.println("Taxable income  =  $" + tIncome);
        System.out.println("Tax group\t\t=  " + tGroup);
        System.out.println("Tax owed\t\t=  $" + tOwed);

    }

}
