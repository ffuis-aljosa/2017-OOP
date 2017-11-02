#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };
enum Winner { PLAYER, COMPUTER, NOONE };

void printWelcomeMessage()
{
    cout << "Dobrodosli u igri Kamen Papir Makaze" << endl;
}

void printInputMessage()
{
    cout << "Izaberite jedanu od opcija" << endl;
}

void printOptions()
{
    cout << "(k - kamen, p - papir, m - makaze): ";
}

void printInputError()
{
    cout << "Molim izaberite jednu od ponudjenih opcija" << endl;
}

void printPlayerVictory()
{
    cout << "Pobijedili ste!" << endl;
}

void printComputerVictory()
{
    cout << "Izgubili ste!" << endl;
}

void printDraw()
{
    cout << "Nerjeseno!" << endl;
}

void printNextRoundMessage()
{
    cout << "Da li zelite jos jednu rundu?" << endl;
}

void printNextRoundOptions()
{
    cout << "(d - da, n - ne): ";
}

void printNextRoundError()
{
    cout << "Molimo izaberite validnu opciju" << endl;
}

void printResults(int draws, int wins, int losses)
{
    cout << "Pobjeda: " << wins << "\tIzgubljenih: " << losses
         << "\tNerjesenih: " << draws << endl;
}

bool isPlayerInputValid(char c)
{
    if (c == 'k' || c == 'p' || c == 'm')
        return true;

    return false;
}

void printEndRound(Winner winner)
{
    if (winner == PLAYER)
        printPlayerVictory();
    else if (winner == COMPUTER)
        printComputerVictory();
    else
        printDraw();
}

Choice getPlayerChoice()
{
    printInputMessage();

    char playerInput;

    while (true)
    {
        printOptions();

        cin >> playerInput;

        if (isPlayerInputValid(playerInput)) {
            switch (playerInput)
            {
            case 'k':
                return ROCK;
            case 'p':
                return PAPER;
            case 'm':
                return SCISSORS;
            default:
                exit(1);
            }
        }
        else
            printInputError();
    }
}

Choice getComputerChoice()
{
    int random = rand();

    int reminder = random % 3;

    if (reminder == 0)
        return ROCK;

    if (reminder == 1)
        return PAPER;

    return SCISSORS;
}

Winner declareWinner(Choice playerChoice, Choice computerChoice)
{
    if (playerChoice == computerChoice)
        return NOONE;

    if (playerChoice == ROCK)
    {
        if (computerChoice == PAPER)
            return COMPUTER;

        return PLAYER;
    }

    if (playerChoice == PAPER)
    {
        if (computerChoice == SCISSORS)
            return COMPUTER;

        return PLAYER;
    }

    if (playerChoice == SCISSORS)
    {
        if (computerChoice == ROCK)
            return COMPUTER;

        return PLAYER;
    }
}

bool wantsNextRound()
{
    printNextRoundMessage();

    while (true)
    {
        printNextRoundOptions();

        char endRoundChoice;

        cin >> endRoundChoice;

        if (endRoundChoice == 'd')
            return true;
        else if (endRoundChoice == 'n')
            return false;
        else
            printNextRoundError();
    }
}

int main()
{
    srand(time(NULL));

    printWelcomeMessage();

    int draws = 0;
    int wins = 0;
    int losses = 0;

    while (true)
    {
        Choice playerChoice = getPlayerChoice();
        Choice computerChoice = getComputerChoice();

        Winner winner = declareWinner(playerChoice, computerChoice);

        if (winner == PLAYER)
            wins++;
        else if (winner == COMPUTER)
            losses++;
        else
            draws++;

        printEndRound(winner);
        printResults(draws, wins, losses);

        if (!wantsNextRound())
            break;
    }

    return 0;
}
