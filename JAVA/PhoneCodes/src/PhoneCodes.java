import java.util.Scanner;

public class PhoneCodes {

    final static int MIAMI_AREA_CODE = 305;

    public static void main (String[] args) {

        int phoneNumber;
        String phoneCode, areaCode, encodedNumber;
        Scanner keyboard = new Scanner(System.in);

        do {

            System.out.print("Please enter your 305 phone number: ");
            phoneNumber = keyboard.nextInt();

        //If length of phone number is not 7, continue looping
        } while(String.valueOf(phoneNumber).length() != 7 && phoneNumber > 0);

        areaCode = encodeNumber(MIAMI_AREA_CODE); //Method called to encode area code
        phoneCode = encodeNumber(phoneNumber); //Method called to encode phone number
        encodedNumber = areaCode + phoneCode;
        //Encoded number = concatenation of area code and phone number

        //Method to print phone number and encoded number
        printEncodedNumber(phoneNumber, encodedNumber);

    }

    public static String encodeNumber(int phoneNum) {

        //First array containing first letters for each keypad
        char[] charLetters = {'0','1','A','D','G','J','M','P','T','W'};
        //Second array containing number of digits in each keypad
        int[] numDigits = {1, 1, 3, 3, 3, 3, 3, 4, 3, 4};

        int digit, randomNum; //Number to randomly decide letter on keypad
        char encodedChar;
        String encodedString = "";

        while(phoneNum > 0) {

            digit = phoneNum % 10; //extract phone number digit from reverse order
            randomNum = (int)(Math.floor(Math.random() * 10)) % numDigits[digit];
            //Math.random() * 10 since the value is between 0 and 1
            encodedChar = (char)(charLetters[digit] + randomNum);
            //Type cast to character to convert to ASCII
            encodedString = encodedChar + encodedString;
            //Add phone number in reverse order since digit was extracted in reverse order
            phoneNum /= 10; //divide by 10 in order to extract next digit

        }

        return encodedString;

    }

    public static void printEncodedNumber(int phoneNum, String encodedNum) {

        System.out.println("The phone number " + MIAMI_AREA_CODE + phoneNum
                + " can be encoded as " + encodedNum);
        //Print Miami area code and phone number after concatenation

    }

}
