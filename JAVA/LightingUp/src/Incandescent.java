public class Incandescent extends Light { //Incandescent class inherits from Light class

    private final double HEAT_CONSTANT = 87.4; //Heat constant for calculating heat output
    private double heatOutput;

    public Incandescent(int lumens) {
        super(lumens); //Calls constructor of superclass and initializes value of lumens
        this.heatOutput = lumens * HEAT_CONSTANT; //Heat output = lumens * heat constant
    }

    @Override
    public double heatOutput() { //Abstract method in light class implemented and overridden
        return heatOutput; //Returns calculated heat output
    }

    @Override
    public boolean isFlourescent() { //Abstract method in light class implemented and overridden
        return false; //Returns false since objects of this class are incandescent type
    }
}
