#include "header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n, minNumber, maxNumber;

    srand(time(NULL));

    cout << "Enter the number of digits in the array: ";
    cin >> n;

    cout << "Enter the lower limit: ";
    cin >> minNumber;

    cout << "Enter the upper limit: ";
    cin >> maxNumber;

    Game game(n, minNumber, maxNumber);

    game.PlayGame();

    return 0;
}
