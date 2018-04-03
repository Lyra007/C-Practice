#include <iostream>
#include <vector>
using namespace std;

long long int absolute(long long int a) {
    if (a<0) return -a;
    return a;
}

long long int minNum(long long int a, long long int b) {
    if (a>b) return b;
    return a;
}
//change num long long into vector
vector<long long int> getVector(long long int num) {

    vector<long long int> split;
    while (num >= 10) {
        long long int ans = num % 10;
        split.push_back(ans);
        num/=10;
    }
    split.push_back(num);
    return split;
}

//get num using first
//length not change
long long int produceNum(long long int first, long long int length) {

    if (first == 10) first *= 2;
    long long int newNumber = 1;
    while (length > 1) {
        newNumber *= 10;
        length--;
    }
    return first*newNumber;
}

//get num using first
//length change
long long int produce(long long int start, long long int length) {
    long long int main =0;
    if(length>1) main = produceNum(start, length);
    long long int ans = 8;
    length -= 1;
    while (length > 1) {
        ans = ans * 10 + 8;
        length--;
    }
    main += ans;
    return main;
}

//get first character

long long int getMin(long long int num) {

    vector<long long int>res = getVector(num);
    long long int newNum = 0;
    long long int min=0;
    for (long long int i=res.size()-1; i >= 0; i--) {
        if(res[i]%2 == 0) {
            newNum += produceNum(res[i], i + 1);
            continue;
        }
        long long int length = i + 1;
        long long int numOne = newNum + produceNum(res[i]+1, length);
        long long int numTwo = newNum + produce(res[i]-1, length);
        min = minNum(absolute(numOne-num), absolute(numTwo-num));
        break;
    }
    return min;


}

int main() {

    freopen("A-large-practice.in", "r", stdin);
    freopen("output_file_name.out", "w", stdout);

    long long int t;
    cin >> t;
    for(long long int i=0; i<t; i++) {
        long long int ele;
        cin >> ele;
        long long int res = getMin(ele);
        cout << "Case #" << i+1 <<": " << res << endl;
    }
    fclose(stdout);


    return 0;
}


