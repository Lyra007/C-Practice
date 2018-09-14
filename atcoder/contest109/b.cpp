//AtCoder Beginner Contest 109
//B - Shiritori

#include <iostream>
#include <map>

using namespace std;

int main() {

  int N;
  map<string, bool> wordList;
  map<string, bool> ::iterator it;
  bool Flag = true;
  cin >> N;
  if (N>0) {
    string s;
    cin >> s;
    wordList[s] = true;
    char lastChar = s[s.length()-1];
    for (int i=1; i<N; i++) {
      string s;
      cin >> s;
      it = wordList.find(s);
      if(it != wordList.end()) {
        Flag = false;
      } else {
        wordList[s] = true;
        char beginChar = s[0];
        if (lastChar != beginChar) {
          Flag = false;
        } else {
          lastChar = s[s.length()-1];
        }
      }
    }
   if (Flag) {
     cout << "Yes" <<endl;
   } else {
     cout << "No" <<endl;
   }
  }

  return 0;
}
