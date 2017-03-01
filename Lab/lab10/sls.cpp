#include <iostream>
using namespace std;
#include "lab.h"
#include <cctype>
/*
 * sls - sentence length sorter
 *       purpose: sort the sentences in a document by number of words
 *	   input: reads text from cin, counts words in each sentence
 *	  output: the sentences in length order from 1 word to ... n-word
 *	    also: prints number of sentences for each length, and ASL
 *	    uses: the Lab class to hold a list of strings
 *       compile: clang++ -Wall -Wextra sls.cpp lab.cpp 
 */

const int MAX_NUM_WORDS = 100;

string get_sentence();
int count_words(string);

int main()
{
	Lab	buckets[MAX_NUM_WORDS+1];
	Lab	overflow;
	string	next_sentence;
	int	num_words;
	int	i;

	while( true )
	{
		next_sentence = get_sentence();
		if ( next_sentence == "" )
			break;
		num_words = count_words(next_sentence);
		if ( num_words <= MAX_NUM_WORDS )
			buckets[num_words].add(next_sentence);
		else
			overflow.add(next_sentence);
	}

	for( i = 1 ; i <= MAX_NUM_WORDS ; i++ ){
		if ( buckets[i].get_count() > 0 ){
			cout << "SENTENCES WITH " << i << " WORDS:" << endl;
			cout << "NUMBER: " << buckets[i].get_count() << endl;
			buckets[i].print();
		}
	}
	
	if ( overflow.get_count() > 0 ){
		cout << "SENTENCES OVER " << MAX_NUM_WORDS << endl;
		cout << "NUMBER: " << overflow.get_count() << endl;
		overflow.print();
	}
	cout << "Avg Sent Len: " << endl;
}

//
// get_sentence: read the next sentence from cin
//  args: none
//  rets: a string with each non-alpha-numeric replaced with ' '
//  note: returns "" when  no more data available
//  
string get_sentence()
{
	char c;
	string result = "";
	while(cin.get(c)){
		if(c != '.'&& c != '!' && c != '?'){
			if(!isalpha(c) && !isdigit(c)){
				result = result+' ';
			}else{
				result = result + c;
			}
		
		}else{
			break;
		}
		
	}
	cout << "'" << result << "'" << endl;
	return result;
	
	
}

//
// count_words: returns the number of words in a string
//  args: a string
//  rets: the number of words.  
//  
int count_words(string str)
{
	int count = 0;
	int str_length = str.length();
		if(isalpha(str[str_length])){
			count++;
		}
			for(int i=1;i<str_length;i++){
				if((isalpha(str[i]))&&(str[i+1]==' ')){
					count++;
				}
			}
	
	return count;		// return 0 for now.  Remove when
				// you write the real code.
}
