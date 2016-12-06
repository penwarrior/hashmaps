//
//  main.cpp
//  dictionary_two_letter_hash_table
//
//  Created by Narine Hall on 11/23/15.
//  Copyright © 2015 Narine Hall. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


class Definition {
   
public:
   string key;
   string description;
   
};

int hash_code(string);
void insert_definition(string, string, Definition[]);
string check_definition(string);
string find_definition(string, Definition[]);
double find_words(string[], Definition[], bool);


const int LETTERS = 26;
char letter_a = 'a';
const int SIZE_FOR_TEST = 8, RUNS = 10;
clock_t start;
double diff, totalDiff;

int main() {
   
   char first_letter, second_letter;
   string word, description;
   string words_for_search[] = {"is", "an", "at", "ad", "ab", "ah", "am", "as"};
   
   Definition defTable[LETTERS * LETTERS];
   
   for (int i = 0; i < LETTERS; i++){
      for(int j = 0; j < LETTERS; j++){
         
         // create the two letter word
         
         // points: THINK ABOUT WHAT THIS CODE DOES
         word = "";
         first_letter = static_cast<char>(letter_a + i);
         second_letter = static_cast<char>(letter_a + j);
         word+=first_letter;
         word+=second_letter;
         description = check_definition(word);
         
         // insert it into the definition table
         insert_definition(word, description, defTable);
         
         if (description != " "){
            cout << "Inserting word " << word << " with description "<< description << endl;}
         else{
            cout << "Inserting word " << word << endl;
         }
         
      }
   }
   
   
   
   
   // find and print the definitions of the following words and time it
   
   cout << endl << " LET'S NOW FIND SOME WORDS" << endl << endl;
   
   bool print_result = true;
   diff = find_words(words_for_search, defTable, print_result);
   cout << endl << "Overall TIME IS " << diff << endl;
   
   
   
   // do the same thing 10 times and print the average time
   
   cout << endl << " LET'S NOW DO THE SAME THING 10 TIMES AND PRINT THE AVERAGE TIME" << endl << endl;
   
   print_result = false;
   for(int i = 0; i < RUNS; i++){
      diff = find_words(words_for_search, defTable, print_result);
      totalDiff += diff;
   }
   
   cout << "Average time for 10 runs is " << totalDiff/RUNS << endl;
   
   
   return 0;
}

double find_words(string words_for_search[], Definition defTable[], bool print_result){
   
   string found_definition;
   double diffs = 0.0;
   
   // start the clock
   start = clock();
   
   for (int k = 0; k < SIZE_FOR_TEST; k++){
      
      found_definition = find_definition(words_for_search[k], defTable);
      
      if(print_result){
         cout << "Found the word " << words_for_search[k] << " with definition " << found_definition << endl;
      }
      
   }
   
   // end the clock
   diffs = ( clock() - start ) / (double)CLOCKS_PER_SEC;
   
   return diffs;
   
}



string find_definition(string word, Definition defTable[]){
   
   string description;

   // points: write your find_definition function here that will take a word and find its definition
   
   return description;
}



void insert_definition(string word, string description, Definition defTable[]){
   
   // points: write your insert_definition function here that inserts a word definition into the table of definitions
   
};



int hash_code(string word){
   
   int index = 0;
   
   // points: write your hash_code function here
   
   return index;
   
};



string check_definition(string word){
   string description = " ";
   
   if (word == "is"){
      description = "Third person singular present of be.";
   }
   
   if (word == "an"){
      description = "The form of the indefinite article (see a) used before words beginning with a vowel sound.";
   }
   
   if (word == "as"){
      description = "Used in comparisons to refer to the extent or degree of something";
   }
   
   if (word == "ab"){
      description = "an abdominal muscle";
   }
   
   if (word == "ad"){
      description = "an advertisement";
   }
   
   if (word == "ah"){
      description = "an exclamation";
   }
   
   if (word == "am"){
      description = " the present tense of be";
   }
   
   if (word == "at"){
      description = " expressing location or time";
   }
   
   return description;
};

