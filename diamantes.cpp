#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
    
    int N = 0, repeticao;
    stack<char> P;
    
    cin >> repeticao;
    
    cin.ignore();
    
    while(repeticao){
    
    string S;
    
    getline(cin, S);
    
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '<') {
            P.push(S[i]);
        }else if (S[i] == '>') {
            P.pop();
            N++;
        }
    }
    
    while (!P.empty()) {
        P.pop();
    }
    
    cout << N << endl;
    N=0;
    repeticao--;
    }
    
}