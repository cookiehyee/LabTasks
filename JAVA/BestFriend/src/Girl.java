public class Girl { //Girl class

    private String name; //Name of the girl
    private Diamond currentDiamond; //Current diamond object of the girl

    public Girl(String name) { //Constructor to create a new girl object according to name input
        this.name = name;
        this.currentDiamond = new Diamond(); //A newly created girl object has no diamond object
    }

    public Diamond getDiamond() { //Accessor method to return the girl's current diamond
        return currentDiamond;
    }

    public void setDiamond(Diamond diamond) { //Girl class method to accept a new diamond object
        this.currentDiamond = diamond;
    }

    public String toString() { //Overridden method to print girl object

        return this.name + " has a diamond, " + this.currentDiamond.toString(); //toString() method of diamond class


    }

}
