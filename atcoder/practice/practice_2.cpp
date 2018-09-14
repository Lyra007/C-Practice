#include <iostream>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  string s;
  for(int i=0; i < N; i++) s += (char)('A' + i);

  for(int j=0; j < N; j++) {
    for(int i=0; i < N-1; i++) {
      cout << "? "<<s[i] << " " <<s[i+1]<<endl;
      fflush(stdout);
      char ans;
      cin >> ans;
      if (ans == '>') swap(s[i], s[i+1]);
    }
  }
  cout << s;
  fflush(stdout);
  return 0;
}
