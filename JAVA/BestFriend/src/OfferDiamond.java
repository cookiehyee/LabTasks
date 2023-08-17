import java.util.Scanner;

public class OfferDiamond { //Driver class to create a girl and repeatedly offer new diamonds

    public static void main(String[] args) {

        Scanner keyboard = new Scanner(System.in);
        Girl theGirl;
        Diamond diamondOffered;
        String name;

        System.out.print("Enter the name of the girl : ");
        name = keyboard.nextLine(); //Get name of the girl
        theGirl = new Girl(name); //Creates new girl object based name input
        diamondOffered = new Diamond(); //Creates a new diamond object

        offerDiamond(theGirl,diamondOffered); //Offers new diamond to the girl

    }

    public static void offerDiamond (Girl theGirl, Diamond diamondOffer) { //Method to offer new diamond

        Scanner keyboard = new Scanner(System.in);
        Diamond herDiamond;
        int carats;
        double value;

        do { //Loops to continually offer a new diamond until a carat of 0 is specified

            System.out.println(theGirl); //Displays information about the girl and her diamond
            System.out.print("Enter carats and value     : ");
            carats = keyboard.nextInt(); //Get carats of the new diamond
            value = keyboard.nextDouble(); //Get value of the new diamond

            if (carats > 0) { //If more than 0 carats, a new diamond is created to be offered to the girl

                diamondOffer.setValue(value); //Sets the value of the next diamond
                diamondOffer.setCarats(carats); //Sets the carats of the next diamond
                herDiamond = theGirl.getDiamond(); //Gets the current diamond of the girl

                //If the girl's has no diamond or if her current diamond is less valuable than the new diamond
                if (herDiamond == null || herDiamond.getValue() < diamondOffer.getValue()) {
                    theGirl.setDiamond(diamondOffer); //Girl accepts the new diamond
                    System.out.println("Woohoo, the girl took the diamond");
                } else { //If her current diamond is more valuable than the new diamond
                    System.out.println("Aaargh, the diamond was rejected"); //Diamond is rejected
                }

            }

        } while (carats != 0); //Loop terminates when a carat of 0 is specified

        System.out.println(theGirl);

    }

}
