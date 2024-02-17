#ifndef ASIGT4_BINARYTREE_H
#define ASIGT4_BINARYTREE_H
#include "Node.h"
#include <map>
#include <list>
#include <sstream>
#include <fstream>
class BinaryTree{

    private:
        Node* root;
        std::map<char,std::string> encoded;  //dictionary of characters with encoded data. Key: character Value: encoded datum
        std::string treeFile = "tree.txt";
        std::ofstream file;  // opens tree.txt
    public:
        BinaryTree(){}
        BinaryTree(std::map<char,int> chars);         //Constructor method. Creates binary tree according to data in given chars map
        void insert(std::list<Node*> nodes) ;         // inserts each node to binary tree according to Huffman Encoding Algorithm
        void encode(Node* node, std::string s);       // encodes charcaters with preorder traversal and fills the encoded map.
        std::string printEncoded();                   //returns a string of characters with encoded data.
        void listTree(Node* node,std::string blank,std::string code);   //constructs the diagram of the tree
        void display();  //prints diagram of the tree out to treeFile

};



#endif //ASIGT4_BINARYTREE_H
