import java.util.Scanner;

public class KillingKangaroos {

    //Declare constant variable to be used for calculation
    final static double ROAD_KILL_CONSTANT = 1.47;
    final static double AUS_ROAD_WIDTH = 0.01;

    public static void main(String[] args) {

        //Declare variables, Kangaroo denoted as roo for convenience
        int numRoos; //Declared as an integer because roos are countable
        double roadLength, squareLength, rooDensity, roadArea, numKills;

        Scanner input = new Scanner(System.in);

        //Prompt the user to enter variable values
        System.out.print("Enter side of square in km  : ");
        squareLength = input.nextDouble();
        System.out.print("Enter roads length in km    : ");
        roadLength = input.nextDouble();

        System.out.print("Enter number of 'roos       : ");
        numRoos = input.nextInt();

        /* Phase 1
           Perform calculations for roo density and surface area */
        rooDensity = Math.pow(squareLength,2) / numRoos;
        roadArea = roadLength * AUS_ROAD_WIDTH;

        /* Phase 2
           Perform calculation for expected number of Kangaroo kills
           based on the calculated roo density and surface area. */
        numKills = (roadArea/rooDensity) * ROAD_KILL_CONSTANT;

        //Display the expected number of kangaroo kills
        System.out.println("Expected number of kills is : " + numKills);

    }

}
