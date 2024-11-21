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
        String fileName = username+"questions.txt";
        try {
            FileWriter outFile = new FileWriter(fileName);
            
            for(int ndx=0;ndx<counter;ndx++){
                outFile.write(questions[ndx]+"\n");
                System.out.println(questions[ndx]);
            }
            outFile.close();
        }
        catch (Exception e){
            System.out.println("There was an error trying to save your file!");
        }
    }

    public static void main(String []args) {
        // Get the usersname
        String userName="";
        cliInput = new Scanner(System.in);
        Boolean ok = false;
        while (!ok) {
            // Only checking for empty string -- we could do more
            System.out.print("Please enter a username.  Do not include spaces: ");
            userName = cliInput.nextLine();
            if (userName != "") {
                ok = true;
            }
        }
        String question = getQuestion();
        String[] questions = new String[5]; // This declares AND initializes an empty array
        int counter = 0;
        while (!question.equals("") && counter < MAX_QUESTIONS) {
            // save the question to our Array, then get the next question
            questions[counter] = question;
            counter = counter + 1;
            question = getQuestion();
        }
        System.out.println("There were "+counter+ " questions entered");
        System.out.println("The name entered was "+userName);
        saveQuestions(userName, questions, counter); 
        System.out.println("Done");
    }

}