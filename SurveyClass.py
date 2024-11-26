"""
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
        with open(f"{self.username}responses.txt", "a") as f:
            for a in self.answers:
                # Force it to be an uppercase Y/N
                f.write(a.upper())
            # this will store the responses all on one line, so make sure to add a newline
            f.write("\n")
