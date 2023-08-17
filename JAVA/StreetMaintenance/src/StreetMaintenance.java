import java.util.Scanner;

public class StreetMaintenance {

    public static void main(String[] args) {

        int[] houseNumbers; //Array containing house
        int[][] peopleAge; //Array containing people and their ages for each house
        int numHouses; //Number of houses in the street

        Scanner keyboard = new Scanner(System.in);

        System.out.print("How many houses in the street?   : ");
        numHouses = keyboard.nextInt();

        houseNumbers = new int[numHouses]; //Array of size depending on number of houses
        peopleAge = new int[numHouses][];
        //The number of people per house is different, so size of second dimension left empty for now

        inputStreetData(houseNumbers, peopleAge);  //Method to input data for house number and people arrays
        analyzeStreetData(houseNumbers, peopleAge); //Method to analyze data of house and age arrays

    }

    //Method to input street data, which consists of house numbers and people
    public static void inputStreetData(int[] house, int[][] people) {

        Scanner keyboard = new Scanner(System.in);
        int houseNum, numPeople, personAge;

        System.out.println(); //Newline

        //Fill in house number array
        for(int i = 0; i < house.length; i++) { //Loop to input house number for each house
            System.out.print("What is the next house number?   : ");
            houseNum = keyboard.nextInt();
            house[i] = houseNum;
        }

        //Fill in people and their age array
        for(int i = 0; i < people.length; i++) { //Outer loop to input number of people for each house
            System.out.print("\nHow many people live in number " + house[i] + " : ");
            numPeople = keyboard.nextInt();
            people[i] = new int[numPeople]; //Size of second dimension decided by number of people per house

            for(int j = 0; j < people[i].length; j++) { //Inner Loop to input age for each person
                System.out.print("What is the age of person " + (j + 1) + "      : ");
                personAge = keyboard.nextInt();
                people[i][j] = personAge;
            }
        }

    }

    public static void analyzeStreetData(int[] house, int[][] age) { //Method to analyze street data

        int houseAge = 0;
        int streetAge = 0;

        for(int i = 0; i < house.length; i++) { //Outer loop to add age of all houses: street age
            System.out.print("\nHouse " + house[i] + " has a total age of ");

            for(int j = 0; j < age[i].length; j++) { //Inner loop to add age of people per house: house age
                houseAge += age[i][j];
            }

            System.out.print(houseAge); //Print age of each house
            streetAge += houseAge; //Add total age of a house to the total street age
            houseAge = 0; //Reset age to zero in order to add age of people in next house
        }

        System.out.println("\n\nThe street has a total age of " + streetAge);

    }

}
