#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

int main ()
{
    cout << "Välkommen till spelet Hänge gubbe!" << endl << endl;
    do {
        cout << "Välj ett alternativ" << endl;
        cout << "1. Spela" << endl;
        cout << "2. Highsciores" << endl;
        cout << "3. Instruktioner" << endl;
        cout << "4. Avsluta" << endl;
        
        cout << "Ditt val: ";
        int choice = 0;
        cin >> choice;
        

    } while (1);

    cout << "Tack för att du spelade!" << endl;
    return 0;
}