#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Sequence.h"
#include <cstring>
#define MAXCHAR 1500000
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


int pstrcmp(const void *p1 , const void *p2 ){
    return strcmp ( *(char* const *)p1, *(char* const*)p2 );
}

int count ( char *a, char *b){
    int i = 0;
    while ( *a && (*a++ == *b++) )i++;
    return i;
}


string Sequence::longestRepeated(){
    char* a = new char[MAXCHAR];
    char* *b = new char*[MAXCHAR];
    strcpy(a,dna.c_str());
    for ( int i = 0; i < len ; i++){b[i] = &a[i];}
    int temp;
    int maxlen=0, maxi=0;
    qsort( b , len , sizeof(char*), pstrcmp);
    for ( int i = 0; i < len - 1; i++){
      temp = count ( b[i] , b[i+1] ) ;
      if(temp > maxlen ){
        maxlen = temp;
        maxi = i;}}
    string s = b[maxi];
    string result;
    for ( int i = 0 ; i< maxlen ; i++){
    result += s[i];
}
    delete []a;
    delete []b;
    return result;}
    
     
