public class Person { //Person class

    private String name;
    private int age;

    public Person() { //Default constructor
        name = null; //Initialized to an empty string
        age = 0; //Initialized to 0
    }

    public Person(String name, int age) { //Overloaded constructor
        this.age = age; //Initialize age
        this.name = name; //Initialize name
    }

    public String toString() { //Method to return string representation of a person object
        return name + " is " + age + " years old";
    }

    public void incrementAge() { //Method to increment age by 1
        this.age++;
    }

    public String getName() { //Method to get name of a person object
        return this.name;
    }

    public int getAge() { //Method to get age of a person object
        return this.age;
    }

}
