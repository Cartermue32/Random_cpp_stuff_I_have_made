#include <iostream>
#include <random>
using namespace std;
int main() {
    while(true) {
        random_device rd;
        mt19937 gen(rd());
        cout << "Minimum number: ";
        int min, max;
        cin >> min;
        cout << endl;
        cout << "Maximum number: ";
        cin >> max;
        cout << endl;
        uniform_int_distribution<> distrib(min, max);
        int randomNumber = distrib(gen);
        cout << "Number of guesses: ";
        int guesses;
        cin >> guesses;
        cout << endl;
        while(true) {
            int num;
            cout << "Input guess: ";
            cin >> num;
            cout << endl;
            if(num > randomNumber) {
                cout << "Smaller" << endl;
            } else if(num < randomNumber) {
                cout << "Bigger" << endl;
            } else {
                cout << "You win :)" << endl;
                break;
            }
            if(guesses <= 0) {
                cout << "You lost :(" << endl;
                break;
            }
            guesses--;
            cout << "Guesses left: " << guesses << endl;
        }
        char ans;
        cout << "Do you want to play again? (y/n): ";
        cin >> ans;
        if(ans == 'Y' || ans == 'y') {
            ans = 'y';
        } else if(ans == 'N' || ans == 'n') {
            ans = 'n';
        } else {
            ans = 'n';
        }
        if(ans == 'n') {
            break;
        } else {
            break;
        }
    }
    return 0;
}