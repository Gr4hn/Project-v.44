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

class Game
{
private:
    string wordToGuess;
    string guessedWord;
    vector<char> incorrectGuesses;
    int maxAttempts;

public:
    Game(const std::string& word, int maxAttempts = 10) : wordToGuess(word), maxAttempts(maxAttempts) {
        guessedWord = std::string(word.size(), '_');
    }

    char letters[29] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'å', 'ä', 'ö'};
    string randomword;
    char randomletter;
    
 
    void randomLetter() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 28); // 29 letters in the array
        int index = dis(gen);
        randomletter = letters[index];
    }

    void randomWord(vector<string>& words) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, words.size() - 1);
        int index = dis(gen);
        randomword = words.at(index);
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

    bool endOfAttempts()
    {
        return incorrectGuesses.size() >= maxAttempts;
    }

    bool win()
    {
        return guessedWord == wordToGuess;
    }
};

void instructions()
{
    cout << "Dessa instruktioner & reglergäller för Hänga Gubbe" << endl << endl
    << "Spelet handlar om att gissa ett slumpmäsigt utvalt ord" << endl
    << "Ordet är dolt och anges med understräck som visar hur många bokstäver ordet innehåller" << endl
    << "Du har 10 gissningar innan gubben hängs, för varje felaktigt gissat bokstav förlorar du en gissning " << endl
    << "För varje bokstav du gissar rätt visas bokstaven i ordet" << endl
    << "Du kan gissa på hela ordet när som helst, men gissar du fel kommer omgången att avslutas." << endl
    << "Under din spelomgång kommer ett slumpmässig bokstav att räkna som 2 gissningar. Du får inte veta vilken bokstav detat är." << endl << endl
    << "Lycka till!" << endl << endl;
}

void endGame(bool& gameIsRunning) {
    gameIsRunning = false;
}

void showMenu(vector<string>& words) {
    int choice;
    bool gameIsRunning = true;
    cout <<"Välkommen till spelet Hänga Gubbe!" << endl << endl << endl;
    do
    {
        cout << "Huvudmeny" << endl << endl
        <<"Välj ett alternativ: " << endl
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
                cout << endl << "Instruktioner" << endl << endl;
                instructions();
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

void gamePlay(vector<string>& words) {
    //code
}

int main ()
{
    vector<string>words = loadWordsFromFile("words.txt");
    //Game game;
    showMenu(words);
    
    return 0;
}
