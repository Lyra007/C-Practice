//AtCoder Beginner Contest 109
//A - ABC333

#include <iostream>
using namespace std;

void checkIfStaties(int A, int B) {
  int multiple = A*B;
  for(int i=A; i<=B; i++) {
    int more = i*multiple;
    if (more % 2 != 0) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
  return;
}


int main() {
  int A, B;

  cin >> A >> B;
  if( A>=1 && A<=3 && B>=1 && B<=3) {
    if(A > B) {
      checkIfStaties(B, A);
    } else {
      checkIfStaties(A, B);
    }
  }
  return 0;
}
