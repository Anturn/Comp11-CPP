#include <iostream>
#include "keylist.h"
#include "cipher.h"

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
        KeyList key(filename);
        KeyWithResult key_in_struct = key.next();
        string ciphertext = read_input("decrypt");
        while (key_in_struct.word_percentage != -1) {
                Cipher cipher("decrypt",key_in_struct.key, ciphertext);
                cout << "'" << cipher.get_plaintext();
                cout << "' " << "decryped with key '";
                cout << key_in_struct.key << "'" << endl << endl;
                key_in_struct = key.next();
        }
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
