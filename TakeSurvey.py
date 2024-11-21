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
"""
input("Please enter your username")