import java.util.ArrayList;

public class Family { //Family class

    private static final int MAX_PEOPLE = 10; //Max number of people in family
    private ArrayList<Person> familyMembers = new ArrayList<Person>(); //ArrayList to store person object
    private int numPeople;
    private int totalAge;

    public Family() { //Default constructor
        numPeople = 0; //Initialized to 0
    }

    public void display() { //Method to display all person objects in the family
        int personIndex;
        for(personIndex = 0; personIndex < familyMembers.size(); personIndex++) { //Loop to print person objects
            //toString method used to print person objects
            System.out.println(familyMembers.get(personIndex).toString());
        }
    }

    public boolean addPerson(String name, int age) { //Method to add person objects in family
        if(numPeople <= MAX_PEOPLE) { //Lesser than or equal to max number of people
            familyMembers.add(new Person(name, age)); //Add a new person to the ArrayList<Person>
            numPeople++; //Increment number of people each time a person is added
            totalAge += age; //Add the age of the person added to the total age of family

            return true; //Return true so that loop to add person object will continue
        }

        return false; //Return false so that loop to add person object will stop
    }

    public void birthday(String name) { //Method to increment age of a person object when birthday
        int personIndex;
        for(personIndex = 0; personIndex < familyMembers.size(); personIndex++) { //Loop to find person object
            if (familyMembers.get(personIndex).getName().equals(name)) { //If person object is found
                familyMembers.get(personIndex).incrementAge(); //Increment age by 1
                totalAge++; //Increment total age of family also by 1
            }
        }
    }

    public int getNumberOfPeople() { //Method to get number of people
        return numPeople;
    }

    public int getTotalAge() { //Method to get total age of family
        return totalAge;
    }

}
