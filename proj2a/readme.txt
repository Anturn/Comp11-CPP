Name : Rui Qin Date : 4 / 15 /
       2016 Class
       : comp11 Project
         : project2

               Overall Purpose
           : This programm allows the user to give some plaintext and then
                 encrypt it by using some specific key word.Or oppositely,
    decrypt some ciphertexts, which are really messy and disordered words,
    into some plain and readable sentences.

        General Guideline
        : You can have three ways to do with the programm give out a
              ciphertext and a key to decrypt it to the plaintext or
        give a plaintext and finally encrypt it into a ciphertext.Or,
    you have a ciphertext and want to know the right meaning of it but you
        cannot find the right key.Then you try
        out all the keys and at last get some sentences,
            one of which is the most English version,
            and that is the one you try to find.


		   to encrypt: " ./phase0 --encrypt key " you give a key and the 
			         programm will run and ask for a plaintext and 
				 then uses the key you give to encrypt the text into 
				 a ciphertext, a unreadable version.
		   to decrypt: " ./phase0 --decrypt key " you give a key and the 
			         programm will run and ask for a ciphertext and 
				 then uses the key you give to decrypt the text into 
				 a plaintext, a readable version.
		
		   to decrypt using a lot of keys:
			       " ./phase0 --keyfile filename" the programm asks for 
				 a ciphertest and uses tons of different keys to brutely
				 decrypt your message to some texts, one of which is the 
				 right answer with readable meaning.


A Readme.txt file spells out for the user a number of things:


The design, including a list of all of your classes and their purpose. E.g., 

Dictionary Class
        This class is a dynamic array that reads in a dictionary
        from a file, and has the following public functions:
                Dictionary()  : the default constructor
                ~Dictionary() : the default destructor
                bool has_word(std::string word) : returns true
                         if the word is in the dictionary.

        The class has the following private methods:
                void expand() : to expand the dynamic array
                void read_dict_from_file(std::string filename) : this
                        reads in the words from a dictionary into the
                        dynamic array

        The class has the following private variables:
                std::string wordlist : this holds the dynamic
                                       array pointer
                int num_elements : the number of elements in the array
                int capacity     : the number of elements the array can hold



KeyList Class
	This class is a linked list, which also maintain a struct in it. 
	The linked list contains two things, one is a struct and the other
	is a pointer points to the next node. 
	KeyList()  : the default constructor
	KeyList(std::string keyFile)  : the default constructor reading the
					input file
	~KeyList()  : the default destructor

	The class has the following private methods:
		read_file(std::string keyFile) : to read file containing all 
						 keys from outside
		insert(std::string k) : to insert the new keys to the linked list
		KeyWithResult next() :  to return the next KeyWithResult data in 
					the list
		reset_iterator() :      reset the iterator to the head
					of the list to go through the list again

		update_result(std::string k,
                                   float percentage,
                                   std::string p_text) : search through the list and
						         update k's tage and
							 plaintext

		The class has the following private variables:
			Node *head : the head of the list
			Node *iterator :  the iterator for the list, which points
					  to the next Node to retrieve during
					  iteration, and will point to the head
					  after an insert() or after reset_iterator()


KeyList Class
	A class for enciphering and deciphering a transposition cipher
		Cipher(std::string encrypt_or_decrypt,
                                std::string inputtext,
                                std::string key):  to set up the class
                ~Cipher(); // destructor : to destroy the class
                std::string get_plaintext() : Returns the plaintext 
                std::string get_ciphertext() : Returns the ciphertext
                std::string get_key() : accessor for key

	The class has the following private methods:

                void set_key(std::string k,int klen) : to set the key and key length
                void set_encipher(bool will_encipher) : to set whether we are enciphering or 
							deciphering
                int *get_column_order() : accessor for the column_order array
                int get_key_len() : accessor for key
                void transform() : call the encrypt or decrypt depending on our mission
                void order_columns() : order the columns based on the key
				       This is done alphabetically, so a key of
				       "hello" would put 1,0,2,3,4 into the column_order
				       array because e (column 1) is alphabetically 
				       first, h is second, etc.
                
                void parse_plaintext_to_cols() : takes the plaintext and puts it into 
						 columns based on the length of the key
                void parse_ciphertext_to_cols() : puts the ciphertext into columns 
						  based on the length of the key
                std::string pad(std::string s,int len) : to return an underscore 
							 padded string that has a
         						 length divisible by len
                std::string strip_and_underscore(std::string s) : clean up plaintext to be alpha-only,
          							  lowercase, and spaces turned into 
								  underscores
                std::string remove_underscores(std::string s) : replaces underscores with spaces

                void encrypt() : simply re-order the plaintext columns into ciphertext
                void decrypt() : return ciphertext to plaintext based on the key column ordering

	The class has the following private variables:
		std::string plaintext : plaintext, readable text
                std::string ciphertext : ciphertext, unreadable text
                std::string key : the key to decrypt or encrypt
		int key_len : the length of the key
                int *column_order : 
                bool will_encipher : decides wether to decipher or encipher

		


To compile (all on one line):
        clang++ -Wall -Wextra -g cipher.cpp keylist.cpp phase0.cpp -o phase0
