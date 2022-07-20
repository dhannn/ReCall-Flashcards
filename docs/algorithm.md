# Top-Level Algorithm
1. Check if file exists.
    * If not, inform the user and exit.
    * If yes, proceed.
1. Read the content of the file.
1. Tokenize the content.
1. Parse the tokens.
1. Initiate a ReCall session.

# Reading content algorithm
_Precondition: File already exists_

1. Open and load content of file.
1. Check if there's an opening delimiter for course code (i.e. '[').
    * If false, set bitmap to 1.
1. Check if there's a closing delimiter for course code (i.e. ']').
    * If false, set bitmap to 1.
1. Check if the number for the new question delimiter matches the number for the answer delimiter (i.e. "\n\n" and "- " respectively).
    * If false, set bitmap to 1.
1. Return bitmap.

# Tokenize content algorithm 
1. Check if the current character is a null byte.
    * If yes, exit.
    * If not, proceed.
1. Check if current character is alphanumeric.
    * If yes:
        * Tokenize alphanumeric string.
    * If no: 
        * Tokenize non-alphanumeric character.
1. Increment character.
1. Go to Step 1.
