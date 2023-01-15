# wordFinder

## Introduction

wordFinder was created as an extra credit assignment for my COSC 175 class. The C++ script searches for a user-given word within a .txt file in this format

![image](https://user-images.githubusercontent.com/116126778/212567388-d624e9f6-7a22-4183-a184-ac20472b90a3.png)

and outputs what line numbers the word was found in. 

![image](https://user-images.githubusercontent.com/116126778/212567526-794c7eb1-abd8-434b-aec1-62b2e543d0e2.png)

If the file can't be found, the user is asked to try again.

![image](https://user-images.githubusercontent.com/116126778/212567775-d57d2e92-40e0-492d-956e-9e9350d7cb58.png)

![image](https://user-images.githubusercontent.com/116126778/212567600-087234ba-f967-4daf-8a4a-9e259e1d7b87.png)

If the word can't be found, the user is informed.

![image](https://user-images.githubusercontent.com/116126778/212567686-a0254020-2f16-45d1-b637-33436f984662.png)

The algorithm works by adding 1 to the variable lineNum every time a letter is checked to keep track of what line number is being read. If the first letter matches, is is considered the starting line. If every other line after that matches to create the target word, the last line number is considered the ending line. If the word is not complete, and a non-matching character is checked, the variable indexWord is brought back to 0, so a new starting line may be found.

![image](https://user-images.githubusercontent.com/116126778/212567826-cc79d867-c5ea-4010-be6a-e612a413db62.png)

## Credits

- Assignment and .txt files created by Nick Winner from Towson University
