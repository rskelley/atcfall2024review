#include <fstream>
#include <iostream>

using namespace std;

/*
Use similar class as used in the python program
*/
class SurveyQuestions {
 public:
  SurveyQuestions();
  SurveyQuestions(string);
  void loadQuestions();
  string question(int);
  int questionCount();
private:
  string username;
  string questions[5];
  int numberQuestions;
};

SurveyQuestions::SurveyQuestions() {
  username = "";
  for (int ndx = 0; ndx < 5; ndx++) {
    questions[ndx] = "";
  }
  numberQuestions = 0;
}
SurveyQuestions::SurveyQuestions(string inputName) {
  username = inputName;
  for (int ndx = 0; ndx < 5; ndx++) {
    questions[ndx] = "";
  }
  numberQuestions = 0;
}
void SurveyQuestions::loadQuestions() {
  string fileName = username + "questions.txt";
  ifstream inputFile(fileName);
  numberQuestions = 0;
  string question;
  while (getline(inputFile, question)) {
    questions[numberQuestions] = question;
    numberQuestions++;
  }
}
string SurveyQuestions::question(int ndx) {
  return questions[ndx];
}
int SurveyQuestions::questionCount() {
  return numberQuestions;
}
