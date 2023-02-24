#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

void PrintMessage(string msg, bool printTop = true, bool printBottom = true){
    if (printTop){
        cout << "+----------------------------------+" << endl;
        cout << "|";
    }
    else{
        cout << "|";
    }
    bool front = true;
    for (int i = msg.length(); i < 34; ++i)
    {
        if (front){
            msg = " " + msg;
        }
        else{
            msg = msg + " ";
        }
        front = !front;
    }
    cout << msg.c_str();
    if (printBottom){
        cout << "|" << endl;
        cout << "+----------------------------------+" << endl;
    }
    else{
        cout << "|" << endl;
    }
}
void PrintHangman(int guessCount = 0){
    if (guessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
    if (guessCount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
    if (guessCount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);
    if (guessCount == 4)
        PrintMessage("/  ", false, false);
    if (guessCount == 5)
        PrintMessage("/| ", false, false);
    if (guessCount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);
    if (guessCount == 7)
        PrintMessage("/ ", false, false);
    if (guessCount >= 8)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);
}
void PrintLetters(string input, char from, char to){
    string s;
    for (char i = from; i <= to; ++i){
        if (input.find(i) == string::npos){
            s += i;
            s += " ";
        }
        else{
            s += "  ";
        }
    }
    PrintMessage(s, false, false);
}
void PrintAvailableLetters(string taken){
    PrintMessage("Available letters");
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}
bool PrintWord(string word, string guessed){
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); ++i){
        if (guessed.find(word[i]) == string::npos){
            won = false;
            s += "_ ";
        }
        else{
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}
string toUpper(string text){
    for (int i = 0; i < text.length(); ++i){
        text[i] = toupper(text[i]);
    }
    return text;
}
string LoadRandomWord(string path){
    int lineCount = 0;
    string word;
    vector<string> v;
    ifstream reader(path);
    if (reader.is_open()){
        while (std::getline(reader, word))
            v.push_back(word);
        int randomLine = rand() % v.size();

        word = v.at(randomLine);
        reader.close();
    }
    return word;

}
int Tries(string word, string guessed){
    int error = 0;
    for (int i = 0; i < guessed.length(); ++i){
        if (word.find(guessed[i]) == string::npos){
            ++error;
        }
    }
    return error;
}
int main(){
    srand(time(0));
    string guesses;
    string wordToGuess;
    wordToGuess = toUpper(LoadRandomWord("wordlist.txt"));
    
    
    int tries = 0;
    bool win = false;
    do
    {
        system("cls");
        PrintMessage("Hangman");
        PrintHangman(tries);
        PrintAvailableLetters(guesses);
        PrintMessage("Guess the word");
        win = PrintWord(wordToGuess, guesses);
        if (win){
            break;
        }
        char x;
        cout << ">";
        cin >> x;
        x = toupper(x);
        if (guesses.find(x) == string::npos)
            guesses += x;
        tries = Tries(wordToGuess, guesses);
    }while (tries < 9);
    
    
    if(win)
        PrintMessage("You win!");
    else
        PrintMessage("Game over!");
    PrintMessage("The word was " + wordToGuess, false);
    
    getchar();
    return 0;
}