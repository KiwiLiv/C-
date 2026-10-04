#include <iostream> 
//För input och output

#include <ctime>
#include <cstdlib>
//För random nummer
using namespace std;
//Gör så jag slipper skriva std:: framför varje I/O-ström

int main() {

    srand(time(0));
//Gör så att random numret blir olika varje gång man startar spelet

    char answer;
//Här skapar jag en char variabel för spelarens svar på y eller n
int totalScore = 10;
    //Sätter startpoängen till 10

do {
    cout << "Have you played this game before? y for yes, n for no (y/n): ";
    cin >> answer;
    cin.ignore(1000, '\n');
    // Rensar resten av input-raden efter spelarens svar. Detta är så att den inte ska breaka om spelaren svarar med mer än ett tecken.

    if (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N') {
        cout << "Invalid answer. Please enter y or n.\n";
    }
} while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');
//Denna do-while säger att om variabeln answer inte är y, Y, n eller N så skriver den ut Invalid answer. och loopar tills spelaren skriver korrekt.

    if (answer == 'y' || answer == 'Y') {
        cout << "\n"
            "Welcome back\n"
             "Remember that you can allways cancell a current game by pressing ctrl + c or close terminal with alt + f4.\n";
    } //Om svaret är y eller Y så skriver den ut "Welcome back".

    else if (answer == 'n' || answer == 'N') {
//Om svaret är n eller N så skriver den ut instruktionerna:
        cout << "\n"
             "The computer will choose a number between 1-100 and you will have to guess it.\n"
             "After each guess, the computer will tell you if you need to guess higher or lower.\n"
             "You can choose how many guesses you want to have, and the fewer guesses you choose, the more points you will receive if you win.\n"
             "3 guesses = 10 points\n"
             "4 guesses = 5 points\n"
             "5 guesses = 3 points.\n"
             "You will start with 10 points. If you don't guess the correct number within your allowed guesses, you will lose 5 points.\n"
             "You can allways cancell a current game by pressing ctrl + c or close terminal with alt + f4.\n";

    }

    int numberOfGuesses;
    //Variabel för antalet gissningar speelaren valt

    char playAgain;
    //Variabel som frågar om spelaren vill spela igen. Anvåänds i slutet av loopen.

    do { //Här börjar loopen som kommer att fortsätta tills spelaren förlorat eller avslutat.
    while (true) {
    cout << "\n"
       "How many guesses would you like? 3, 4 or 5: \n";
    cin >> numberOfGuesses;
    //Spelarens input fyller variabeln numberOfGuesses.

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Please enter a number: 3, 4 or 5.\n";
        continue;
        //Precis som ovan skriver jag while och loopen breakar när spelaren skriver 3, 4 eller 5. Se break nedan:
    }

    if (numberOfGuesses == 3) {
        cout << "\n"
                "You will receive 10 points if you win.\n";
        break;
    }
    else if (numberOfGuesses == 4) {
        cout << "\n"
                "You will receive 5 points if you win.\n";
        break;
    }
    else if (numberOfGuesses == 5) {
        cout << "\n"
                "You will receive 3 points if you win.\n";
        break;
    }
    else {
        cout << "Choose only 3, 4 or 5.\n";
    }
} 
// Denna sekvens berättar för spelaren hur många poäng de får vid vinst. Eller ber dem skriva på nytt om input är fel.

    int points;
    //Här är variabeln för poängen spelaren får under en runda. Denna kommer att adderas till totalScore om spelaren vinner.

    if (numberOfGuesses == 3) {
        points = 10;
    }
    else if (numberOfGuesses == 4) {
        points = 5;
    }
    else {
        points = 3;
    }
    //Denna sekvens förklarar för spelet hur många poäng spelaren kommer få.

int secretNumber = rand() % 100 + 1;
//Randoomiserar ett nummer. 

int guessesLeft = numberOfGuesses;
// Håller reda på hur många gissningar spelaren har kvar och minskar med 1 vid fel gissning.

cout << "\n"
        "The computer has chosen a number between 1-100. You have "
          << guessesLeft << " guesses.\n"
          << "You currently have " << totalScore << " points.\n";

bool won = false;
//Används för att kontrollera om spelaren har vunnit.
//Börjar som false eftersom spelaren inte vunnit än.

while (guessesLeft > 0) {
    //Här skapas en stor while loop som kommer att fortsätta tills guessesLeft är 0.
    int guess;
    //Variabel för spelarens gissning

    cout << "\n"
            "Enter your guess: ";
    cin >> guess;
    //Spelarens input blir variabeln guess.

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Please enter a number.\n";
        continue;
        //Denna precis som ovan förhindrar spelaren från att skriva in något annat än ett nummer.
    }

    if (guess == secretNumber) {
        totalScore += points; 
        //Denna räknar ihop tidigare poäng med de poäng spelaren får vid vinst.
        cout << "\n"
                "Congratulations! You guessed the correct number!\n"
                  << "You have received " << points << " points!\n"
                  << "Your total score is " << totalScore << " points.\n";
        won = true;
        break; //Här breakar loopen om spelaren gissar rätt.
    }

    else if (guess < secretNumber) {
        cout << "\n"
                "Guess higher!\n";
        //Om gissningen är lägre än det hemliga numret så skriver den ut "Guess higher!"
    }

    else {
        cout << "\n"
                "Guess lower!\n";
        //Om gissningen är högre än det hemliga numret så skriver den ut "Guess lower!"
    }

    guessesLeft--;
    cout << "\n"
            "You have " << guessesLeft << " guesses left.\n";
    //Precis innan loopen börjar om minskar den guessesLeft med 1.
}

//Här har while loopen avslutats eftersom spelaren gissat rätt eller guessesLeft är 0.
if (!won) {
    totalScore -= 5;
    //Om spelaren inte vunnit så dras 5 poäng från totalScore.

    if (totalScore <= 0) {
        totalScore = 0;
        cout << "\n"
             << "No guesses left. The number was " << secretNumber << ".\n"
             << "You have 0 points left. Game over.\n";
        break;
    }
    //Om totalScore är 0 eller mindre så skriver den ut detta och breakar hela loopen.
}

if ((!won) && (totalScore > 0)) {
    cout << "\n"
         << "No guesses left. The number was " << secretNumber << ".\n"
         << "You have lost 5 points. Your total score is now " << totalScore << " points.\n";
    //Om spelaren inte vunnit, men har kvar poäng så skriver den ut detta.
}

do {
    cout << "\n"
            "Do you want to play again? y/n: ";
    cin >> playAgain;                
    cin.ignore(1000, '\n');
    //Samma som ovan, rensar input-raden efter spelarens svar och loopar tills spelaren skriver korrekt input.

    if (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
        cout << "Invalid answer. Please enter y or n.\n";
    }
} while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N');

} while (playAgain == 'y' || playAgain == 'Y');
//Denna while hänger ihop med do på rad 58
   
    cout << "\n"
              << "Thank you for playing!\n"
              << "Your final score is " << totalScore << " points.\n";
              //Denna skrivs endast ut när loopen är slut.
    return 0;
}