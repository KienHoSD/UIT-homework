/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
for
while
goto
[
]
static
###End banned keyword*/
#include <iostream>
using namespace std;
int candle(int candles, int makeNew){
    return candles+(candles-1)/(makeNew-1);
}
int main (){
    int candles, makeNew;
    cin >> candles >> makeNew;
	cout << candle(candles, makeNew);
}
