#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int up = a * c * e;
    int down = b * d * f;

    int A = up;
    int B = down;
    int C;

    while (B != 0){
        C = A % B;
        A = B;
        B = C;
    }

    printf("%d/%d", up/A, down/A);
}


/*#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <string>

//czy palindrom
using namespace std;
int main(){
    int testAmount; scanf("%d", &testAmount);
    int resultArray[testAmount];

    for(int i = 0; i < testAmount; i++){
        string original; cin >> original;

    }
    return 0;
}
*/
