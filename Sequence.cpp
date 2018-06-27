#include <iostream>
#include <string>
#include <fstream>
#include "Sequence.h"
#include <cstring>
using namespace std;

Sequence::Sequence(string filename){
    len = 0;
    string temp;
    ifstream input;
    char a[100];
    strcpy(a,filename.c_str());
    input.open(a);
    if(!input.is_open()){
      cout << "Could not find the file\n";
      }
    while ( getline( input , temp) ) {
      dna += temp;}
    len = dna.length();
}

int Sequence::length(){
    return len;
}


int Sequence::numberOf(char base){
    int count = 0;
    for ( int i = 0 ; i < len; i++ ){
    if ( dna[i] == base ){ count++; }}
    return count;
}

string Sequence::longestConsecutive(){ 
    char a = dna[0];
    char tempa;
    int templen = 1;
    int longestlen = 0;
   
    for ( int i=1; i<len ; i++ ){
      if ( dna[i] == a ){
      templen++;}
      else{
        if(templen>longestlen){
          longestlen = templen;
          tempa = a;}

        a = dna[i];
        templen = 1;}}

    string result;
    for ( int j=1; j<=longestlen ; j++){
    result += tempa; }
    cout << longestlen << endl;
    return result;
}

string Sequence::longestRepeated(){


}
    
     
