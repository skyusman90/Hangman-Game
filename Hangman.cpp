#include <iostream>
#include <string>
#include <fstream>
#include <time.h> //included to generate random numbers to choose a random word from the file
using namespace std;

string readWords(ifstream& fin, int totalWords); //function to read the words from the file for the game
void displayMenu(); //function to display the main menu
void changeWord(string &word); //function to display the random word from the file
int getTotalWords(ifstream& fin); //function to display the total number of words from file
bool checkWord(string word, char userInput); //function to check the user input
void displayWord2(string &word, char user, string actualWord); //function to display the word after each guess


int main(){

    //variables used in the program
    int score = 0; //to keep the score of the user
    int tries = 0; //the number of tries that depend on the difficulty
    string word;
    int difficulty;
    bool playGame = true;

    ifstream fin("e:hangman.txt");
    int totalWords = getTotalWords(fin);
    fin.close();

    srand(time(NULL));

    int userChoice;

    while(playGame){
        displayMenu();
        cin >> userChoice; //getting user input for choosing game dificulty or exiting the game
        if(userChoice == 1 || userChoice == 2 || userChoice == 3 || userChoice == 0){
            if(userChoice == 0){ //to exit the game
                cout << "Thank you for playing the game" << endl;
                playGame = false;
            }
            else if(userChoice == 1){ //easy difficulty (tries = 5)
                tries = 5;
                char userInput;
                ifstream fin("e:hangman.txt");
                word = readWords(fin, totalWords); //getting random word from file
                fin.close();
                string tempWord = word;
                changeWord(word); //removing letters from the word for the user to guess
                while(tries > 0){
                    cout << word << endl; //displaying the word with removed letters
                    int check = 0;
                    for(int i = 0; i < word.length(); i++){ 
                        if(word.at(i) != '*'){
                            check++;
                        }
                    }
                    if(check == word.length()){ //checking if the word has been completely guessed if there are no removed letters
                        cout << "You have correctly guessed the word. You Won" << endl;
                        break;
                    }
                    cout << "Enter guess(lowercase): "; //taking the user guess
                    cin >> userInput;
                    if((int)userInput >= 97 && (int)userInput <= 122){ //checking if the user has entered the characters a-z and no invalid input
                        if(checkWord(tempWord, userInput)){ //checks if the user guess is present in the word
                            displayWord2(word, userInput, tempWord); //displays the word after correclty guessing the letter
                        }
                        else{
                            cout << "Wrong guess" << endl;
                            tries--;
                            cout << "Tries Left: " << tries << endl; //having the no of tries decremented by 1 if the user incorrectly guesses.
                        }
                    }
                    else{
                        cout << "Enter correct input" << endl;
                    }
                }

            }
            else if(userChoice == 2){ //medium difficulty (tries = 3)
                tries = 3;
                char userInput;
                ifstream fin("e:hangman.txt");
                word = readWords(fin, totalWords); //getting random word from file
                fin.close();
                string tempWord = word;
                changeWord(word); //removing letters from the word for the user to guess
                while(tries > 0){
                    cout << word << endl; //displaying the word with removed letters
                    int check = 0;
                    for(int i = 0; i < word.length(); i++){ 
                        if(word.at(i) != '*'){
                            check++;
                        }
                    }
                    if(check == word.length()){ //checking if the word has been completely guessed if there are no removed letters
                        cout << "You have correctly guessed the word. You Won" << endl;
                        break;
                    }
                    cout << "Enter guess(lowercase): "; //taking the user guess
                    cin >> userInput;
                    if((int)userInput >= 97 && (int)userInput <= 122){ //checking if the user has entered the characters a-z and no invalid input
                        if(checkWord(tempWord, userInput)){ //checks if the user guess is present in the word
                            displayWord2(word, userInput, tempWord); //displays the word after correclty guessing the letter
                        }
                        else{
                            cout << "Wrong guess" << endl;
                            tries--;
                            cout << "Tries Left: " << tries << endl; //having the no of tries decremented by 1 if the user incorrectly guesses.
                        }
                    }
                    else{
                        cout << "Enter correct input" << endl;
                    }
                }                
            }
            else if(userChoice == 3){ //hard difficulty (tries = 1)
                tries = 1;
                char userInput;
                ifstream fin("e:hangman.txt");
                word = readWords(fin, totalWords); //getting random word from file
                fin.close();
                string tempWord = word;
                changeWord(word); //removing letters from the word for the user to guess
                while(tries > 0){
                    cout << word << endl; //displaying the word with removed letters
                    int check = 0;
                    for(int i = 0; i < word.length(); i++){ 
                        if(word.at(i) != '*'){
                            check++;
                        }
                    }
                    if(check == word.length()){ //checking if the word has been completely guessed if there are no removed letters
                        cout << "You have correctly guessed the word. You Won" << endl;
                        break;
                    }
                    cout << "Enter guess(lowercase): "; //taking the user guess
                    cin >> userInput;
                    if((int)userInput >= 97 && (int)userInput <= 122){ //checking if the user has entered the characters a-z and no invalid input
                        if(checkWord(tempWord, userInput)){ //checks if the user guess is present in the word
                            displayWord2(word, userInput, tempWord); //displays the word after correclty guessing the letter
                        }
                        else{
                            cout << "Wrong guess" << endl;
                            tries--;
                            cout << "Tries Left: " << tries << endl; //having the no of tries decremented by 1 if the user incorrectly guesses.
                        }
                    }
                    else{
                        cout << "Enter correct input" << endl;
                    }
                }                
            }
        }
    }

    return 0;
}
void displayMenu(){

    cout << "--------------------------------------------------" << endl;
    cout << "Welcome to Hangman Game" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Select Difficulty" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Press 0 to exit" << endl;
    cout << endl;
    cout << "--->";

}
string readWords(ifstream& fin, int totalWords){
    string *words = new string[totalWords];
    string word;
    int i = 0;
    string temp;
    while(fin >> temp){
        words[i] = temp;
        i++;
    }

    int randomIndex = (rand() % totalWords); //to generate random numbers
    word = words[randomIndex];

    delete[] words;
    fin.close();
    return word;
}
int getTotalWords(ifstream& fin){
    int totalWords = 0;
    string temp;
    while(fin >> temp){
        totalWords++;
    }
    return totalWords;
}
void changeWord(string &word){
    int displayLetters = (word.length() / 2);
    for(int i = 0; i < displayLetters; i++){
        int random = (rand() % word.length());
        word.at(random) = '*';
    }
}
bool checkWord(string word, char userInput){
    bool temp = false;
    for(int i = 0; i < word.length(); i++){
        if(word.at(i) == userInput){
            temp = true;
            break;
        }
    }
    return temp;
}
void displayWord2(string &word, char user, string actualWord){
    for(int i = 0; i < word.length(); i++){
        if(actualWord.at(i) == user){
            word.at(i) = actualWord.at(i);
        }
    }
    cout << word << endl;
}