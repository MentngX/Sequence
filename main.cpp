#include <iostream>
#include "Sequence.h"
using namespace std;


int main(){
    string a = "dna.txt";
    Sequence dna(a);

    cout << "Length:"<<dna.length() << endl;
    cout << "A:" << dna.numberOf('A') << endl;
    cout << "C:"  << dna.numberOf('C') << endl;
    cout << "G:"  << dna.numberOf('G') << endl;
    cout << "T:" << dna.numberOf('T') << endl;
    cout << dna.longestConsecutive() << endl;
    
    return 0;
}
