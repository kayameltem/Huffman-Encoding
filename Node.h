#ifndef ASIGT4_NODE_H
#define ASIGT4_NODE_H
#include <iostream>
#include <map>
class Node {
    private:
        char data;
        int freq;
        Node* left;
        Node* right;
        Node( int freq ,char data,Node* left = NULL, Node* right = NULL){  //constructor method used to create nodes for each character
            this->freq = freq;
            this->data = data;
            this->left = left;
            this->right = right;
        }
        Node(Node* left, Node* right){  //constructor method used for consturct binary tree by using Huffman Encoding Algorithm
            this->left = left;
            this->right = right;
            if(left != NULL && right != NULL){
                freq = left->freq + right->freq;
            }
        }
    friend class BinaryTree;
};


#endif //ASIGT4_NODE_H
