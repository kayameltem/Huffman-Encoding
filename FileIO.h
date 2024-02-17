#ifndef ASIGT4_FILEIO_H
#define ASIGT4_FILEIO_H
#include "BinaryTree.h"
#include <string>
class FileIO{
    private:
     BinaryTree tree ;
     std::map<char,std::string> dict;
     std::string treeFile = "tree.txt";
     std::string dictionaryFile = "dictionary.txt";
public:
    FileIO(){} // default constructor
    FileIO(std::string argv1);  // constructor for printing the diagram of tree.
    FileIO(std::string argv1,std::string argv2);  // constructor for two argument inputs such as -s character, encoding and decoding given data.
    void dictionary(std::string file); //gets dictionary from dictionary.txt and fills "dict" variable with characters and their encoded data.
    void calcFrequencies(std::string file, std::map<char,int> &frequency); //calculates frequencies of each character included by given input file.
    void outDictionary(std::string s); //prints out dictionary to dictionary.txt.
    void decoder(std::string inp);  // decodes data given in inp file and prints decoded data out to console.
    std::string findChar(char c, std::string dictionary); // finds encoded data of c in dictionary file and returns its encoded data.
};

#endif //ASIGT4_FILEIO_H
