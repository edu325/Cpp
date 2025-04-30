#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    string entrada;
    string aviao;
    queue<string> cardeal[4];

    while (entrada != "0")
    {
        cin >> entrada;

        if (entrada[0] == '-')
        {
            if (entrada == "-1")
            {
                cin >> aviao;
                cardeal[0].push(aviao);
                cout << cardeal[0].back() << endl;
            }
            else if (entrada == "-2")
            {
                cardeal[1].push(aviao);
            }
            else if (entrada == "-3")
            {
                cardeal[2].push(aviao);
            }
            else if (entrada == "-4")
            {
                cardeal[3].push(aviao);
            }
        }
    }
}