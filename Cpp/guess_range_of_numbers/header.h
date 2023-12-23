#ifndef header_H

#define header_H

#include <iostream>
using namespace std;

class Game
{

private:
    int arr[20]; // 1st member variable

    int n; // 2nd member variable

    int maxGuess; // 3rd member variable

    int minNumber; // 4th member variable

    int maxNumber; // 5th member variable

    int currentGuessCount, foundGuesses, guessArray[20] /*array where all guesses are stored*/
    , guessArrayFlag[20] /*array keeping whether guesses are correct or not in 1 or 0*/;

    void Guess();

    void WriteArray();

    void PushGuessArray(int guessCount);

    void PushGuessArrayFlag(int flag);

    void FillArrayWithRandomValues(int n);

    int GenerateRandomNumberInRange(int minNumber, int maxNumber);

public:
    Game(int n, int minNumber, int maxNumber);

    void PlayGame();
};

#endif
