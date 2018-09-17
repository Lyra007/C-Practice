//AtCoder Beginner Contest 109
//C - Skip

#include <iostream>
#include <cmath>
#include<algorithm>

using namespace std;

//a way to find greatest common divisor
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main() {
  int N, X;
  cin >> N >> X;

  int min_dis = 0;

  while (N) {
    long long xth_city;
    cin >> xth_city;
    long long dis = abs(xth_city-X);
    min_dis = gcd(min_dis, dis);
    N--;
  }
  cout << min_dis <<endl;

  return 0;
}
