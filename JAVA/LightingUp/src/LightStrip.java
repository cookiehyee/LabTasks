import java.util.ArrayList;

public class LightStrip {

    private ArrayList<Light> lightList; //Array list of lights
    private double totalLumens, totalHeatOutput;
    private int flourescentCount = 0; //Initialized to 0

    public LightStrip() { //Constructs light strip object
        lightList = new ArrayList<Light>(); //Creates ArrayList of light when light strip object is instantiated
    }

    public void display() { //Method to display entire light data in the light strip object

        int lightIndex;

        for(lightIndex = 0; lightIndex < lightList.size(); lightIndex++) {
            System.out.println(lightIndex + ": " + lightList.get(lightIndex)); //Prints each light object of the list
        }

        System.out.println("Total lumens: " + totalLumens); //Prints total lumens of all lights in the list
        System.out.println("Flourescent: " + flourescentCount); //Prints total count of flourescent lights
        System.out.println("Heat output: " + totalHeatOutput); //Prints total heat output of all lights in the list

    }

    public void addLight(Light lightToAdd) { //Method to add light object to the light list of the light strip object

        lightList.add(lightToAdd); //Adds light object to the light list
        totalLumens += lightToAdd.getLumens(); //Adds the light's lumens
        totalHeatOutput += lightToAdd.heatOutput(); //Adds the light's heat output

        if (lightToAdd.isFlourescent()) { //If the light to add is a flourescent light
            flourescentCount++; //Increment flourescent light count
        }

    }

    public void removeLight(int index) { //Method to remove light object to the light list of the light strip object

        try { //Index could be out of bounds

            if(lightList.get(index).isFlourescent()) { //If the light to remove is a flourescent light
                flourescentCount--; //Decrement flourescent light count
            }

            totalLumens -= lightList.get(index).getLumens(); //Subtracts the light's lumens
            totalHeatOutput -= lightList.get(index).heatOutput(); //Subtracts the light's heat output
            lightList.remove(index); //Removes light object from the light list

        } catch(IndexOutOfBoundsException exception) { //If index is out of bounds
            System.out.println("ERROR: No light at that index"); //Prints error message of the exception
        }
    }

}
