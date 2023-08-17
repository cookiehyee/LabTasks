public abstract class Light {

    private int lumens;

    public Light(int lumens) {

        this.lumens = lumens;
    }

    public String toString() {

        return(getClass().getName() + " light of " + String.valueOf(lumens) +
                " lumens");
    }

    public int getLumens() {
        return(lumens);
    }

    public abstract double heatOutput();

    public abstract boolean isFlourescent();

}