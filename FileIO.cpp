#include <iostream>
#include "FileIO.h"

FileIO::FileIO(std::string argv1) {
    //prints binary tree stored in tree.txt out to console.
    if (argv1 == "-l") {
        std::string line;
        std::ifstream inp(treeFile, std::ios::in);
        while (getline(inp, line)) { //iterates over tree.txt file
            std::cout << line << std::endl;
        }
        inp.close();
    }
}
FileIO::FileIO(std::string argv1, std::string argv2) {
    // if argv1 == -s, prints encoded value of given character (argv2) out to console.
    if(argv1 == "-s"){
        std::cout << findChar(argv2[0],dictionaryFile) << std::endl;
    }
    //if argv2 == -encode, encodes data given in argv1 file and prints encoded data out to console.
    else if (argv2 == "-encode") {
        std::map<char, int> freq;
        calcFrequencies(argv1, freq);
        BinaryTree *tree = new BinaryTree(freq);
        outDictionary(tree->printEncoded());
        std::string line;
        std::string dummyline;
        std::ifstream inp(argv1, std::ios::in);
        while (getline(inp,line)) {
            dummyline += line;
        }
        inp.close();
        while (!dummyline.empty()){
            std::cout << findChar(dummyline[0], dictionaryFile);
            dummyline = dummyline.substr(1);
        }
        std::cout << std::endl;
    }
    //if argv2 == -decode, decodes data given in argv1 file and prints decoded data out to console.
    else if (argv2 == "-decode"){
        dictionary(dictionaryFile); // fills dict variable with data included by dictionary file.
        decoder(argv1);  //decodes data given in argv1 file.
    }

}
void FileIO::calcFrequencies(std::string file, std::map<char,int> &frequency) {
    char c;
    std::ifstream inp(file, std::ios::in);
    while (!inp.eof()) { //iterates over file.
        bool dummy= true;
        inp.get(c);
        for (std::map<char,int>::iterator it = frequency.begin(); it != frequency.end(); ++it) {
            // if c  already exists in frequency map, increases its value by one.
            if (it->first == c) {
                dummy = false;
                it->second++;
                break;
            }
        }
        // if c does not exist in frequency map, adds and sets its value as 1.
        if(dummy) {
            frequency[c] = 1;
        }
        }
    inp.close();
}
void FileIO::dictionary(std::string file){
    //reads dictionary txt and constructs the dictionary map which includes each character and relative encoded data.
    std::string decoder;
    std::ifstream inp(file, std::ios::in);
    while(getline(inp,decoder)){  //reads each line of dictionary file.
        if(decoder[decoder.length()-1] == '\n'){
            decoder = decoder.substr(0,decoder.find('\n'));
        }
        if(decoder.find("\\n") == 0){
            dict['\n'] = decoder.substr(decoder.find('\t')+1);
            continue;
        }
        dict[decoder[0]] = decoder.substr(decoder.find('\t')+1);
    }
    inp.close();

}
void FileIO::decoder(std::string inp){
    std::string ss ="";
    std::string line;
    std::ifstream input(inp);
    while(getline(input,line)){ //reads inp file which will be decoded.
        ss.append(line);
    }
    input.close();
    line = "";
    while(!ss.empty()) {
        for (std::map<char, std::string>::iterator it = dict.begin(); it != dict.end(); ++it) {
            // iterates over dict map to find decoded value of data given in inp file.
            if (ss.find(it->second) == 0) {
                line += it->first;
                ss = ss.substr(it->second.length());
                break;
            }
        }
    }
    std::cout<<line<<std::endl;  //prints decoded data out to console.

}
void FileIO::outDictionary(std::string s){
    //prints dictionary out to dictionary.txt
    std::ofstream file;
    file.open(dictionaryFile);
    file.clear();
    file << s;
    file.close();

}
std::string FileIO::findChar(char c, std::string dictionary){
    std::string line;
    std::ifstream inp(dictionary, std::ios::in);
    while(getline(inp,line)){  // iterates over dictionary.txt to find encoded value of given c.
        if (line.find(c) == 0 || (line.find("\\n") == 0 && c == '\n')){
            inp.close();
            return line.substr(line.find("\t")+1);
        }
    }
    inp.close();
    return "";
}




