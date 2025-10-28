#include <cctype>
#include <iostream>
#include <limits.h>
#include <cctype>
#include <string>

using namespace std;

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

string g_input = "";

int main () {
  
  while(true) {
    cout << "Text: ";
    getline(cin, g_input);

    if(cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
      break;
    }
  }

  double letters = count_letters(g_input);
  double words = count_words(g_input);
  double sentences = count_sentences(g_input);

  //cout << "Letters: " << letters << " Words: " << words << " Sentences: " << sentences << '\n';

  double avg_letters = (letters / words) * 100;
  double avg_sentences = (sentences / words) * 100;

  double index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);

  //cout << "Avg Words: " << avg_letters << '\n';
  //cout << "Avg Sentences: " << avg_sentences << '\n';
  cout << "Index: " << index << '\n';

return 0;
}

int count_letters(string input) {

  int letter_count = 0;

  for (int i = 0; i < input.length(); i++) {
    if(isalpha(input[i])) {
      letter_count++;
    }
  }
  return letter_count;
}

int count_words(string input) {
  
  int word_count = 1;
  
  for(int i = 0; i < input.length(); i++) {
    if(input[i] == ' ') {
      word_count++;
    }
  }
  return word_count;
}

int count_sentences(string input) {
  
  int sentence_count = 0;

  for(int i = 0; i < input.length(); i++) {
    if(input[i] == '.' || input[i] == '!') {
      sentence_count++;
    }
  }
  return sentence_count;
}
