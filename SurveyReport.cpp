#include <iostream>
#include <fstream>

using namespace std;

/*
Use similar class as used in the python program
*/
class SurveyQuestions {
    public:
        SurveyQuestions();
        SurveyQuestions(string);
        void loadQuestions();
        int numberQuestions;
        string questions[5];
    private:
        string username;
};

SurveyQuestions::SurveyQuestions() {
    username = "";
    for(int ndx=0;ndx<5;ndx++) {
        questions[ndx] = "";
    }
    numberQuestions = 0;
}
SurveyQuestions::SurveyQuestions(string inputName) {
    cout << "Loading with username " << inputName;
    username = inputName;
    for(int ndx=0;ndx<5;ndx++) {
        questions[ndx] = "";
    }
    numberQuestions = 0;
}
void SurveyQuestions::loadQuestions() {
    string fileName = username + "questions.txt";
    cout << "Loading " << fileName << endl;
    ifstream inputFile(fileName);
    numberQuestions = 0;
    string question;
    while (getline(inputFile, question)) {
        questions[numberQuestions]  = question;
        numberQuestions++;
    }
}

int main(int argc, char* argv[]) {
    string userName = "";
    int responseTotalsYes[5];
    int responseTotalsNo[5];

    // initialize the responses array
    for(int ndx =0;ndx<5;ndx++) {
        responseTotalsYes[ndx] = 0;
        responseTotalsNo[ndx] = 0;
    }
    // get the username for the questions and responses before we setup the object
    cout << "Enter your username: ";
    cin >> userName;

    // setup the object;
    SurveyQuestions survey(userName);

    // Load the questions
    survey.loadQuestions();
    cout << "Loaded " << survey.numberQuestions << " questions " << endl;
    // Now, we need to open the responses file
    ifstream responsesFile(userName+"responses.txt");
    // for each set of responses, start totaling them up
    string responseLine = "";
    while(getline(responsesFile, responseLine)) {
        // at this point, we have a line with up to 5 characters, a Y or N per question
        cout << responseLine << endl;
    }
    for(int ndx=0;ndx < survey.numberQuestions; ndx++) {
        cout << survey.questions[ndx] << endl;
    }
    
    cout << "Done" << endl;
}