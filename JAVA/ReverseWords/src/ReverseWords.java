import java.util.Scanner;

public class ReverseWords {

    public static void main (String[] args) {

        String[] wordList;

        Scanner keyboard = new Scanner(System.in);
        wordList = keyboard.nextLine().split(" "); //Split sentence by words in a string array
        reverseOutput(wordList, wordList.length - 1);

    }

    public static void reverseOutput(String[] words, int count) { //Recursively output words of a sentence in reverse

        if(count > 0 ) { //Recursive case
            if(words[count].contains(".")) { //If the word contains a period
                words[count] = words[count].substring(0,words[count].length()- 1); //Remove the period
            }
            System.out.print(words[count] + " ");
            reverseOutput(words, count - 1);
        }

        else { //Base case
            System.out.println(words[count] + ".");
        }

    }

}
