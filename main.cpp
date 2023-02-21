#include <iostream>
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
    for (int i = msg.length(); i < 34; i++)
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
int main(){
    PrintMessage("Hangman");
    PrintHangman(8);
    getchar();
    return 0;
}