# Introduction

## Purpose
This CLI program aims to help students in streamlining the process between 
jotting down notes and reviewing them. It does this by implementing a flashcard
system where a note file is loaded to the program and the questions are printed
to the screen. Users can then give the program input on how familiar the question
is and this input can help in automating the flashcard system.

## Intended Use
ReCall is intended for students who want a light-weight flashcard generator. 
To use the program, students will write a note file (usually .txt) with syntax 
as follows: 
```
[<Name of the Subject>] <Topic>

<Question 1>
- <Answer 1>

<Question 2>
- <Answer 2>

<Question 3>
- <Answer 3>

...
```

After creating the note file, students can call `recall <filename>` in the 
directory of the note. This command will 1) initiate the ReCall session 
(a single round of using the flashcards) and 2) generate a .dat file containing
pertinent statistics about your ReCall session.

## Scope 
Development of the software will be done in stages with expanding scope: 

1. **Basic functionality.**  In the first iteration of the software, only 
parsing of the note file and initiating the ReCall session will be done. 
The ReCall sessions will not yet have a shuffling feature. However, the user 
will be able to open the next cards and reveal the answers.

2. **Shuffling and simple memory.** At this stage, shuffling cards will be 
supported. On top of shuffling cards, the program will also be able to store
the current statistics (e.g. number of items correct) to a .dat file.

3. **Implementation of Leitner system.** This is the last stage of the planned
development. At this point, we will be able to use the .dat files stored to 
automate which flashcards to show more frequently based on mastery on the 
material.

## Definitions
| Term           | Definition                                                        |
|----------------|-------------------------------------------------------------------|
| ReCall Session | A single round of viewing a set of flashcards                     |
| Item           | A structure consisting of a question and its corresponding answer |

# Overall Description
## Functional Requirements 

Here are the functions necessary to achieve the desired results.

### **Parse the note file**
* The program should be able to read the note file and parse the items.
<sup>1</sup>

* These items will be loaded to a hash table containing the questions 
and answers.<sup>1</sup>

* The program should also be able to parse the necessary metadata 
(i.e. the subject name and the topic).<sup>1</sup>


### **Initiate a ReCall session**
* The program should load the card list structure<sup>1</sup> 
and randomize its order.<sup>2</sup>

* It should flash the cards and allow the users to input 
the familiarity level of the answer.<sup>1</sup>

* It should also allow users to flash the next card and reveal 
the answers.<sup>1</sup>

* The frequency of the flashcards shall be determined by the mastery
level of the user.<sup>3</sup>

* After the session, the program will store the statistics to 
a generated .dat file.<sup>2</sup>


**Footnotes**

* [1] Will be implemented in Stage 1
* [2] Will be implemented in Stage 2
* [3] Will be implemented in Stage 3
