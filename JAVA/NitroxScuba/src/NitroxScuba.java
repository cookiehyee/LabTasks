import java.util.Scanner;

public class NitroxScuba {

    //Declare constant variables given
    final static double FEET_PER_ATMOSPHERE = 33;
    final static double MAXIMAL_OXYGEN = 1.4;
    final static double CONTINGENCY_OXYGEN = 1.6;

    public static void main(String[] args) {

        int depth, oxygenPercent; //Variables to ask user
        double ambientPressure, oxygenPressure; //Variables to calculate
        char oxygenGroup;
        boolean exceedsMaximal, exceedsContingency;

        //Prompt user to input depth and oxygen percent
        Scanner keyboard = new Scanner(System.in);
        System.out.print("Enter depth and percentage 02\t: ");
        depth = keyboard.nextInt();
        oxygenPercent = keyboard.nextInt();

        //Perform calculation for ambient and oxygen pressure
        ambientPressure = (depth / FEET_PER_ATMOSPHERE) + 1;
        oxygenPressure = ((double)oxygenPercent / 100) * ambientPressure;

        /* Assign boolean values to check if calculated oxygen pressure
        exceeds maximal or contingency partial oxygen pressure */
        exceedsMaximal = (oxygenPressure > MAXIMAL_OXYGEN);
        exceedsContingency = (oxygenPressure > CONTINGENCY_OXYGEN);

        //Calculate oxygen group
        oxygenGroup = (char)((int)(oxygenPressure * 10) + 'A');

        //Method to print results for a cleaner code
        printResults(ambientPressure, oxygenPressure, oxygenGroup,
                exceedsMaximal, exceedsContingency);

    }

    //Method: Print all results by passing the calculated variables as parameters
    public static void printResults(double ambPressure, double o2Pressure, char o2Group,
                                    Boolean exMaximal, Boolean exContingency) {

        System.out.println("\nAmbient pressure\t\t\t\t: " + ambPressure);
        System.out.println("02 pressure\t\t\t\t\t\t: " + o2Pressure);
        System.out.println("02 group\t\t\t\t\t\t: " + o2Group);
        System.out.println("\nExceeds maximal 02 pressure\t\t: " + exMaximal);
        System.out.println("Exceeds contingency 02 pressure : " + exContingency);

    }

}
