/*

Purpose: Collect the name of the question designer and up to 5 questions

Program fill need to do:
Get the user name
Start asking for questions
WE EXPECT AT LEAST 1.  Give an suitable error message if there are no questions
save the questions in a file named {username}questions.txt

*/
import java.util.Scanner;
import java.io.FileWriter;
public class QuestionCollector {
    public static final int MAX_QUESTIONS = 5;
    public static Scanner cliInput;

    public static String getQuestion() {
        System.out.print("Enter a question.  Just press enter to quit: ");
        String userInput = cliInput.nextLine();
        return userInput;

    }

    public static void saveQuestions(String username, String[] questions, int counter) {   
        // create a file based on our username     
        String fileName = username+"questions.txt";
        try {
            FileWriter outFile = new FileWriter(fileName);
            
            for(int ndx=0;ndx<counter;ndx++){
                // Write each question out to the file
                outFile.write(questions[ndx]+"\n");
                System.out.println(questions[ndx]);
            }
            // Don't forget to close!!!
            outFile.close();
        }
        catch (Exception e){
            // Some classes in Java might throw an Exception which must be caught, so we have this try catch block
            System.out.println("There was an error trying to save your file!");
        }
    }

    public static void main(String []args) {
        // declare all of our function scope variables in one place
        String userName="";
        Boolean ok = false;
        String question;
        String[] questions = new String[5]; // This declares AND initializes an empty array
        int counter = 0; // another initialization for later

        // the scanner variable is global, so this is an assignment, not a declaration
        cliInput = new Scanner(System.in);
        
        // Get the usersname
        while (!ok) {
            // Only checking for empty string -- we could do more
            System.out.print("Please enter a username.  Do not include spaces: ");
            userName = cliInput.nextLine();
            if (userName != "") {
                ok = true;
            }
        }
        System.out.println("The name entered was "+userName);

        // Now get our questions
        question = getQuestion();
        while (!question.equals("") && counter < MAX_QUESTIONS) {
            // save the question to our Array, then get the next question
            questions[counter] = question;
            counter = counter + 1;
            question = getQuestion();
        }
        // We said we have to have at least one question! Don't save anything if there is nothing to save
        if (counter > 0) {
            saveQuestions(userName, questions, counter); 
        }
        else {
            System.out.println("There were no questions entered!! Nothing saved.");
        }
        System.out.println("Done!");
    }

}