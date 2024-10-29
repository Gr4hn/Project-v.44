#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

class Highscore
{
    //Kod för Highscore
};

class Player
{
private:
    string wordToGuess;
    string guessedWord;
    vector<char> incorrectGuesses;
    int maxAttempts;

public:
    Player (const string& word, int attempts) : wordToGuess(word), maxAttempts(attempts) {
        guessedWord = string(word.size(), '_');
    }

    bool guess(char letter) {
        letter = tolower(letter);
        bool correct = false;

        for (size_t i = 0; i < wordToGuess.size(); ++i) {
            if (wordToGuess[i] == letter) {
                guessedWord[i] = letter;
                correct = true;
            }
        }

        if (!correct) {
            incorrectGuesses.push_back(letter);
        }

        return correct;
    }
};
void endGame(bool& gameIsRunning) {
    gameIsRunning = false;
}

void showMenu(vector<string>& words) {
    int choice;
    bool gameIsRunning = true;
    cout <<"Välkommen till spelet Hänga Gubbe!" << endl <<endl;
    do
    {
        cout <<"Välj ett alternativ: " << endl
        << "1. Spela" << endl
        << "2. Highscorelista" << endl
        << "3. Instruktioner" << endl
        << "4. Avsluta" << endl
        << "Ditt val: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout <<"Spela" << endl;

                break;
            case 2:
                cout <<"Highscorelista" << endl;
                break;
            case 3:
                cout <<"Instruktioner" << endl;
                break;
            case 4:
                endGame(gameIsRunning);
                break;
            default:
                cout <<"Felaktigt val, försök igen!" << endl;
                break;
        }
    } while (gameIsRunning);
    cout <<"Tack för att du spelade!" << endl;
}

vector<string> loadWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open the file " << filename << "\n";
        return words;
    }

    string word;
    while (getline(file, word)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }
    return words;
}

int main ()
{
    vector<string>words = loadWordsFromFile("words.txt");
    showMenu(words);
    
    return 0;
}
