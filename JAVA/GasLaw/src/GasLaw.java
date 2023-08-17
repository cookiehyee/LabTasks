import java.util.Scanner;

public class GasLaw {

    private static Scanner keyboard = new Scanner(System.in);

    //The gas constant in Joules/mole/K
    private static final double GAS_CONSTANT = 8.3143;

    public static void main(String[] args) {

        //Declare variables to hold system values
        double volume, moles, temperature;
        double pressure;

        //Prompt the user to input variable values
        System.out.print("Enter volume, moles, temperature : ");
        volume = keyboard.nextDouble();
        moles = keyboard.nextDouble();
        temperature = keyboard.nextDouble();

        //Calculate and assign a value to pressure
        pressure = moles * GAS_CONSTANT * temperature / volume;

        //Display calculated pressure
        System.out.println("Pressure is " + pressure);

    }

}