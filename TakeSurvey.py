"""
This program will read the user's questions and present them in a loop to various respondents.
After each person has entered their responses, the program will save the data by APPENDING it to a results file
Because we may not do this all at once, we will not ERASE the results file, we will always append to ti

pseudocode:
get username
questions_file = open username+"questions.txt"
read questions into an array

is there someone to take the survey?
while there are people taking the survey
    ask all questions
    append responses in username+"results.txt" file
    is there someone else to take the survey

thank user for using the program

Other thoughts -- use a class to store question responses to results file
class diagram:
    properties:
        username
        questions_array
        responses
        answers
    methods:
        load_questions
        ask_questions
        store_responses
"""
class SurveyData:
    username = ""
    questions = []
    responses = []
    answers = []

    # initialize new instance
    def __init__(self, username=None):
        self.username = username

    # get the questions
    def load_questions(self):
        with open(f"{self.username}questions.txt", "r") as f:
            for line in f:
                self.questions.append(line)
    
    # ask a respondent the questions and store the answers
    def ask_questions(self):
        # Clear the previous answers
        self.answers = []
        for q in self.questions:
            answer = input(q)
            self.answers.append(answer)
        print("That's all of our questions!  Thank you!")
    
    # Save the answers to a file -- USE APPEND!
    def store_responses(self):
        with open(f"{username}responses.txt", "a") as f:
            for a in self.answers:
                f.write(a)
            # this will store the responses all on one line, so make sure to add a newline
            f.write("\n")
        
# get the user's name
username = input("Please enter your username: ")
# load the questions
survey = SurveyData(username)
survey.load_questions()

# If there's someone to take the survey, let them take it
respondents = input("Do you have someone to take the survey?(y/n) ")
while respondents.lower() == "y":
    # ask the questions
    survey.ask_questions()
    # store the questions
    survey.store_responses()
    # check for more respondents
    respondents = input("Do you have someone to take the survey?(y/n) ")

print("All done!")
