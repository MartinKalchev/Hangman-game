///Мартин Калчев F85994
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

class ArrayVector
{
public:
    ArrayVector()
    {
        n = 0;
    }
    void insert(const string &s)
    {
        words.push_back(s);
        n++;
    }
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


void isCorrect(char guess, const string& word, string& soFar, int& wrongInputs)
{
    if (word.find(guess) != string::npos)
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
    const int maxWrongGuesses = 8;

    string line;
    ArrayVector words;
    ifstream file;
    file.open("words.txt");

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

    while ((wrongGuesses < maxWrongGuesses) && (soFar != rnd))
    {
        cout << "\n\nYou have " << (maxWrongGuesses - wrongGuesses) << " incorrect guesses left.\n";
        cout << "\nThe following letter have been used:\n" << GuessedLetters << endl;
        cout << "\nThe word so far:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;


    while (GuessedLetters.find(guess) != string::npos)
    {
        cout << "\nYou've already guessed " << guess << endl;
        cout << "Enter your guess: ";
        cin >> guess;
    }
        GuessedLetters += guess;


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


