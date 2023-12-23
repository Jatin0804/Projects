#include "header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

bool IsInArray(int guess, int *arr, int n)
{ // Function to check if the guessed number is in the array.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == guess)
        {
            return true;
        }
    }

    return false;
}

void Game::Guess()
{
    int guessCount;

    this->currentGuessCount += 1;

    cout << "Guess a digit: ";
    cin >> guessCount;

    if (IsInArray(guessCount, guessArray, currentGuessCount - 1))
    { // Check if the user has guessed the same number.
        cout << "You cannot guess the same number." << endl
             << endl;
        this->currentGuessCount -= 1;
        maxGuess -= 1;
        return;
    }

    this->PushGuessArray(guessCount);

    if (IsInArray(guessCount, this->arr, this->n))
    { // Check if the guessed number is in the randomly generated array.
        this->foundGuesses += 1;
        this->PushGuessArrayFlag(1);
    }
    else
    {
        this->PushGuessArrayFlag(0);
        cout << guessCount << " not found" << endl
             << endl;
    }
}

void Game::WriteArray()
{ // Function to print 'x's and correctly guessed numbers after each guess.
    for (int i = 0; i < n - foundGuesses; i++)
    {
        cout << "x"
             << " ";
    }

    for (int i = 0; i < currentGuessCount; i++)
    {
        if (guessArrayFlag[i])
        {
            cout << guessArray[i] << " ";
        }
    }

    cout << endl;
}

void Game::PushGuessArray(int guessCount)
{ // Function to push guesses to the array.
    this->guessArray[this->currentGuessCount - 1] = guessCount;
}

void Game::PushGuessArrayFlag(int flag)
{ // Function to push guess flags to the array.
    this->guessArrayFlag[this->currentGuessCount - 1] = flag;
}

void Game::FillArrayWithRandomValues(int n)
{ // Function to transfer random unique values to the array.
    for (int i = 0; i < n; i++)
    {
        int isUnique = 1;
        do
        {
            int randomNumber = GenerateRandomNumberInRange(this->minNumber, this->maxNumber);
            if (!IsInArray(randomNumber, arr, i))
            {
                isUnique = 1;
                arr[i] = randomNumber;
            }
            else
            {
                isUnique = 0;
            }
        } while (!isUnique);
    }
}

int Game::GenerateRandomNumberInRange(int minNumber, int maxNumber)
{ // Function to generate random numbers using rand.
    return minNumber + rand() % ((maxNumber + 1) - minNumber);
}

Game::Game(int n, int minNumber, int maxNumber)
{ // This is our constructor.
    this->n = n;
    this->minNumber = minNumber;
    this->maxNumber = maxNumber;
    currentGuessCount = 0;
    foundGuesses = 0;
}

void Game::PlayGame()
{ // Function called in the public, calling the private functions.
    FillArrayWithRandomValues(n);
    maxGuess = n * 2;

    while (currentGuessCount < maxGuess && n != foundGuesses)
    {
        this->Guess();
        this->WriteArray();
    }

    if (n == foundGuesses)
    {
        cout << "Congratulations. You won!" << endl;
    }
    else
    {
        cout << "Sorry. You lost:(" << endl;
    }
}
