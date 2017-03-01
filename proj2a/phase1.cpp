#include <iostream>
#include "keylist.h"
#include "cipher.h"
#include "dictionary.h"

const int SENTINEL = -1;
// to make:
// clang++ -Wall -Wextra keylist.cpp phase0.cpp cipher.cpp -o phase0
using namespace std;

struct Arguments {
        string operation;
        string key_or_filename;
};

/////////////////// Function Definitions ///////////////////
void print_usage(string program_name);
Arguments check_arguments(int argc, char *argv[]);
void encrypt(string key);
void decrypt(string key);
void brute_force(string filename);
string read_input(string operation);
int word_in_English(string text);
float word_percent(string text);
void print_Top(Node *head);
int totalword(string text);
void print_out(float percent, string key, string text);
/////////////////// Function Code  ///////////////////
int main(int argc, char *argv[]) {
        Arguments args = check_arguments(argc, argv);
        if (args.operation == "none") {
                return -1; // bad argument list
        } else if (args.operation == "encrypt") {
                encrypt(args.key_or_filename);
        } else if (args.operation == "decrypt") {
                decrypt(args.key_or_filename);
        } else if (args.operation == "keyfile") {
                brute_force(args.key_or_filename);
        }
        return 0;
}

// check_arguments()
// Purpose: To parse the command line arguments
// Arguments: the command line arguments :)
// Return value: an Arguments struct with the
//               operation information and either
//               the key or filename
//               The operation will be "none" if
//               the usage was incorrect
Arguments check_arguments(int argc, char *argv[]) {
        Arguments args;
        args.operation = "none"; // no operation yet

        string program_name = argv[0];

        if (argc < 3) {
                print_usage(program_name);
        } else {
                string poss_op = argv[1]; // the first argument
                if (poss_op == "--encrypt") {
                        args.operation = "encrypt";
                        args.key_or_filename = argv[2];
                } else if (poss_op == "--decrypt") {
                        args.operation = "decrypt";
                        args.key_or_filename = argv[2];
                } else if (poss_op == "--keyfile") {
                        args.operation = "keyfile";
                        args.key_or_filename = argv[2];
                }
        }
        return args;
}

// print_usage()
// Purpose: to print the usage for the program
// Arguments: none
// Return value: none
void print_usage(string program_name) {
        cout << "Usage:" << endl << endl;
        cout << program_name << " --encrypt key" << endl << endl;
        cout << program_name << " --decrypt key" << endl << endl;
        cout << program_name << " --keyfile filename" << endl;
        cout << endl;
}

// encrypt()
// Purpose: to use the Cipher class to encrypt a string
// Arguments: the key to use for the encryption
// Return value: none
void encrypt(string key) {
        string plaintext = read_input("encrypt");
        Cipher cipher("encrypt", key, plaintext);
        cout << endl << "Ciphertext:" << endl;
        cout << cipher.get_ciphertext() << endl;
}

// decrypt()
// Purpose: to use the Cipher class to decrypt a string
// Arguments: the key to use for the decryption
// Return value: none
void decrypt(string key) // track 11111111111
{
        // TODO: Students write code here
        string ciphertext = read_input("decrypt");
        Cipher cipher("decrypt", key, ciphertext);
        cout << endl << "Plaintext:" << endl;
        cout << cipher.get_plaintext() << endl;
}

// brute_force()
// Purpose: to use the Cipher class and a keyfile to decrypt a string
// Arguments: the filename for the keyfile
// Return value: none
void brute_force(string filename) {
        // TODO: Students write code here
        string plain;
        float percent;
        string k;

        string ciphertext = read_input("decrypt");
        KeyList key(filename);
        KeyWithResult key_in_struct = key.next();
	cout << endl<<"Checking: " ;
        while (key_in_struct.word_percentage != SENTINEL) {
                Cipher cipher("decrypt", key_in_struct.key, ciphertext);
                plain = cipher.get_plaintext();
                percent = word_percent(plain);
                k = key_in_struct.key;
                key.update_result(k, percent, plain);
                key_in_struct = key.next();
		cout << k <<", ";
        }
	cout << endl << endl;
        print_Top(key.get_head());
}

// read_input()
// Purpose: to read a line of input from the user
// Arguments: the operation to ask for (e.g., "encrypt" or "decrypt")
// Return value: the string that was returned
string read_input(string operation) {
        string text;
        cout << "Please enter text to " << operation << ":" << endl;
        getline(cin, text);
        return text;
}

// word_in_English()
// Purpose: to decide how many words are in English
// Arguments: a string,the decrypted text, the plaintext
// Return value: the int, the number of words in English
int word_in_English(string text) {
        Dictionary diction;
        string word = "";
        int text_length = text.length();
        int count = 0;
        for (int i = 0; i < text_length; i++) {
                if (isalpha(text[i])) {
                        word = word + text[i];
                        if ((i == text_length - 1) || (text[i + 1] == ' ')) {
                                if (diction.has_word(word)) {
                                        count++;
                                }
                                word = "";
                        }
                }
        }
        return count;
}

// totalword()
// Purpose: to decide how many words are in total
// Arguments: a string,the decrypted text, the plaintext
// Return value: the int, the total numbers of words
int totalword(string text) {
        int count = 0;
        int text_length = text.length();

        if (isalpha(text[0])) {
                count++;
        }

        for (int i = 1; i < text_length; i++) {
                if ((isalpha(text[i])) && (text[i - 1] == ' ')) {
                        count++;
                }
        }
        return count;
}

// word_percent()
// Purpose: return how many percents of words in English
// Arguments: a string,the decrypted text, the plaintext
// Return value: the float, the percent
float word_percent(string text) {
        float percent;
        int total = totalword(text);
        int total_in_English = word_in_English(text);

        percent = (float)total_in_English / (float)total;
        return percent * 100;
}

// print_Top()
// Purpose: to print out the top five
// Arguments: the linked list
// Return value: none
void print_Top(Node *head) {
        Node *current = head;
        string key;
        string text;
        cout << "Top 5 matches:" << endl;
        for (int i = 0; i < 5; i++) {
                float percent = current->kwr.word_percentage;
                string key = current->kwr.key;
                string text = current->kwr.plaintext;
                while (current != NULL) {
                        if (current->kwr.word_percentage > percent) {
                                percent = current->kwr.word_percentage;
                                key = current->kwr.key;
                        }
                        current = current->next;
                }
                current = head;

                while (current != NULL) {
                        if (key == current->kwr.key) {
                                text = current->kwr.plaintext;
                                current->kwr.word_percentage = 0;
                        }
                        current = current->next;
                }
                current = head;
                print_out(percent, key, text);
        }
}

// print_out()
// Purpose: to print out the information
// Arguments: float,percent;string key and the plaintext
// Return value: none
void print_out(float percent, string key, string text) {
        cout << "'" << text << "' decrypted with key '";
        cout << key << "': " << percent << "%" << endl;
}
