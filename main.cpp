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

  int index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);
  //cout << "Index: " << index << '\n';

  switch (index) {
    case 1:
      cout << "Grade 1\n";
      break;
    case 2:
      cout << "Grade 2\n";
      break;
    case 3:
      cout << "Grade 3\n";
      break;
    case 4:
      cout << "Grade 4\n";
      break;
    case 5:
      cout << "Grade 5\n";
      break;
    case 6:
      cout << "Grade 6\n";
      break;
    case 7:
      cout << "Grade 7\n";
      break;
    case 8:
      cout << "Grade 8\n";
      break;
    case 9:
      cout << "Grade 9\n";
      break;
    case 10:
      cout << "Grade 10\n";
      break;
    case 11:
      cout << "Grade 11\n";
      break;
    case 12:
      cout << "Grade 12\n";
      break;
    case 13:
      cout << "Grade 13\n";
      break;
    case 14:
      cout << "Grade 14\n";
      break;
    case 15:
      cout << "Grade 15\n";
      break;
    case 16:
      cout << "Grade 16\n";
      break;
    default:
      if(index <= 1) {
        cout << "Before Grade 1\n";
      } else if(index >= 16) {
        cout << "Grade 16+\n";
      } else {
        return 1;
      }
  }

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
    if(input[i] == '.' || input[i] == '!' || input[i] == '?') {
      sentence_count++;
    }
  }
  return sentence_count;
}
