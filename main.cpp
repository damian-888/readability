#include <cctype>
#include <iostream>
#include <limits.h>
#include <cctype>

using namespace std;

int calc_letters(string words);
//calc_sentences();
//calc_level();

string input = "";

int main () {

  //up to 16, then Grade 16+, or Before Grade 1
  //cout Text:
  
  while(true) {
    cout << "Text: ";
    getline(cin, input);
    //cout << input << '\n';

    if(cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
      break;
    }
  }
  
  int average_letters = calc_letters(input);
  cout << "Main " << average_letters << '\n';

  return 0;
}

int calc_letters(string words) {
  char current;
  char previous;
  int letter_count = 0;
  int word_count = 0;

  for(int i = 0; i < words.length(); i++) {
    current = words[i];
    previous = words[i - 1];

    if(isalpha(words[i])) {
      letter_count++;
    }

    if(previous == ' ' || previous == '.') {
      word_count++;
    }
  }

  //To fix index starting at 0, i don't know a better way right now
  word_count += 1;

  //Printing Debug
  //cout << "Final letters: " << letter_count << " " << "Final words: " << word_count << '\n';
  //cout << average << '\n';

  int avg_letters = (letter_count * 100) / word_count;

  return avg_letters;
}
