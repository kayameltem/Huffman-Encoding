#include "BinaryTree.h"

BinaryTree::BinaryTree(std::map<char,int> chars) {
    std::list<Node *> nodes ;  //nodes by which Binary tree will be constructed
    //iterates over chars map to construct nodes.
    for (std::map<char, int>::iterator it = chars.begin(); it != chars.end(); ++it) {
        std::list<Node*>::iterator iterList = nodes.begin();
        Node *node = new Node(it->second, it->first);
        if(nodes.size() == 0) {
            nodes.push_back(node);
            continue;
        }
        int i = 0;
        //adds each node to freq map in ascending order by their ascending frequencies
        for(auto& n: nodes){
            i++;
            if(n->freq >= node->freq){
                nodes.insert(iterList,node);
                break;
            }
            else if(nodes.size() == i){
                nodes.push_back(node);
                break;
            }
            iterList++;
        }
    }
    insert(nodes); //constructs binary tree and inserts all nodes.
    encode(root, ""); //encodes each leaf exists in binary tree.
    display();  // prints the diagram of binary tree to treeFile.

}
void BinaryTree::insert(std::list<Node*> nodes) {

    Node* node;
    if (nodes.size() == 0 ){  // if nodes list is empty
        return;
    }
    if (nodes.size() == 1) {  // if nodes list has only one node
        root = nodes.front();
        nodes.clear();
        return;
    }
    else {                    // if nodes list contains more than one value
        Node* left = nodes.front();
        nodes.pop_front();
        Node* right = nodes.front();
        nodes.pop_front();

        node = new Node(left,right);
        if(nodes.empty()){
            root = node;
            return;
        }
    }

    std::list<Node *>::iterator it = nodes.begin();
    int i = 0;
    for (auto &n: nodes) {
        i++;
        if (n->freq >= node->freq) {
            nodes.insert(it, node);
        }
        else if (nodes.size() == i){  // if i points last element of nodes
            nodes.push_back(node);
        }
        else {
            ++it;
            continue;
        }
        insert(nodes);
        break;

    }
}
void BinaryTree::encode(Node* node, std::string s) {
    // encodes charcaters with preorder traversal and fills the encoded map.
    if (node == NULL || (node->left == NULL && node->right == NULL)){
        if(node != NULL) {
            encoded[node->data] = s;
        }
        return;
    }
    encode(node->left, s + "0");
    encode(node->right, s + "1");

}
std::string BinaryTree::printEncoded(){
    //returns a string of characters with encoded data.
    std::stringstream ss;
    for(auto& code:encoded){
        if(code.first == '\n'){
            ss<< "\\n\t" <<code.second<< "\n";
            continue;
        }
        ss << code.first << "\t" << code.second << "\n";
    }
    return ss.str();

}
void BinaryTree::listTree(Node* node,std::string blank,std::string code){
    //Constructs the diagram of the tree with preorder traversal.
    if(node == NULL) {
        return;
    }
    if(node->left == NULL && node->right == NULL){
        blank.append("|---Leaf ").append(code).append(" (");
        if(node->data == '\n'){
            blank+= "\\n";
        }
        else {
            blank += node->data;
        }
        blank.append(")\n");
        file<< blank;
        return ;
    }
    file<<blank << "|----Parent " <<code << std::endl;
    listTree(node->left,blank+"|\t",code+"0");
    listTree(node->right,blank+"|\t",code+"1");
}
void BinaryTree::display(){
    //Prints the diagram of the tree to tree.txt file. Stores tree in tree.txt for using later.
    file.open(treeFile);
    file << "root\n|----subtree left\n";
    listTree(root->left,"|\t","0");
    file<<"|----subtree right\n";
    listTree(root->right, "|\t","1");
    file.close();
}
