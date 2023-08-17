public class Flourescent extends Light { //Flourescent inherits from Light class

    public Flourescent(int lumens) {
        super(lumens); //Calls constructor of superclass and initializes value of lumens
    }

    @Override
    public double heatOutput() { //Abstract method in light class implemented and overridden
        return 0; //returns heat output which is 0
    }

    @Override
    public boolean isFlourescent() { //Abstract method in light class implemented and overridden
        return true; //Returns true since objects of this class are flourescent type
    }
}
