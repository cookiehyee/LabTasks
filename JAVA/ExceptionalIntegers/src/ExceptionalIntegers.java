import java.util.ArrayList;

public class ExceptionalIntegers {

    public static void main(String[] args) {

        //ArrayList to store args converted to Integer
        ArrayList<Integer> intList = new ArrayList<>();
        int index;

        for(index = 0; index < args.length; index++) { //Loop through command line
            try{ //Check if number format exception exists in wrapping process
                wrap(args[index], intList); //Method to wrap command line argument to Integer
            } catch(NumberFormatException e) { //Catches if number format exception is found
                System.out.println("Catch block says the argument \"" + args[index] +
                        "\" is ignored because " + args[index]);
            }
        }

        System.out.println("\nVector contents are:");
        for(index = 0; index < intList.size(); index++) { //Loop to print ArrayList content
            System.out.println("Item " + index + " is " + intList.get(index));
        }

    }
    public static void wrap(String value, ArrayList<Integer> List)
            throws NumberFormatException { //Method to wrap args to Integer

        List.add(Integer.parseInt(value)); //Integer.parseInt to wrap args to an Integer
        //If wrapping fails due to number format exception the catch block is executed
        System.out.println("Converter method says integer OK - " + value);

    }

}
