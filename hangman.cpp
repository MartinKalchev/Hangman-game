#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

/// Using a custom data structure to store the words from the .txt file
class ArrayVector
{
public:
    ArrayVector()
    {
        n = 0; /// size of the structure initially
    }

    /// function to insert the words in the vector words.
    void insert(const string &s)
    {
        words.push_back(s);
        n++;
    }

    /// function to erase words from the vector words.
    void erase()
    {
        words.pop_back();
    }

    int size()
    {
        return n;
    }

    bool empty()
    {
        return size() == 0;
    }

    /// function to randomly choose a word from all the words in the game
    string Rand()
    {
        srand(time(0));
        int i = rand();

        return words[i];
    }
private:
    vector<string> words;
    int n;
};


/// function that checks if the letter given by the user is in the word to guess.
/// if the guess is correct update the blank spaces in the word with the correct letter
/// if the guess is wrong update the wrongInputs variable
void isCorrect(char guess, const string& word, string& soFar, int& wrongInputs)
{
    if (word.find(guess) != string::npos)  /// checks if the letter is contained in the word to guess.
    {
        cout << "Correct! " << "'" << guess << "'" << " is in the word.\n";

        for (int i = 0; i < word.length(); ++i)
            if (word[i] == guess)
                soFar[i] = guess;
    }
    else
    {
        cout << "The word does not contain the letter " << guess << endl;
        ++wrongInputs;
    }
}


/// the function that draws the hangman in the game after a wrong guess by the player.
void draw(int& wrongInputs)
{
 if(wrongInputs==1)
 {
  cout<<"\n"<<"\n"
   <<"   +       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"  ============="<<"\n"<<"\n";
 }
 else if(wrongInputs==2)
 {
  cout<<"\n"<<"\n"
   <<"   +----+  "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"  ============="<<"\n"<<"\n";
 }
 else if(wrongInputs==3)
 {
 cout<<"\n"<<"\n"
   <<"   +----+  "<<"\n"
   <<"   |    |  "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"  ============="<<"\n"<<"\n";
 }
 else if(wrongInputs==4)
 {
  cout<<"\n"<<"\n"
   <<"   +----+  "<<"\n"
   <<"   |    |  "<<"\n"
   <<"   |    O  "<<"\n"
   <<"   |    |  "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"  ============="<<"\n"<<"\n";
 }
 else if(wrongInputs==5)
 {
  cout<<"\n"<<"\n"
   <<"   +----+  "<<"\n"
   <<"   |    |  "<<"\n"
   <<"   |    O  "<<"\n"
   <<"   |   /|  "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"  ============="<<"\n"<<"\n";
 }
 else if(wrongInputs==6)
 {
  cout<<"\n"<<"\n"
   <<"   +----+  "<<"\n"
   <<"   |    |  "<<"\n"
   <<"   |    O  "<<"\n"
   <<"   |   /|\ "<<"\n"
   <<"   |       "<<"\n"
   <<"   |       "<<"\n"
   <<"  ============="<<"\n"<<"\n";
 }
 else if(wrongInputs==7)
 {
  cout<<"\n"<<"\n"
   <<"   +----+  "<<"\n"
   <<"   |    |  "<<"\n"
   <<"   |    O  "<<"\n"
   <<"   |   /|\ "<<"\n"
   <<"   |     \ "<<"\n"
   <<"   |       "<<"\n"
   <<"  ============"<<"\n"<<"\n";
 }
 else if(wrongInputs==8)
 {

  cout<<"\n"<<"\n"
   <<"   +----+     "<<"\n"
   <<"   |    |     "<<"\n"
   <<"   |    O     "<<"\n"
   <<"   |   /|\\   "<<"\n"
   <<"   |   / \\   "<<"\n"
   <<"   |          "<<"\n"
   <<"  ============"<<"\n"<<"\n";
 }
 }

int main()
{
    const int maxWrongGuesses = 8;  /// max number of wrong guesses

    string line;
    ArrayVector words;  /// initialization of the data structure that will contain the words
    ifstream file;
    file.open("words.txt");   /// the file which contains the words for the game

    while(!(file.eof()))
    {
        getline(file,line);
        words.insert(line);
    }

    string rnd = words.Rand();

    int wrongGuesses = 0;
    string soFar(rnd.size(), '_');
    string GuessedLetters = "";
    char guess;

    cout << "WELCOME TO THE HANGMAN GAME!!! GOOD LUCK, YOU WILL NEED IT!\n";
    cout << "/_________________________________________________________\\";

    while ((wrongGuesses < maxWrongGuesses) && (soFar != rnd))  /// keep working until the word is not guessed or the maximum wrong inputs is reached
    {
        cout << "\n\nYou have " << (maxWrongGuesses - wrongGuesses) << " incorrect guesses left.\n";
        cout << "\nThe following letter have been used:\n" << GuessedLetters << endl;
        cout << "\nThe word so far:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;


    while (GuessedLetters.find(guess) != string::npos) /// checks if the letter is already typed by the player and if it is the user is asked to type another letter
    {
        cout << "\nYou've already guessed " << guess << endl;
        cout << "Enter your guess: ";
        cin >> guess;
    }
        GuessedLetters += guess;  /// the letters which are correctly guessed are updated


        isCorrect(guess, rnd, soFar, wrongGuesses);
        draw(wrongGuesses);
    }

    if (wrongGuesses == maxWrongGuesses)
        cout << "\nYou've been hanged, better try next time!" << endl;
    else
        cout << "\nYou guessed it!" << endl;

    cout << "\nThe word was " << rnd << endl;

    return 0;
}


