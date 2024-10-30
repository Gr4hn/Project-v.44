/*
    Hangman Game by "Projektgrupp 1"
    Authors: Anna Schwartz, Eric Grahn, Fredrik Storm
*/

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void instructions();
void endGame(bool& gameIsRunning);
void showMenu(vector<string>& words, vector<string>& letters);
void gamePlay(vector<string>& words, vector<string>& letters);
string Randomizer(vector<string>list);
void splashScreen();
void clearScreen();


class Highscore
{
    //Kod för Highscore
};

class Game
{
private:
    string wordToGuess;
    string guessedLetters;
    vector<char> incorrectGuesses;
    int maxAttempts;

public:
    Game(const std::string& word, int maxAttempts = 10) : wordToGuess(word), maxAttempts(maxAttempts) {
        guessedLetters = std::string(word.size(), '_');
    }

    string randomword; 

    void drawHangman() {
        //rita ut gubbe, använd incorrectGuesses.size() för att veta hur många fel som gjorts
    }

    void displayStatus() {
        clearScreen();
        drawHangman();
        cout << "Ord: ";
        for (char c : guessedLetters) {
            cout << c << " ";
        }
        cout << endl << "Felgissningar: ";
        for (char ch : incorrectGuesses) {
            cout << ch << " ";
        }
        cout << endl << "Antal försök kvar: " << maxAttempts - incorrectGuesses.size() << endl;
    }

    bool guess(char letter) {
        letter = tolower(letter);
        bool correct = false;

        for (size_t i = 0; i < wordToGuess.size(); ++i) {
            if (wordToGuess[i] == letter) {
                guessedLetters[i] = letter;
                correct = true;
            }
        }

        // kolla här om vår random letter för twist träffas, pusha in samma bokstav 2 ggr?
        if (!correct) {
            incorrectGuesses.push_back(letter);
        }

        return correct;
    }

    bool endOfAttempts()
    {
        return incorrectGuesses.size() >= maxAttempts || guessedLetters == wordToGuess;
    }

    bool win()
    {
        return guessedLetters == wordToGuess;
    }
};


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



void showHighscore (vector<string>& words) {
    cout << "Highscore" << endl;
}

void clearScreen() {
#ifdef _WIN32
    // Windows-specific code
    system("cls");
#else
    // Unix-like system-specific code
    std::cout << "\033[2J\033[1;1H";
#endif
}

void sleepForSeconds(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

void splashScreen() {
    cout << "\e[38;5;250;48;5;7m▄\e[38;5;7;48;5;251m▄▄▄\e[38;5;7;48;5;7m▄\e[38;5;7;48;5;250m▄\e[38;5;250;48;5;249m▄\e[38;5;145;48;5;145m▄\e[48;5;248m \e[38;5;145;48;5;145m▄\e[38;5;248;48;5;248m▄\e[38;5;145;48;5;145m▄\e[38;5;101;48;5;245m▄\e[38;5;241;48;5;241m▄\e[38;5;241;48;5;59m▄\e[38;5;101;48;5;102m▄\e[38;5;238;48;5;239m▄\e[38;5;239;48;5;239m▄\e[38;5;240;48;5;239m▄▄\e[38;5;241;48;5;241m▄\e[48;5;145m \e[38;5;145;48;5;145m▄▄▄\e[38;5;249;48;5;250m▄\e[38;5;243;48;5;101m▄\e[38;5;247;48;5;144m▄\e[38;5;249;48;5;250m▄\e[38;5;249;48;5;249m▄\e[38;5;144;48;5;249m▄▄\e[38;5;101;48;5;246m▄\e[38;5;239;48;5;238m▄\e[38;5;236;48;5;239m▄\e[38;5;235;48;5;238m▄▄\e[38;5;234;48;5;236m▄\e[38;5;234;48;5;234m▄\e[38;5;233;48;5;239m▄\e[38;5;237;48;5;250m▄\e[38;5;144;48;5;187m▄\e[38;5;187;48;5;187m▄\e[38;5;187;48;5;223m▄▄\e[38;5;223;48;5;223m▄\e[38;5;230;48;5;223m▄\e[38;5;230;48;5;187m▄\e[38;5;223;48;5;223m▄▄\e[38;5;223;48;5;187m▄▄▄\e[38;5;254;48;5;187m▄\e[38;5;187;48;5;187m▄▄▄▄▄\e[38;5;223;48;5;187m▄\e[38;5;187;48;5;187m▄▄▄▄▄\e[38;5;187;48;5;144m▄\e[38;5;101;48;5;241m▄\e[38;5;238;48;5;239m▄\e[38;5;144;48;5;7m▄\e[38;5;251;48;5;7m▄\e[38;5;7;48;5;7m▄▄▄▄▄▄\e[38;5;251;48;5;7m▄▄▄\e[38;5;7;48;5;7m▄\e[m" << endl;
    cout << "\e[38;5;145;48;5;250m▄▄▄▄\e[38;5;145;48;5;249m▄▄▄\e[38;5;145;48;5;145m▄\e[38;5;145;48;5;248m▄\e[38;5;145;48;5;145m▄▄▄\e[38;5;145;48;5;246m▄▄\e[38;5;144;48;5;245m▄\e[38;5;242;48;5;243m▄\e[38;5;239;48;5;238m▄\e[38;5;240;48;5;240m▄\e[38;5;241;48;5;59m▄▄\e[38;5;242;48;5;241m▄\e[38;5;145;48;5;145m▄▄\e[38;5;249;48;5;145m▄▄\e[38;5;145;48;5;145m▄\e[38;5;249;48;5;246m▄\e[38;5;101;48;5;246m▄\e[38;5;246;48;5;250m▄\e[38;5;242;48;5;144m▄\e[38;5;144;48;5;101m▄\e[38;5;95;48;5;59m▄\e[38;5;238;48;5;236m▄\e[38;5;237;48;5;235m▄\e[38;5;237;48;5;234m▄▄▄\e[38;5;237;48;5;233m▄\e[38;5;236;48;5;233m▄\e[38;5;233;48;5;232m▄\e[38;5;233;48;5;234m▄\e[38;5;234;48;5;241m▄\e[38;5;238;48;5;249m▄\e[38;5;187;48;5;187m▄\e[38;5;187;48;5;223m▄▄▄\e[38;5;223;48;5;187m▄\e[38;5;230;48;5;223m▄▄\e[38;5;223;48;5;223m▄\e[38;5;223;48;5;230m▄\e[38;5;223;48;5;223m▄▄▄\e[38;5;187;48;5;223m▄\e[38;5;223;48;5;187m▄▄▄\e[38;5;187;48;5;187m▄▄▄▄▄▄▄\e[38;5;187;48;5;250m▄\e[38;5;240;48;5;240m▄\e[38;5;241;48;5;242m▄\e[38;5;187;48;5;187m▄▄▄▄\e[38;5;187;48;5;251m▄▄▄\e[38;5;251;48;5;251m▄\e[38;5;7;48;5;251m▄▄\e[38;5;251;48;5;187m▄\e[m" << endl;
    cout << "\e[38;5;187;48;5;249m▄\e[38;5;251;48;5;249m▄\e[38;5;7;48;5;145m▄\e[38;5;249;48;5;145m▄\e[38;5;145;48;5;145m▄▄▄▄▄▄▄▄▄▄\e[38;5;144;48;5;144m▄\e[38;5;240;48;5;59m▄\e[38;5;239;48;5;239m▄\e[38;5;240;48;5;240m▄\e[38;5;241;48;5;241m▄▄\e[38;5;243;48;5;242m▄\e[38;5;145;48;5;145m▄\e[38;5;249;48;5;145m▄\e[38;5;249;48;5;249m▄▄▄\e[38;5;246;48;5;144m▄\e[38;5;240;48;5;245m▄\e[38;5;240;48;5;246m▄\e[38;5;187;48;5;101m▄\e[38;5;187;48;5;223m▄\e[38;5;101;48;5;180m▄\e[38;5;240;48;5;101m▄\e[38;5;239;48;5;239m▄\e[38;5;238;48;5;238m▄▄▄▄\e[38;5;239;48;5;238m▄\e[38;5;239;48;5;237m▄\e[38;5;238;48;5;234m▄\e[38;5;234;48;5;233m▄\e[38;5;235;48;5;234m▄\e[38;5;238;48;5;242m▄\e[38;5;144;48;5;254m▄\e[38;5;187;48;5;223m▄\e[38;5;223;48;5;223m▄\e[38;5;230;48;5;229m▄\e[38;5;230;48;5;230m▄\e[38;5;229;48;5;223m▄\e[38;5;230;48;5;187m▄\e[38;5;230;48;5;223m▄\e[38;5;230;48;5;187m▄▄\e[38;5;223;48;5;223m▄\e[38;5;223;48;5;230m▄\e[38;5;223;48;5;223m▄\e[48;5;187m \e[38;5;187;48;5;187m▄▄▄▄▄▄\e[38;5;223;48;5;187m▄\e[38;5;187;48;5;187m▄▄\e[38;5;101;48;5;144m▄\e[38;5;240;48;5;242m▄\e[38;5;187;48;5;187m▄▄▄▄▄▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;187;48;5;187m▄▄\e[38;5;251;48;5;187m▄\e[38;5;7;48;5;251m▄\e[38;5;7;48;5;249m▄▄\e[38;5;250;48;5;249m▄\e[38;5;250;48;5;145m▄\e[38;5;249;48;5;145m▄▄▄\e[38;5;145;48;5;145m▄\e[38;5;249;48;5;145m▄\e[38;5;145;48;5;145m▄\e[38;5;247;48;5;144m▄\e[38;5;240;48;5;240m▄\e[38;5;239;48;5;239m▄\e[38;5;240;48;5;240m▄\e[38;5;59;48;5;241m▄\e[38;5;241;48;5;241m▄\e[38;5;247;48;5;245m▄\e[38;5;249;48;5;145m▄\e[38;5;249;48;5;249m▄▄▄▄\e[38;5;144;48;5;144m▄\e[38;5;144;48;5;95m▄\e[38;5;187;48;5;144m▄\e[38;5;223;48;5;223m▄\e[38;5;180;48;5;187m▄\e[38;5;95;48;5;137m▄\e[38;5;240;48;5;95m▄\e[38;5;240;48;5;101m▄\e[38;5;238;48;5;239m▄\e[38;5;237;48;5;238m▄\e[38;5;238;48;5;238m▄▄▄\e[38;5;239;48;5;239m▄\e[38;5;238;48;5;238m▄\e[38;5;235;48;5;234m▄\e[38;5;234;48;5;235m▄\e[38;5;235;48;5;235m▄\e[38;5;239;48;5;241m▄\e[38;5;187;48;5;187m▄\e[38;5;223;48;5;223m▄▄\e[38;5;223;48;5;230m▄\e[38;5;230;48;5;230m▄\e[38;5;223;48;5;223m▄\e[38;5;187;48;5;223m▄▄\e[38;5;187;48;5;229m▄\e[38;5;187;48;5;223m▄▄\e[38;5;223;48;5;223m▄\e[38;5;229;48;5;187m▄\e[38;5;223;48;5;187m▄▄▄▄\e[38;5;187;48;5;187m▄\e[38;5;223;48;5;223m▄▄\e[38;5;223;48;5;187m▄\e[38;5;187;48;5;187m▄\e[38;5;144;48;5;101m▄\e[38;5;59;48;5;239m▄\e[38;5;187;48;5;144m▄\e[38;5;187;48;5;187m▄▄\e[38;5;223;48;5;187m▄▄\e[38;5;187;48;5;187m▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;187;48;5;223m▄▄\e[38;5;187;48;5;187m▄▄▄\e[38;5;187;48;5;7m▄\e[38;5;187;48;5;250m▄\e[38;5;7;48;5;250m▄\e[38;5;250;48;5;250m▄▄\e[38;5;249;48;5;249m▄▄▄▄\e[38;5;247;48;5;247m▄\e[38;5;239;48;5;240m▄\e[38;5;239;48;5;239m▄▄\e[48;5;59m \e[38;5;59;48;5;241m▄\e[38;5;249;48;5;248m▄\e[38;5;249;48;5;249m▄▄▄▄\e[38;5;250;48;5;249m▄\e[38;5;249;48;5;249m▄\e[38;5;137;48;5;144m▄\e[38;5;180;48;5;187m▄\e[38;5;95;48;5;180m▄\e[38;5;237;48;5;95m▄\e[38;5;237;48;5;238m▄\e[38;5;238;48;5;238m▄\e[38;5;239;48;5;238m▄\e[38;5;238;48;5;236m▄\e[38;5;236;48;5;234m▄\e[38;5;235;48;5;234m▄\e[38;5;235;48;5;235m▄\e[38;5;235;48;5;237m▄\e[38;5;237;48;5;239m▄\e[38;5;239;48;5;239m▄\e[38;5;238;48;5;237m▄\e[38;5;236;48;5;235m▄\e[38;5;235;48;5;234m▄\e[38;5;238;48;5;239m▄\e[38;5;187;48;5;187m▄▄\e[38;5;187;48;5;223m▄\e[38;5;187;48;5;187m▄▄▄▄▄▄▄\e[38;5;187;48;5;223m▄▄\e[38;5;223;48;5;229m▄▄\e[38;5;223;48;5;223m▄\e[38;5;223;48;5;229m▄\e[38;5;223;48;5;230m▄\e[38;5;187;48;5;223m▄▄\e[38;5;181;48;5;223m▄\e[38;5;144;48;5;223m▄\e[38;5;144;48;5;187m▄\e[38;5;239;48;5;101m▄\e[38;5;101;48;5;241m▄\e[38;5;187;48;5;187m▄\e[38;5;187;48;5;223m▄\e[38;5;223;48;5;223m▄▄▄▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;7;48;5;187m▄▄\e[38;5;251;48;5;187m▄\e[38;5;187;48;5;187m▄▄▄▄▄\e[38;5;187;48;5;7m▄\e[38;5;187;48;5;250m▄▄\e[38;5;251;48;5;250m▄\e[38;5;250;48;5;250m▄\e[38;5;250;48;5;249m▄\e[38;5;247;48;5;247m▄\e[38;5;239;48;5;239m▄\e[48;5;239m \e[38;5;240;48;5;239m▄\e[38;5;241;48;5;241m▄\e[38;5;241;48;5;59m▄\e[38;5;7;48;5;250m▄▄▄\e[38;5;251;48;5;250m▄\e[38;5;7;48;5;250m▄▄\e[38;5;251;48;5;7m▄\e[38;5;144;48;5;240m▄\e[38;5;239;48;5;240m▄\e[38;5;235;48;5;237m▄\e[38;5;234;48;5;236m▄\e[38;5;235;48;5;235m▄\e[38;5;238;48;5;238m▄▄\e[38;5;238;48;5;237m▄\e[38;5;235;48;5;235m▄▄\e[38;5;236;48;5;234m▄\e[38;5;237;48;5;235m▄\e[38;5;237;48;5;237m▄\e[38;5;238;48;5;238m▄\e[38;5;239;48;5;239m▄\e[38;5;237;48;5;236m▄\e[38;5;236;48;5;236m▄\e[38;5;237;48;5;237m▄\e[38;5;144;48;5;249m▄\e[38;5;251;48;5;187m▄\e[38;5;7;48;5;187m▄▄▄\e[38;5;251;48;5;187m▄▄\e[38;5;187;48;5;187m▄▄▄▄▄▄\e[38;5;223;48;5;187m▄\e[38;5;180;48;5;223m▄\e[38;5;144;48;5;223m▄\e[38;5;137;48;5;187m▄\e[38;5;101;48;5;144m▄\e[38;5;95;48;5;241m▄\e[38;5;237;48;5;239m▄\e[38;5;236;48;5;239m▄\e[38;5;237;48;5;239m▄\e[38;5;239;48;5;241m▄\e[38;5;237;48;5;242m▄\e[38;5;237;48;5;95m▄\e[38;5;239;48;5;101m▄\e[38;5;187;48;5;187m▄\e[38;5;223;48;5;223m▄▄▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;245;48;5;249m▄\e[38;5;247;48;5;250m▄\e[38;5;247;48;5;7m▄▄\e[38;5;7;48;5;7m▄\e[38;5;187;48;5;251m▄\e[38;5;187;48;5;187m▄▄▄▄▄▄▄▄\e[38;5;246;48;5;247m▄\e[38;5;239;48;5;239m▄\e[48;5;239m \e[38;5;240;48;5;240m▄\e[38;5;241;48;5;241m▄▄\e[38;5;187;48;5;7m▄\e[38;5;187;48;5;251m▄\e[38;5;187;48;5;187m▄▄\e[38;5;187;48;5;251m▄▄▄\e[38;5;144;48;5;250m▄\e[38;5;180;48;5;240m▄\e[38;5;101;48;5;239m▄\e[38;5;239;48;5;237m▄\e[38;5;95;48;5;237m▄\e[38;5;240;48;5;181m▄\e[38;5;240;48;5;239m▄\e[38;5;239;48;5;238m▄\e[38;5;237;48;5;237m▄▄▄▄\e[38;5;238;48;5;237m▄\e[38;5;239;48;5;238m▄\e[38;5;240;48;5;240m▄\e[38;5;239;48;5;237m▄\e[38;5;240;48;5;236m▄\e[38;5;237;48;5;238m▄\e[38;5;95;48;5;95m▄\e[38;5;144;48;5;7m▄\e[38;5;187;48;5;7m▄\e[38;5;251;48;5;7m▄\e[38;5;187;48;5;7m▄▄\e[38;5;187;48;5;251m▄▄\e[38;5;187;48;5;187m▄▄▄\e[38;5;180;48;5;187m▄\e[38;5;144;48;5;187m▄\e[38;5;101;48;5;180m▄\e[38;5;138;48;5;187m▄\e[38;5;240;48;5;101m▄\e[38;5;239;48;5;236m▄\e[38;5;235;48;5;236m▄\e[38;5;238;48;5;235m▄\e[38;5;236;48;5;236m▄▄\e[38;5;240;48;5;236m▄\e[38;5;238;48;5;237m▄\e[38;5;237;48;5;237m▄\e[38;5;237;48;5;239m▄\e[38;5;241;48;5;238m▄\e[38;5;187;48;5;187m▄\e[38;5;223;48;5;223m▄▄▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;240;48;5;240m▄\e[38;5;239;48;5;240m▄\e[38;5;240;48;5;240m▄\e[38;5;239;48;5;240m▄\e[38;5;238;48;5;243m▄▄▄\e[38;5;239;48;5;250m▄\e[38;5;241;48;5;187m▄\e[38;5;246;48;5;187m▄\e[38;5;187;48;5;187m▄▄▄▄\e[38;5;101;48;5;245m▄\e[48;5;239m \e[38;5;239;48;5;239m▄\e[38;5;240;48;5;240m▄\e[38;5;59;48;5;241m▄\e[38;5;241;48;5;241m▄\e[38;5;187;48;5;187m▄\e[38;5;223;48;5;223m▄▄▄▄▄\e[38;5;223;48;5;187m▄▄\e[38;5;180;48;5;180m▄\e[38;5;101;48;5;137m▄\e[38;5;239;48;5;240m▄\e[38;5;238;48;5;95m▄\e[38;5;238;48;5;240m▄\e[38;5;238;48;5;238m▄\e[38;5;237;48;5;238m▄\e[38;5;236;48;5;237m▄\e[38;5;237;48;5;237m▄\e[38;5;237;48;5;238m▄\e[38;5;239;48;5;238m▄\e[38;5;239;48;5;239m▄\e[38;5;240;48;5;240m▄▄\e[38;5;239;48;5;239m▄▄\e[38;5;237;48;5;236m▄\e[38;5;8;48;5;95m▄\e[38;5;187;48;5;7m▄\e[38;5;187;48;5;187m▄▄▄▄▄▄▄\e[38;5;144;48;5;187m▄\e[38;5;180;48;5;180m▄\e[38;5;237;48;5;101m▄\e[38;5;239;48;5;95m▄\e[38;5;236;48;5;238m▄\e[38;5;235;48;5;239m▄\e[38;5;238;48;5;239m▄\e[38;5;238;48;5;236m▄\e[38;5;236;48;5;236m▄\e[38;5;234;48;5;235m▄\e[38;5;236;48;5;238m▄\e[38;5;237;48;5;236m▄\e[38;5;238;48;5;239m▄\e[38;5;187;48;5;238m▄▄\e[38;5;187;48;5;242m▄\e[38;5;223;48;5;187m▄\e[38;5;223;48;5;223m▄\e[38;5;229;48;5;223m▄▄\e[38;5;223;48;5;223m▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;242;48;5;242m▄\e[38;5;242;48;5;243m▄\e[38;5;243;48;5;241m▄\e[38;5;101;48;5;241m▄▄\e[38;5;242;48;5;59m▄\e[38;5;240;48;5;240m▄\e[38;5;239;48;5;239m▄\e[38;5;239;48;5;238m▄\e[38;5;243;48;5;241m▄\e[38;5;187;48;5;7m▄\e[38;5;223;48;5;223m▄▄\e[38;5;187;48;5;187m▄\e[38;5;242;48;5;101m▄\e[38;5;239;48;5;239m▄▄\e[38;5;240;48;5;240m▄\e[38;5;241;48;5;241m▄\e[38;5;101;48;5;242m▄\e[38;5;223;48;5;223m▄\e[38;5;229;48;5;223m▄▄\e[38;5;223;48;5;223m▄\e[48;5;223m \e[38;5;223;48;5;223m▄▄▄\e[38;5;187;48;5;180m▄\e[38;5;240;48;5;95m▄\e[38;5;238;48;5;238m▄▄\e[38;5;238;48;5;237m▄\e[38;5;239;48;5;237m▄\e[38;5;238;48;5;236m▄▄▄\e[38;5;236;48;5;236m▄\e[38;5;237;48;5;237m▄\e[38;5;239;48;5;240m▄\e[38;5;240;48;5;240m▄▄\e[38;5;239;48;5;240m▄\e[38;5;238;48;5;238m▄\e[38;5;240;48;5;238m▄\e[38;5;187;48;5;101m▄\e[38;5;187;48;5;187m▄▄\e[38;5;7;48;5;187m▄\e[38;5;144;48;5;187m▄▄\e[38;5;101;48;5;187m▄\e[38;5;240;48;5;144m▄\e[38;5;237;48;5;144m▄\e[38;5;236;48;5;95m▄\e[38;5;239;48;5;95m▄\e[38;5;237;48;5;237m▄\e[38;5;236;48;5;235m▄\e[38;5;236;48;5;236m▄\e[38;5;236;48;5;233m▄\e[38;5;235;48;5;236m▄\e[38;5;237;48;5;237m▄\e[38;5;238;48;5;237m▄\e[38;5;239;48;5;235m▄\e[38;5;237;48;5;236m▄\e[38;5;238;48;5;237m▄\e[38;5;144;48;5;101m▄\e[38;5;223;48;5;223m▄\e[38;5;229;48;5;223m▄\e[38;5;229;48;5;229m▄▄▄\e[48;5;229m  \e[38;5;223;48;5;223m▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;238;48;5;242m▄\e[38;5;240;48;5;241m▄\e[38;5;240;48;5;242m▄\e[38;5;239;48;5;243m▄\e[38;5;240;48;5;101m▄\e[38;5;240;48;5;241m▄\e[38;5;241;48;5;240m▄\e[38;5;59;48;5;241m▄\e[38;5;239;48;5;239m▄\e[38;5;101;48;5;101m▄\e[38;5;187;48;5;187m▄\e[38;5;187;48;5;223m▄\e[38;5;223;48;5;223m▄\e[38;5;250;48;5;180m▄\e[38;5;241;48;5;241m▄\e[38;5;239;48;5;239m▄▄\e[38;5;240;48;5;240m▄\e[38;5;241;48;5;241m▄\e[38;5;144;48;5;246m▄\e[38;5;223;48;5;223m▄▄▄▄▄\e[38;5;229;48;5;223m▄▄▄\e[38;5;223;48;5;187m▄\e[38;5;101;48;5;95m▄\e[38;5;239;48;5;238m▄\e[38;5;239;48;5;236m▄\e[38;5;237;48;5;234m▄\e[38;5;237;48;5;236m▄▄\e[38;5;238;48;5;238m▄\e[38;5;238;48;5;237m▄▄▄\e[38;5;237;48;5;238m▄\e[38;5;238;48;5;239m▄▄▄▄\e[38;5;248;48;5;247m▄\e[38;5;238;48;5;249m▄\e[38;5;237;48;5;144m▄\e[38;5;95;48;5;144m▄\e[38;5;240;48;5;101m▄\e[38;5;237;48;5;242m▄\e[38;5;235;48;5;241m▄\e[38;5;237;48;5;95m▄\e[38;5;237;48;5;235m▄\e[38;5;236;48;5;237m▄\e[38;5;234;48;5;234m▄\e[38;5;235;48;5;236m▄\e[38;5;237;48;5;236m▄\e[38;5;236;48;5;237m▄\e[38;5;235;48;5;237m▄\e[38;5;236;48;5;236m▄\e[38;5;237;48;5;236m▄\e[38;5;237;48;5;237m▄\e[38;5;144;48;5;238m▄\e[38;5;187;48;5;101m▄\e[38;5;223;48;5;144m▄▄\e[38;5;223;48;5;187m▄\e[38;5;229;48;5;229m▄▄\e[48;5;229m \e[38;5;229;48;5;229m▄▄\e[48;5;229m \e[38;5;229;48;5;229m▄▄\e[38;5;223;48;5;229m▄\e[38;5;223;48;5;223m▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;240;48;5;239m▄\e[38;5;243;48;5;242m▄\e[38;5;246;48;5;8m▄\e[38;5;246;48;5;243m▄\e[38;5;246;48;5;241m▄\e[38;5;243;48;5;240m▄\e[38;5;241;48;5;240m▄\e[38;5;59;48;5;241m▄\e[38;5;240;48;5;242m▄\e[38;5;245;48;5;245m▄\e[38;5;187;48;5;187m▄▄\e[38;5;144;48;5;187m▄\e[38;5;138;48;5;181m▄\e[38;5;138;48;5;7m▄\e[38;5;101;48;5;187m▄\e[38;5;242;48;5;144m▄\e[38;5;101;48;5;101m▄\e[38;5;144;48;5;101m▄\e[38;5;7;48;5;249m▄\e[38;5;187;48;5;187m▄\e[38;5;187;48;5;223m▄▄▄▄▄▄▄\e[38;5;223;48;5;223m▄\e[38;5;180;48;5;144m▄\e[38;5;101;48;5;240m▄\e[38;5;95;48;5;239m▄\e[38;5;237;48;5;238m▄\e[38;5;237;48;5;237m▄▄\e[38;5;237;48;5;238m▄▄\e[38;5;237;48;5;237m▄\e[38;5;237;48;5;238m▄\e[38;5;237;48;5;237m▄\e[38;5;237;48;5;238m▄▄\e[38;5;236;48;5;237m▄\e[38;5;236;48;5;236m▄\e[38;5;7;48;5;247m▄\e[38;5;237;48;5;233m▄\e[38;5;234;48;5;234m▄\e[38;5;236;48;5;238m▄▄\e[38;5;238;48;5;239m▄\e[38;5;237;48;5;236m▄\e[38;5;236;48;5;236m▄\e[38;5;237;48;5;237m▄\e[38;5;236;48;5;235m▄\e[38;5;236;48;5;236m▄\e[38;5;234;48;5;236m▄\e[38;5;237;48;5;238m▄\e[38;5;238;48;5;236m▄\e[38;5;95;48;5;237m▄\e[38;5;144;48;5;238m▄\e[38;5;230;48;5;101m▄\e[38;5;223;48;5;223m▄▄\e[38;5;229;48;5;223m▄▄\e[38;5;229;48;5;229m▄▄▄▄▄▄\e[48;5;229m   \e[38;5;229;48;5;229m▄▄\e[38;5;229;48;5;223m▄\e[38;5;223;48;5;223m▄▄▄\e[m" << endl;
    cout << "\e[38;5;241;48;5;240m▄\e[38;5;101;48;5;101m▄\e[38;5;144;48;5;144m▄▄\e[38;5;246;48;5;246m▄\e[38;5;243;48;5;243m▄\e[38;5;59;48;5;59m▄\e[38;5;240;48;5;241m▄\e[38;5;241;48;5;59m▄\e[38;5;246;48;5;247m▄\e[38;5;144;48;5;187m▄\e[38;5;138;48;5;144m▄\e[38;5;241;48;5;144m▄\e[38;5;239;48;5;137m▄\e[38;5;237;48;5;241m▄\e[38;5;237;48;5;240m▄\e[38;5;239;48;5;238m▄\e[38;5;238;48;5;239m▄\e[38;5;239;48;5;241m▄\e[38;5;241;48;5;246m▄\e[38;5;144;48;5;251m▄\e[38;5;187;48;5;187m▄▄▄▄▄▄▄▄▄\e[38;5;187;48;5;144m▄\e[38;5;95;48;5;138m▄\e[38;5;238;48;5;239m▄\e[38;5;237;48;5;237m▄▄\e[48;5;236m \e[38;5;235;48;5;236m▄▄▄\e[38;5;235;48;5;237m▄\e[38;5;235;48;5;236m▄\e[38;5;235;48;5;235m▄\e[38;5;235;48;5;236m▄\e[38;5;236;48;5;236m▄\e[38;5;238;48;5;101m▄\e[38;5;101;48;5;101m▄\e[38;5;180;48;5;101m▄\e[38;5;144;48;5;101m▄\e[38;5;235;48;5;235m▄\e[38;5;237;48;5;237m▄\e[38;5;237;48;5;238m▄\e[38;5;237;48;5;234m▄\e[38;5;235;48;5;236m▄\e[38;5;236;48;5;236m▄\e[38;5;238;48;5;236m▄\e[38;5;7;48;5;236m▄\e[38;5;187;48;5;239m▄\e[38;5;223;48;5;144m▄\e[38;5;223;48;5;187m▄\e[38;5;223;48;5;223m▄▄\e[38;5;223;48;5;229m▄\e[38;5;229;48;5;229m▄▄▄▄▄\e[38;5;223;48;5;229m▄▄\e[38;5;229;48;5;229m▄▄\e[38;5;223;48;5;229m▄\e[38;5;229;48;5;229m▄\e[38;5;223;48;5;229m▄▄▄▄\e[38;5;223;48;5;223m▄▄▄\e[m" << endl;
    cout << "\e[38;5;240;48;5;240m▄\e[38;5;101;48;5;101m▄\e[38;5;246;48;5;246m▄\e[38;5;246;48;5;144m▄\e[38;5;101;48;5;246m▄\e[38;5;241;48;5;242m▄\e[38;5;240;48;5;240m▄\e[38;5;243;48;5;241m▄\e[38;5;138;48;5;242m▄\e[38;5;101;48;5;144m▄\e[38;5;240;48;5;138m▄\e[38;5;238;48;5;239m▄\e[38;5;239;48;5;239m▄\e[38;5;237;48;5;240m▄\e[38;5;236;48;5;236m▄\e[38;5;237;48;5;237m▄▄▄\e[38;5;238;48;5;239m▄\e[38;5;241;48;5;241m▄\e[38;5;101;48;5;247m▄\e[38;5;187;48;5;187m▄▄▄▄▄▄▄▄▄▄\e[38;5;223;48;5;187m▄\e[38;5;59;48;5;237m▄\e[38;5;237;48;5;236m▄▄\e[38;5;235;48;5;235m▄▄\e[38;5;234;48;5;234m▄▄\e[38;5;235;48;5;234m▄\e[38;5;234;48;5;235m▄\e[38;5;235;48;5;234m▄\e[38;5;236;48;5;235m▄\e[38;5;239;48;5;235m▄\e[38;5;241;48;5;242m▄\e[38;5;242;48;5;101m▄\e[38;5;144;48;5;144m▄\e[38;5;180;48;5;187m▄\e[38;5;144;48;5;144m▄\e[38;5;95;48;5;236m▄▄\e[38;5;101;48;5;238m▄\e[38;5;223;48;5;238m▄\e[38;5;223;48;5;137m▄\e[38;5;223;48;5;223m▄▄▄▄\e[48;5;223m \e[38;5;223;48;5;223m▄▄▄\e[38;5;223;48;5;229m▄▄▄▄▄\e[38;5;223;48;5;223m▄\e[48;5;223m \e[38;5;223;48;5;223m▄▄▄\e[48;5;223m \e[38;5;223;48;5;223m▄▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;240;48;5;240m▄\e[38;5;245;48;5;101m▄\e[38;5;247;48;5;246m▄\e[38;5;246;48;5;246m▄\e[38;5;101;48;5;101m▄\e[38;5;59;48;5;241m▄▄\e[38;5;240;48;5;101m▄\e[38;5;239;48;5;95m▄▄▄\e[38;5;237;48;5;238m▄▄\e[38;5;237;48;5;237m▄\e[38;5;237;48;5;236m▄▄\e[38;5;237;48;5;237m▄\e[38;5;238;48;5;238m▄\e[38;5;239;48;5;239m▄\e[38;5;242;48;5;101m▄\e[38;5;144;48;5;246m▄\e[38;5;223;48;5;187m▄▄\e[38;5;223;48;5;223m▄▄▄▄▄▄\e[38;5;223;48;5;187m▄\e[38;5;187;48;5;187m▄\e[38;5;144;48;5;223m▄\e[38;5;95;48;5;101m▄\e[38;5;59;48;5;239m▄\e[38;5;235;48;5;237m▄\e[38;5;235;48;5;235m▄\e[38;5;236;48;5;234m▄▄\e[38;5;236;48;5;233m▄\e[38;5;236;48;5;235m▄\e[38;5;234;48;5;234m▄\e[38;5;239;48;5;235m▄\e[38;5;240;48;5;239m▄\e[38;5;239;48;5;240m▄\e[38;5;240;48;5;240m▄\e[38;5;242;48;5;241m▄\e[38;5;101;48;5;101m▄\e[38;5;144;48;5;180m▄\e[38;5;144;48;5;144m▄\e[38;5;144;48;5;180m▄\e[38;5;180;48;5;187m▄▄\e[38;5;181;48;5;187m▄▄\e[38;5;187;48;5;223m▄\e[38;5;223;48;5;223m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;223m \e[38;5;223;48;5;223m▄▄▄▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;241;48;5;239m▄\e[38;5;242;48;5;101m▄\e[38;5;242;48;5;246m▄▄\e[38;5;242;48;5;101m▄\e[38;5;59;48;5;240m▄\e[38;5;241;48;5;239m▄\e[38;5;241;48;5;240m▄\e[38;5;138;48;5;95m▄\e[38;5;239;48;5;238m▄\e[38;5;238;48;5;239m▄\e[38;5;239;48;5;95m▄\e[38;5;237;48;5;237m▄\e[38;5;238;48;5;238m▄\e[38;5;237;48;5;237m▄\e[38;5;238;48;5;238m▄\e[38;5;237;48;5;238m▄\e[38;5;238;48;5;238m▄\e[38;5;240;48;5;239m▄\e[38;5;144;48;5;242m▄\e[38;5;187;48;5;144m▄\e[38;5;223;48;5;223m▄▄\e[38;5;187;48;5;223m▄▄\e[38;5;180;48;5;223m▄\e[38;5;144;48;5;187m▄\e[38;5;144;48;5;144m▄▄▄\e[38;5;95;48;5;180m▄\e[38;5;101;48;5;187m▄\e[38;5;239;48;5;144m▄\e[38;5;238;48;5;101m▄\e[38;5;235;48;5;241m▄\e[38;5;237;48;5;237m▄\e[38;5;236;48;5;235m▄\e[38;5;234;48;5;234m▄\e[38;5;235;48;5;234m▄\e[38;5;239;48;5;233m▄\e[38;5;240;48;5;240m▄▄\e[38;5;239;48;5;240m▄\e[38;5;239;48;5;239m▄\e[38;5;241;48;5;240m▄\e[38;5;242;48;5;59m▄\e[38;5;101;48;5;101m▄\e[38;5;101;48;5;144m▄\e[38;5;246;48;5;144m▄\e[38;5;101;48;5;144m▄\e[38;5;144;48;5;144m▄\e[38;5;187;48;5;95m▄\e[38;5;144;48;5;144m▄\e[38;5;137;48;5;187m▄\e[38;5;144;48;5;187m▄\e[38;5;180;48;5;241m▄\e[38;5;187;48;5;223m▄▄▄\e[38;5;223;48;5;223m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[38;5;187;48;5;223m▄\e[m" << endl;
    cout << "\e[38;5;240;48;5;59m▄\e[38;5;59;48;5;241m▄\e[38;5;240;48;5;241m▄\e[38;5;59;48;5;241m▄\e[38;5;240;48;5;59m▄\e[38;5;59;48;5;241m▄\e[38;5;240;48;5;241m▄\e[38;5;243;48;5;101m▄\e[38;5;242;48;5;137m▄\e[38;5;241;48;5;59m▄\e[38;5;238;48;5;237m▄\e[38;5;237;48;5;237m▄▄▄▄\e[38;5;237;48;5;238m▄\e[38;5;237;48;5;237m▄\e[38;5;237;48;5;239m▄\e[38;5;239;48;5;241m▄\e[38;5;101;48;5;144m▄\e[38;5;101;48;5;180m▄\e[38;5;59;48;5;144m▄\e[38;5;101;48;5;180m▄\e[38;5;239;48;5;137m▄\e[38;5;95;48;5;137m▄\e[38;5;239;48;5;144m▄First Time? - Hang Man 0.1\e[38;5;101;48;5;246m▄\e[38;5;101;48;5;144m▄\e[38;5;144;48;5;144m▄\e[38;5;101;48;5;180m▄\e[38;5;187;48;5;187m▄▄▄▄\e[38;5;223;48;5;223m▄▄▄▄\e[38;5;187;48;5;223m▄▄▄▄▄▄▄▄▄▄\e[38;5;187;48;5;187m▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;240;48;5;240m▄▄\e[38;5;239;48;5;239m▄▄▄\e[38;5;240;48;5;239m▄\e[38;5;59;48;5;240m▄\e[38;5;101;48;5;101m▄\e[38;5;246;48;5;101m▄\e[38;5;101;48;5;241m▄\e[38;5;59;48;5;239m▄\e[38;5;238;48;5;237m▄▄\e[38;5;236;48;5;237m▄▄\e[38;5;236;48;5;236m▄▄\e[38;5;238;48;5;236m▄\e[38;5;239;48;5;237m▄\e[38;5;235;48;5;237m▄\e[38;5;236;48;5;236m▄\e[38;5;235;48;5;236m▄▄\e[38;5;236;48;5;238m▄\e[38;5;237;48;5;237m▄\e[38;5;236;48;5;238m▄\e[38;5;235;48;5;237m▄\e[38;5;237;48;5;237m▄\e[38;5;236;48;5;236m▄\e[38;5;101;48;5;241m▄\e[38;5;144;48;5;137m▄\e[38;5;144;48;5;239m▄\e[38;5;95;48;5;59m▄\e[38;5;237;48;5;238m▄\e[38;5;239;48;5;238m▄\e[38;5;238;48;5;239m▄\e[38;5;238;48;5;237m▄▄\e[38;5;238;48;5;238m▄\e[38;5;240;48;5;239m▄\e[38;5;239;48;5;239m▄▄\e[38;5;239;48;5;240m▄\e[38;5;239;48;5;237m▄\e[38;5;239;48;5;240m▄\e[38;5;238;48;5;240m▄\e[38;5;238;48;5;239m▄\e[38;5;240;48;5;236m▄\e[38;5;59;48;5;241m▄\e[38;5;241;48;5;242m▄\e[38;5;241;48;5;243m▄\e[38;5;59;48;5;243m▄\e[38;5;241;48;5;243m▄\e[38;5;242;48;5;101m▄\e[38;5;101;48;5;247m▄\e[38;5;144;48;5;144m▄\e[38;5;101;48;5;180m▄\e[38;5;144;48;5;187m▄\e[38;5;180;48;5;187m▄\e[38;5;187;48;5;187m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[m" << endl;
    cout << "\e[38;5;246;48;5;238m▄\e[38;5;144;48;5;238m▄\e[38;5;246;48;5;238m▄\e[38;5;144;48;5;238m▄▄▄▄▄\e[38;5;144;48;5;59m▄\e[38;5;144;48;5;241m▄\e[38;5;144;48;5;242m▄\e[38;5;95;48;5;238m▄\e[38;5;236;48;5;236m▄\e[38;5;237;48;5;236m▄▄\e[38;5;236;48;5;237m▄\e[38;5;240;48;5;237m▄\e[38;5;243;48;5;240m▄\e[38;5;101;48;5;101m▄\e[38;5;101;48;5;240m▄\e[38;5;101;48;5;236m▄\e[38;5;239;48;5;234m▄\e[38;5;239;48;5;236m▄\e[38;5;238;48;5;236m▄\e[38;5;238;48;5;235m▄\e[38;5;238;48;5;236m▄\e[38;5;239;48;5;236m▄\e[38;5;239;48;5;237m▄\e[38;5;144;48;5;239m▄\e[38;5;137;48;5;144m▄\e[38;5;95;48;5;137m▄\e[38;5;240;48;5;241m▄\e[38;5;237;48;5;238m▄\e[38;5;236;48;5;236m▄\e[38;5;239;48;5;239m▄\e[38;5;239;48;5;238m▄\e[38;5;239;48;5;239m▄\e[38;5;238;48;5;238m▄\e[38;5;238;48;5;237m▄\e[38;5;238;48;5;238m▄\e[38;5;237;48;5;239m▄\e[38;5;239;48;5;240m▄\e[38;5;238;48;5;238m▄\e[38;5;239;48;5;239m▄\e[38;5;238;48;5;238m▄▄\e[38;5;239;48;5;237m▄\e[38;5;239;48;5;239m▄\e[38;5;240;48;5;240m▄\e[38;5;240;48;5;59m▄\e[38;5;240;48;5;240m▄\e[38;5;240;48;5;239m▄\e[38;5;239;48;5;240m▄\e[38;5;240;48;5;59m▄\e[38;5;241;48;5;242m▄\e[38;5;242;48;5;101m▄▄▄\e[38;5;144;48;5;144m▄\e[38;5;181;48;5;144m▄\e[38;5;181;48;5;187m▄\e[38;5;187;48;5;187m▄\e[38;5;180;48;5;180m▄\e[38;5;144;48;5;144m▄\e[38;5;101;48;5;144m▄▄▄▄▄▄\e[38;5;101;48;5;250m▄\e[38;5;101;48;5;187m▄▄▄▄▄\e[38;5;245;48;5;187m▄\e[38;5;101;48;5;187m▄▄\e[38;5;101;48;5;251m▄\e[m" << endl;
    cout << "\e[38;5;180;48;5;144m▄▄▄\e[38;5;144;48;5;144m▄\e[38;5;180;48;5;144m▄▄\e[38;5;180;48;5;180m▄▄▄▄\e[38;5;180;48;5;144m▄\e[38;5;245;48;5;144m▄\e[38;5;237;48;5;237m▄\e[38;5;239;48;5;238m▄\e[38;5;238;48;5;237m▄\e[38;5;235;48;5;236m▄\e[38;5;238;48;5;239m▄\e[38;5;239;48;5;241m▄\e[38;5;241;48;5;101m▄\e[38;5;242;48;5;101m▄\e[38;5;101;48;5;101m▄\e[38;5;243;48;5;240m▄\e[38;5;239;48;5;240m▄\e[38;5;59;48;5;240m▄\e[38;5;237;48;5;238m▄\e[38;5;238;48;5;239m▄▄\e[38;5;242;48;5;240m▄\e[38;5;180;48;5;144m▄\e[38;5;187;48;5;180m▄\e[38;5;187;48;5;144m▄\e[38;5;240;48;5;240m▄\e[38;5;236;48;5;237m▄\e[38;5;239;48;5;241m▄\e[38;5;242;48;5;239m▄▄\e[38;5;240;48;5;239m▄▄\e[38;5;59;48;5;239m▄\e[38;5;238;48;5;238m▄\e[38;5;240;48;5;238m▄\e[38;5;245;48;5;239m▄\e[38;5;240;48;5;239m▄\e[38;5;238;48;5;238m▄\e[38;5;238;48;5;237m▄\e[38;5;236;48;5;237m▄\e[38;5;238;48;5;238m▄\e[38;5;239;48;5;239m▄\e[38;5;239;48;5;240m▄\e[38;5;240;48;5;240m▄\e[38;5;239;48;5;240m▄\e[38;5;239;48;5;239m▄▄\e[38;5;239;48;5;240m▄\e[38;5;240;48;5;240m▄\e[38;5;240;48;5;59m▄\e[38;5;241;48;5;241m▄\e[38;5;101;48;5;241m▄\e[38;5;101;48;5;59m▄\e[38;5;242;48;5;101m▄\e[38;5;243;48;5;101m▄▄\e[38;5;101;48;5;138m▄\e[38;5;101;48;5;144m▄\e[38;5;101;48;5;101m▄\e[38;5;242;48;5;243m▄\e[38;5;239;48;5;243m▄\e[38;5;239;48;5;241m▄\e[38;5;59;48;5;242m▄\e[38;5;239;48;5;241m▄\e[38;5;240;48;5;243m▄\e[38;5;239;48;5;101m▄▄\e[38;5;239;48;5;242m▄\e[38;5;240;48;5;242m▄\e[38;5;239;48;5;241m▄\e[38;5;59;48;5;241m▄\e[38;5;239;48;5;241m▄\e[38;5;240;48;5;242m▄\e[38;5;240;48;5;243m▄\e[m" << endl;
    cout << "\e[38;5;144;48;5;144m▄\e[38;5;144;48;5;180m▄\e[38;5;180;48;5;180m▄▄\e[38;5;180;48;5;7m▄\e[38;5;7;48;5;180m▄▄▄\e[38;5;144;48;5;180m▄\e[38;5;101;48;5;180m▄\e[38;5;242;48;5;180m▄\e[38;5;95;48;5;95m▄\e[38;5;59;48;5;240m▄\e[38;5;239;48;5;239m▄▄\e[38;5;238;48;5;238m▄\e[38;5;237;48;5;237m▄\e[38;5;239;48;5;239m▄\e[38;5;241;48;5;241m▄\e[38;5;241;48;5;59m▄\e[38;5;238;48;5;242m▄\e[38;5;236;48;5;239m▄\e[38;5;240;48;5;238m▄\e[38;5;240;48;5;241m▄\e[38;5;242;48;5;59m▄\e[38;5;236;48;5;238m▄▄\e[38;5;144;48;5;144m▄\e[38;5;180;48;5;180m▄\e[38;5;180;48;5;187m▄\e[38;5;101;48;5;187m▄\e[38;5;236;48;5;239m▄\e[38;5;59;48;5;95m▄\e[38;5;101;48;5;95m▄\e[38;5;101;48;5;144m▄\e[38;5;240;48;5;101m▄\e[38;5;144;48;5;59m▄\e[38;5;101;48;5;246m▄\e[38;5;101;48;5;241m▄\e[38;5;144;48;5;239m▄\e[38;5;101;48;5;245m▄\e[38;5;239;48;5;242m▄\e[38;5;101;48;5;239m▄▄\e[38;5;238;48;5;238m▄\e[38;5;236;48;5;236m▄\e[38;5;236;48;5;237m▄\e[38;5;239;48;5;239m▄▄\e[38;5;240;48;5;240m▄\e[38;5;239;48;5;239m▄▄▄▄\e[48;5;239m \e[38;5;239;48;5;240m▄\e[38;5;239;48;5;59m▄\e[38;5;240;48;5;240m▄\e[38;5;241;48;5;242m▄\e[38;5;240;48;5;59m▄\e[38;5;241;48;5;242m▄\e[38;5;242;48;5;243m▄\e[38;5;101;48;5;101m▄▄\e[38;5;241;48;5;242m▄\e[38;5;101;48;5;144m▄\e[38;5;144;48;5;101m▄\e[38;5;242;48;5;239m▄\e[38;5;237;48;5;237m▄▄\e[38;5;237;48;5;238m▄\e[38;5;237;48;5;237m▄\e[38;5;236;48;5;236m▄\e[38;5;236;48;5;237m▄\e[38;5;236;48;5;238m▄\e[38;5;236;48;5;237m▄▄\e[38;5;235;48;5;237m▄\e[38;5;236;48;5;239m▄\e[38;5;236;48;5;240m▄\e[m" << endl;
}


void instructions()
{
    clearScreen();
    cout << "Dessa instruktioner & regler gäller för Hänga Gubbe" << endl << endl
    << "Spelet handlar om att gissa ett slumpmäsigt utvalt ord" << endl
    << "Ordet är dolt och anges med understräck som visar hur många bokstäver ordet innehåller" << endl
    << "Du har 10 gissningar innan gubben hängs, för varje felaktigt gissat bokstav förlorar du en gissning " << endl
    << "För varje bokstav du gissar rätt visas bokstaven i ordet" << endl
    << "Du kan gissa på hela ordet när som helst, men gissar du fel kommer omgången att avslutas." << endl
    << "Under din spelomgång kommer en slumpmässig bokstav att räknas som 2 gissningar. Du får inte veta vilken bokstav detta är." << endl << endl
    << "Lycka till!" << endl << endl;
}



void endGame(bool& gameIsRunning) {
    gameIsRunning = false;
}



void showMenu(vector<string>& words, vector<string>& letters) {
    int choice;
    bool gameIsRunning = true;
    clearScreen();
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
                gamePlay(words, letters);
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

void gamePlay(vector<string>& words, vector<string>& letters) {
  
    string randomWord = Randomizer(words);
    string randomLetter = Randomizer(letters);

    Game game(randomWord);

    cout << "Random word: " << randomWord << endl; // Debug
    cout << "Random letter: " << randomLetter << endl; // Debug
    int attempts = 0;
    while(!game.endOfAttempts()) {
        game.displayStatus();

        char guess;
        cout << "Gissa en bokstav: ";
        cin >> guess;

        if(!game.guess(guess)) {
            cout << "Fel gissning!" << endl;
        } else {
            cout << "Rätt gissning!" << endl;
        }
        attempts++;

        if(game.win()) {
            cout << "Grattis! Du vann! " << "Du gissade rätt ord: " << randomWord << endl;
            break;
        }
    }

    if(!game.win()) {
        cout << "Spelet är över! Ordet var: " << randomWord << endl;
    }
}

string Randomizer( vector<string> list) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, list.size() - 1);
    int index = dis(gen);
    return list.at(index);
}


int main ()
{
    //splashScreen();
    //sleepForSeconds(2);
    vector<string>words = loadWordsFromFile("words.txt");
    vector<string>letters= {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "å", "ä", "ö"};
    showMenu(words, letters);
    
    return 0;
}
