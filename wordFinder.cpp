#include <iostream>
#include <fstream>
using namespace std;

string Word();
void WordSearch();

int main() {

	WordSearch();

}

//******************
//This functions collects a word from the user.
string Word() {
	string word;
	cout << "What is your word? ";
	cin >> word;
	return word;
}

//******************
//This program uses a linear search to find a given word within a txt document
void WordSearch() {
	//Declare all variables
	bool found = false;		
	string txtDoc, targetWord;
	char letter;
	int lineNum = 1, lineStart = 0, lineEnd = 0;
	int indexWord = 0;

	//Prompt for txt file
	cout << "Enter the name of the txt file you would like to open: ";
	cin >> txtDoc;

	//If found, open file
	ifstream inFile;
	inFile.open(txtDoc);

	//If not found, prompt until it is, then open
	while (!inFile) {
		cout << "Unable to open file." << endl;
		cout << "\nTry again. Make sure txt file is within folder, or insert entire path. ";
		cin >> txtDoc;

		inFile.open(txtDoc);
	}

	//Prompt word
	targetWord = Word();
	cout << "\nSearching for " << targetWord << " in the void..." << endl;

	//Mucho ifs
	while (inFile && !found) {
		inFile >> letter;	//Look at first letter in file
		if (targetWord[0] == letter) {	//If first letter matches
			lineStart = lineNum;	//Mark starting line
			
			if (indexWord == (targetWord.length() - 1)) {	//If word is one letter long
				lineEnd = lineNum;	//Mark ending line
				found = true;		//Yayyy! Celebration time!
			}

			indexWord = indexWord + 1;	//Go to second letter in word
			lineNum = lineNum + 1;
		}
		else if (targetWord[indexWord] == letter) {	//If any other letter matches
			if (indexWord == targetWord.length() - 1) {	//-1 to account for indexing at 0
				lineEnd = lineNum;	//Mark ending line
				found = true;		//Yayyy! Celebration time!
			}

			indexWord = indexWord + 1;	//If they match, but we're not done yet
			lineNum = lineNum + 1;
		}
		else {
			lineNum = lineNum + 1;	//If nothing matches, try next list character
			indexWord = 0;		//Restart if other beginning letters found along way
		}
	}
	
	if (found) {
		cout << "\nFound it!" << endl;
		cout << "Starts at: " << lineStart << ", ends at: " << lineEnd << endl;
	}
	else {
		cout << "\nSorry bud, couldn't find it :(" << endl;
	}
}