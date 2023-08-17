import java.util.Scanner;

public class I95 {

    final static double speedLimit = 65;

    public static void main(String[] args) {

        double distance, availableTime;
        double speed, timeStop, travelTime;
        boolean warning; //Used to check if speed exceeds speed limit
        Scanner scnr = new Scanner(System.in);

        //Display welcome message and instructions
        welcomeMessage();
        showInstructions();

        //Prompt user to input distance and available time
        System.out.print("Enter distance to travel : ");
        distance = scnr.nextDouble();
        System.out.print("Enter time available\t : ");
        availableTime = scnr.nextDouble();

        //Methods to perform calculation
        timeStop = computeTimeStop(distance);
        travelTime = computeTravelTime(availableTime, timeStop);
        speed = computeSpeed(distance, travelTime);
        warning = (speed > speedLimit);

        //Methods to display results
        displaySpeed(speed);
        displayWarning(warning);

    }

    public static void welcomeMessage() {
        System.out.println("Welcome to the I95 Speed Machine\n");
    }

    public static void showInstructions() {
        System.out.println("You will have to supply:");
        System.out.println("+ The distance you want to travel, in miles");
        System.out.println("+ THe time you have available, in hours\n");
    }

    public static double computeTimeStop(double dist) {
        return ((5 * Math.ceil(dist/100))/60);
        //Math.ceil is used to always round up distance / 100
        //Used to calculate time stops
    }

    public static double computeTravelTime(double availTime, double timeStp) {
        return (availTime - timeStp); //travel time = available time - time stop
    }
    public static double computeSpeed(double dist, double time) {
        return (dist/time); //speed = distance / time
    }

    public static void displaySpeed(double spd) { //Print speed
        System.out.println("\nYou will have to travel : " + spd + "mph");
    }

    public static void displayWarning(boolean overSpeed) { //Print speed warning
        System.out.println("Over the speed limit\t: " + overSpeed);
    }

}
