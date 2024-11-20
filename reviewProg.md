## Review Program CIST 1305


#### Problem definition

Capture survey results; based on a survey of X questions, we will collect Yes, No, or No Answer responses from a sample of people

Scope
   - Get surveyER name (username)
   - Enter a series of questions
     - yes/no type questions
    - based on answers from respondents, tally yes/no answers for each
    - generate a report of yes/no totals for each question

What do we need to decide?

1. 1 or 2 programs or even 3?
   1. How many?
      1.  Question creator (Java)
      2.  Survey responses (Python)
      3.  Report           (C++)
2. How is running the program(s)?
   1. run by us (generator of questions)
   2. Will be run by either the person being questioned OR the interviewer
   3.  Run by us
3. Where will store questions?
   1. Store in a file
4. WHere will store answers?
   1. Store in a file, but anonymized