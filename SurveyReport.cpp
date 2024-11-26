#include <fstream>
#include <iostream>
#include "SurveyClasses.cpp"

using namespace std;


int main(int argc, char* argv[]) {
  string userName = "";
  int responseTotalsYes[5];
  int responseTotalsNo[5];

  // initialize the responses array
  for (int ndx = 0; ndx < 5; ndx++) {
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
  cout << "Loaded " << survey.questionCount() << " questions " << endl;
  // Now, we need to open the responses file
  ifstream responsesFile(userName + "responses.txt");

  // for each set of responses, start totaling them up
  string responseLine = "";
  while (getline(responsesFile, responseLine)) {
    // at this point, we have a line with up to 5 characters, a Y or N per
    // question
    for (int ndx = 0; ndx < survey.questionCount(); ndx++) {
      char answer = responseLine[ndx];
      if (answer == 'Y') {
        responseTotalsYes[ndx]++;
      } else {
        responseTotalsNo[ndx]++;
      }
    }
  }
  for (int ndx = 0; ndx < survey.questionCount(); ndx++) {
    int yes, no;
    yes = responseTotalsYes[ndx];
    no = responseTotalsNo[ndx];
    string result = "Yes";
    if (no > yes) {
      result = "No";
    }
    if (no == yes) {
      result = "Maybe";
    }
    cout << survey.question(ndx);
    cout << " Yes: " << yes;
    cout << " No: " << no << endl;
    cout << " ** For this question the majority says " << result << endl;
  }

  cout << "Done" << endl;
}