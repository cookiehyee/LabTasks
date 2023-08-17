public class Diamond { //Diamond class

    private int carats; //Carat of the diamond
    private double value; //Value of the diamond

    public Diamond() { //Default constructor
        this.carats = 0;
        this.value = 0;
    }

    public double getValue() { //Accessor method to return the diamond's value
        return value;
    }

    public int getCarats() { //Mutator method to return the diamond's carats
        return carats;
    }

    public void setCarats(int carats) { //Mutator method to set the diamond's carats
        this.carats = carats;
    }

    public void setValue(double value) { //Mutator method to set the diamond's value
        this.value = value;
    }

    @Override
    public String toString() { //Overriden method to print diamond object
        return this.carats + " carats, worth $" + this.value;
    }
}

//wed 10 - 2:30
