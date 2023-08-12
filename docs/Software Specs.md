# Introduction

## Purpose
This desktop application aims to help students in streamlining the process 
between jotting down notes and reviewing them. It does this by implementing 
a flashcard system where a note file is loaded to the program and the questions 
are printed to the screen. Users can then give the program input on how familiar
the question is and this input can help in automating the flashcard system.

## Intended Use
ReCall is intended for students who want a light-weight text editor armed with 
a flashcard generator. To use the application, students will open a folder as 
a "Binder". After opening a Binder, the user may write a new note file and 
input the details of the note (Subject and Specific Topic). Then, they may fill
in the content of the flashcard by writing the following syntax:

```
<Question>
- <Answer>

<Question>
- <Answer>

<Question>
- <Answer>

...
```

After creating the note file, students can initiate a ReCall session by clicking
the `Initiate ReCall` button. This command will 1) initiate the ReCall session 
(a single round of using the flashcards) and 2) add containing pertinent 
statistics about your ReCall session to a local database.

## Scope 
Development of the software will be done in stages with expanding scope: 

1. **Basic functionality.**  In the first iteration of the software, only 
setting a Binder folder, creating/editing a note file and initiating a ReCall 
session will be done. The ReCall sessions will not yet have 
a shuffling feature. However, the user will be able to open the next cards 
and reveal the answers.

2. **Shuffling and simple memory.** At this stage, shuffling cards will be 
supported. On top of shuffling cards, the program will also be able to store
the current statistics (e.g. number of items correct) to a local database.

3. **Implementation of Leitner system.** This is the last stage of the planned
development. At this point, we will be able to use the statistics stored in 
the database to automate which flashcards to show more frequently based on 
mastery on the material.

## Definitions
| Term           | Definition                                                        |
|----------------|-------------------------------------------------------------------|
| ReCall Session | A single round of viewing a set of flashcards                     |
| Item           | A structure consisting of a question and its corresponding answer |
| Binder         | A central directory where you put all your notes                  |
| Binder         | A central directory where you put all your notes                  |

# Overall Description
## Functional Requirements 

Here are the functions necessary to achieve the desired results.

### **Setting a Binder folder**
* The user should be able to set a Binder folder.<sup>1</sup>

* The user should be able make a Binder folder the default when loading 
the application.<sup>2</sup>

### **Create a note file**
* The user should be able to add new note files. <sup>1</sup>

* The user should be able to input the necessary metadata for a notebook and save 
the files based on the metadata (folder name for the general subject and filename
for the specific topic).<sup>1</sup>

### **View and edit a note file**
* The user should be able to open and view a note file from a notebook in the 
specified Binder with its metadata.<sup>1</sup>

* The user should also be able to add new questions and edit the metadata of 
the note (i.e. the subject name and the topic).<sup>1</sup>


### **Initiate a ReCall session**
* The program should parse a note file to its corresponding set of flashcards 
<sup>1</sup> and randomize its order.<sup>2</sup>

* It should flash the cards and allow the users to input the familiarity level 
of the answer.<sup>1</sup>

* It should also allow users to flash the next card and reveal the answers.
<sup>1</sup>

* The frequency of the flashcards shall be determined by the mastery level 
of the user.<sup>3</sup>

* After the session, the program will store the statistics to the database.
<sup>2</sup>


**Footnotes**

* [1] Will be implemented in Stage 1
* [2] Will be implemented in Stage 2
* [3] Will be implemented in Stage 3

## Non-Functional Requirements
### Intuitive Design
Since the app requires a specific format for a note file, the design should 
facilitate intuitive use. At first use, the application should have a tooltip 
in the note text editor to nudge the user to the right direction.

### Lightweight
The app needs to be lightweight by implementing only necessary features and 
minimizing feature bloat. Only features related to note creation and flashcard
viewing should be prominent.

### Clutter-free
The app needs facilitate a distraction-free environment in creating notes and
reviewing flashcards. The UI should be clean and minimal, solely focusing on 
the specific task at a time.

### Compatibility
The app needs to be supported across any OS and platforms.

### Error and Missing Information Handling
The app must inform user of incomplete metadata before they can proceed on 
adding flashcards. For missing answers, the app renders the question and allows
the ability to add the answer in the flashcard when in a ReCall session.
