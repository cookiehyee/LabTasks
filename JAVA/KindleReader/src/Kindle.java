public class Kindle { //Kindle class

    int totalPages; //Total number of pages of the book
    int currentPage; //Current page of the book

    public Kindle(int totalPages) { //Constructor
        this.totalPages = totalPages; //Sets number of pages of the book
        this.currentPage = 1; //Sets current page to 1 when a Kindle object is instantiated
        //this refers to the object
    }

    public void turnPages() { //Method to turn 1 page

        turnPages(1);

    }

    public void turnPages(int numPages) { //Overloaded method to turn a specific number of pages of a book

        //Checks if turning a specific number of pages exceeds the total number of pages of the book
        if((this.currentPage + numPages) > this.totalPages) {
            System.out.println("You were on                : " + this); //Prints the object
            System.out.println("Turning " + numPages + " pages would take you past the last page.");
            this.currentPage = this.totalPages; //Sets currentPage to last page of the book
            System.out.println("You are now on             : " + this); //Prints the object
        }

        else {
            this.currentPage += numPages; //Increment by numPages when page is turned by numPages
        }

    }

    public String toString() { //toString method to print a Kindle object
        return String.format("Page %3s", currentPage) + " of  " + totalPages + ".";
    }

}
