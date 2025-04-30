#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {
    int N = 1;
    int aux;
    
    while(N != 0){
    queue<int> cartas;
        
    cin >> N;
    
    
    if (N <= 1);
    else if (N > 1) {
        for (int i = 1; i <= N; i++) {
            cartas.push(i);
        }
        
        cout << "Discarded cards: ";
            
        for (int i = 1; i < N; i++) {
            cout << cartas.front();
            if (i < N - 1) {
                cout << ", ";
            }
            cartas.pop();
            aux = cartas.front();
            cartas.pop();
            cartas.push(aux);
        }
        
        cout << endl << "Remaining card: " << cartas.back() << endl;
    }
    }
}
