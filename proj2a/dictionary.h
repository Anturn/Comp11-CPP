#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>

const int CAPACITY = 10;

static std::string DICT_FILE = "words.txt";

class Dictionary {
      public:
        // constructor calls read_dict_from_file()
        // with the filename
        Dictionary();  // constructor
        ~Dictionary(); // desctructor

        // has_word()
        // Purpose: search for the word in the dictionary
        // Argument: a word to search for
        // Return value: true if word is in the dictionary
        bool has_word(std::string word);

      private:
        // the word list
        std::string *wordlist;

        // word list variables
        int num_elements;
        int capacity;

        // expand function for dynamic array
        void expand();

        // reads in the dictionary from a file
        void read_dict_from_file(std::string filename);
};
#endif
