/* Name: Yuge Zhao
 ID: 204202442
 Date: May 29
 */
#include <stdio.h>
#include <iostream>
#include <cassert>
#include <vector>

template <typename T, typename CMP=std::less<T>>
class TreeNode;

template <typename T,typename CMP=std::less<T>>
class TreeIterator;

template <typename T, typename CMP=std::less<T>>
class BinarySearchTree;


/** @class TreenNode
 Each TreeNode has data, a left child, a right child, and a parent
 */
template <typename T, typename CMP>
class TreeNode{
    friend class BinarySearchTree<T,CMP>;
    friend class TreeIterator<T,CMP>;

public:
    TreeNode();
    TreeNode(T);
    //TreeNode(int data);
    //TreeNode(int data, TreeNode* left, TreeNode* right);
    
    void insert_nodes(TreeNode<T,CMP>* new_node);
    void print_nodes() const;
    bool find(T value) const;
    
    
private:
    T data;
    TreeNode<T,CMP>* left;
    TreeNode<T,CMP>* right;
    TreeNode<T,CMP>* parent;
    CMP isless;
};




/** @class BinarySearchTree
 A BinarySearchTree contains Treenodes
 */
template <typename T, typename CMP>
class BinarySearchTree {
    friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T,CMP>& tree){
        tree.display(os);
        return os;
    };
    
    friend class TreeIterator<T,CMP>;
    friend class TreeNode<T,CMP>;
    
   
    
public:
    void swap(BinarySearchTree<T,CMP>& a, BinarySearchTree<T,CMP>& b){
        std::swap(a.root, b.root);
    };
    
    BinarySearchTree(); //constructor
    BinarySearchTree(const BinarySearchTree<T,CMP>& bst); //copy constructor
    ~BinarySearchTree();
    BinarySearchTree(BinarySearchTree<T,CMP>&& bst):root(std::move(root)){  //move constructor
        std::cout << "Move performed " << std::endl;};
    
    BinarySearchTree<T,CMP>& operator=(BinarySearchTree<T,CMP> other){
        swap(*this, other);
        
        return *this;
    }
    
    void insert(T data);
    void erase(T data);
    int count(T data) const;
    void print() const;
    void copy(TreeNode<T,CMP>* thisRoot, TreeNode<T,CMP>* sourceRoot);
    
    T smallest();
    T largest();

    
    TreeIterator<T,CMP> begin();
    TreeIterator<T,CMP> end();
    
    void display(std::ostream& os) const;
    
private:
    
    TreeNode<T,CMP>* root;
    //bool isLeaf(TreeNode* node) const;
    void free(TreeNode<T,CMP>*& subtree);
    void display(std::ostream& os, TreeNode<T,CMP>* subtree) const;
    CMP isless;
    
};




/** @TreeIterator
 Iterates BinarySearchTree with a pointer to a TreeNode and a pointer to the tree
 */
template <typename T,typename CMP>
class TreeIterator{
    
    friend class TreeNode<T,CMP>;
    friend class BinarySearchTree<T,CMP>;
    
    friend bool operator== (const TreeIterator<T,CMP>& lhs, const TreeIterator<T,CMP>& rhs){
        return lhs.curcurrent_node -> data == rhs.current_node->data;
    };
    
    friend bool operator!= (const TreeIterator<T,CMP>& lhs, const TreeIterator<T,CMP>& rhs){
        return !(lhs.current_node -> data == rhs.current_node->data);
    };
    
public:
    
    //TreeNode* next();
    // TreeNode* previous();
    TreeIterator(BinarySearchTree<T,CMP>* bst):tree(bst){};
    T& operator* () const;

    
    
    // move forward to next larger value
    TreeIterator<T,CMP>& operator++ ();
    TreeIterator<T,CMP> operator++(int);
    
    // postincrement
    // TreeIterator operator++ (int);
    
    //  move backward to largest value < current value
    TreeIterator<T,CMP>& operator-- ();
    
    // postdecrement
    TreeIterator<T,CMP> operator-- (int);
    
    
private:
    TreeNode<T,CMP>* current_node;
    BinarySearchTree<T,CMP>* tree;
    CMP isless;
    
};








/** Constructor
 */
template <typename T, typename CMP>
TreeNode<T,CMP>::TreeNode(){
    //this->data = 0;
    left = right = parent = nullptr;
}

/** Constructor
 */
template <typename T, typename CMP>
TreeNode<T,CMP>::TreeNode(T data){
 this->data = data;
 left = right = parent = nullptr;
 }

/*
 TreeNode::TreeNode(int data, TreeNode* left, TreeNode* right){
 this -> data = data;
 this -> left = left;
 this -> right = right;
 this->parent = nullptr;
 }
 
 */

/** This function inserts nodes
 @param newnode is the node bein inserted
 */
template <typename T, typename CMP>
void TreeNode<T,CMP>::insert_nodes(TreeNode<T,CMP> *new_node){
    if (isless(new_node->data, this->data)) {
        if (left == nullptr) {
            left = new_node;
            new_node->parent = this;
        }
        else
            left->insert_nodes(new_node);
    }
    
    else if (isless(this->data, new_node->data)){
        if (right == nullptr) {
            right = new_node;
            new_node->parent = this;
        }
        else
            right -> insert_nodes(new_node);
    }
             
}

/** This function find a value
 @param value is the value being found
 */
\
template <typename T, typename CMP>
bool TreeNode<T,CMP>::find(T value) const{
    if (isless(value, data)) {
        if (left == nullptr) {
            return false;
        }
        else
            return left -> find(value);
    }
    
    else if (isless(data, value)){
        if (right == nullptr) {
            return false;
        }
        else
            return right -> find(value);
    }
    else
        return true;
}

/** This function prints out nodes
 */
template <typename T, typename CMP>
void TreeNode<T,CMP>::print_nodes() const{
    if (left != nullptr) {
        left -> print_nodes();
    }
    std::cout << data << "\n";
    if (right != nullptr) {
        right -> print_nodes();
    }
    
    
}







//Constructor
template <typename T, typename CMP>
BinarySearchTree<T,CMP>::BinarySearchTree(){
    root = nullptr;
    //std::cout<< "tree constructed" << std::endl;
}


/** Copy constructor
 @param source is the source BinarySearchTree to be copies
 */
template <typename T, typename CMP>
BinarySearchTree<T,CMP>::BinarySearchTree(const BinarySearchTree<T,CMP>& source):root(source.root){
    /*std::vector<TreeNode<T,CMP> const*> remaining;
    TreeNode<T,CMP> const* cur = source.root;
    while (cur) {
        insert(cur->data);
        if (cur->right) {
            remaining.push_back(cur->right);
        }
        if (cur->left) {
            cur = cur->left;
        }
        else if (remaining.empty()) {
            break;
        }
        else {
            cur = remaining.back();
            remaining.pop_back();
        }
    }*/
    
    
    if(source.root == NULL)
        root = NULL;
    else
        copy(this->root, source.root);
    std::cout << "Copy made" << std::endl;

}


/** Copy helper functino
 @param thisRoot is the TreeNode to be copied to, 
 @param sourceRoot is the TrEENode to be copied
 */
template <typename T, typename CMP>
void BinarySearchTree<T,CMP>::copy(TreeNode<T,CMP> * thisRoot, TreeNode<T,CMP> * sourceRoot){
    if(sourceRoot == nullptr)
    {
        thisRoot = nullptr;
    }
    else
    {
        thisRoot = new TreeNode<T,CMP>;
        thisRoot->data = sourceRoot->data;
        copy(thisRoot->left, sourceRoot->left);
        copy(thisRoot->right, sourceRoot->right);
}
}

/** Uses postorder traversal to print the data values of and all
 deallocate the TreeNode objects (one at a time) in the given
 subtree.
 */
template <typename T, typename CMP>
void BinarySearchTree<T,CMP>::free(TreeNode<T,CMP>*& subtree){
    if(subtree){
        free(subtree->left);
        free(subtree->right);
        //std::cout << "Delete node" << subtree -> data << std::endl;
        delete subtree;
        //subtree = nullptr;
    }
}

//Destructor
template <typename T, typename CMP>
BinarySearchTree<T,CMP>::~BinarySearchTree(){
    free(root);
}


/*
 //Determines whether the given TreeNode node is a leaf
 
 bool BinarySearchTree::isLeaf(TreeNode *node) const{
 assert(node != nullptr);
 if ((node->left == nullptr) && (node->right == nullptr)) {
 return true;
 }
 
 else {
 return false;
 }
 }
 */


//Print function
template <typename T, typename CMP>
void BinarySearchTree<T,CMP>::print() const{
    if (root != nullptr) {
        root -> print_nodes();
    }
}

/** insert a data
 @param data is being inserted
 */
template <typename T, typename CMP>
void BinarySearchTree<T,CMP>::insert(T data){
    TreeNode<T,CMP>* new_node = new TreeNode<T,CMP>;
    new_node->parent = nullptr;
    new_node -> data = data;
    new_node -> left = nullptr;
    new_node -> right = nullptr;
    if (root == nullptr) {
        root = new_node;
        //new_node->parent = nullptr;
    }
    else
        root -> insert_nodes(new_node);
    
    //std::cout << "node inserted" << std::endl;
}


/** count numbers of data
 @param data is being counted
 */
template <typename T, typename CMP>
int BinarySearchTree<T,CMP>::count(T data) const{
    if (root == nullptr) {
        return 0;
    }
    else if (root->find(data)){
        return 1;
    }
    else
        return 0;
}

/** Erase data
 @param data is to be erased
 */
template <typename T, typename CMP>
void BinarySearchTree<T,CMP>::erase(T data){
    //finde node to be removed
    
    TreeNode<T,CMP>* to_be_removed = root;
    to_be_removed->parent = nullptr;
    bool found = false;
    while (!found && to_be_removed != nullptr) {
        if (to_be_removed->data < data) {
            to_be_removed->parent = to_be_removed;
            to_be_removed = to_be_removed->right;
        }
        
        else if (data < to_be_removed->data){
            to_be_removed->parent = to_be_removed;
            to_be_removed = to_be_removed->left;
        }
        else found = true;
    }
    
    if (!found) {
        return;
    }
    
    //to_be_removed contains data, if one of thr children is empty, use the other
    if (to_be_removed->left == nullptr || to_be_removed->right == nullptr) {
        TreeNode<T,CMP>* new_child;
        if (to_be_removed->left == nullptr) {
            new_child = to_be_removed->right;
        }
        else{
            new_child = to_be_removed->left;
        }
        
        if (to_be_removed->parent == nullptr) {
            root = new_child;
        }
        else if (to_be_removed->parent->left == to_be_removed){
            to_be_removed->parent->left = new_child;
        }
        else
            to_be_removed->parent->right = new_child;
        return;
    }
    
    //Neither tree is enpty, find the largest element of the left subtree
    
    TreeNode<T,CMP>* largest_parent = to_be_removed;
    TreeNode<T,CMP>* largest = to_be_removed->left;
    while (largest -> right != nullptr) {
        largest_parent = largest;
        largest = largest->right;
    }
    
    //largest contains largest child in right subtree, move content, unlink child
    
    to_be_removed -> data = largest->data;
    if (largest_parent == to_be_removed) {
        largest_parent->left = largest->left;
    }
    else
        largest_parent->right = largest->right;
    
    
}

/** Finds the smallest value
 @return smallest value T
 */
template <typename T, typename CMP>
T BinarySearchTree<T,CMP>::smallest(){
    //assert(root != nullptr && root ->left != nullptr);
    TreeNode<T,CMP>* smallest_parent = root;
    TreeNode<T,CMP>* smallest = smallest_parent-> left;
    while (smallest -> left != nullptr) {
        smallest_parent = smallest;
        smallest = smallest ->left;
    }
    return smallest->data;
    
}

/** Finds the largest value
 @return largest value T
 */
template <typename T, typename CMP>
T BinarySearchTree<T,CMP>::largest(){
    //assert(root != nullptr && root ->right != nullptr);
    TreeNode<T,CMP>* largest_parent = root;
    TreeNode<T,CMP>* largest = largest_parent->right;
    while (largest -> right != nullptr) {
        largest_parent = largest;
        largest = largest->right;
    }
    return largest->data;
}


/** Begin fnuction for BST from the smallest
 @return an iterator to the smallest TreeNode
 */
template <typename T, typename CMP>
TreeIterator<T,CMP> BinarySearchTree<T,CMP>::begin(){
 

    TreeIterator<T,CMP> itr(this);
    
    /*while (itr.current_node->left != nullptr) {
        itr--;
    }
    return itr;*/
    
    TreeNode<T,CMP>* smallest_parent = root;
    TreeNode<T,CMP>* smallest = smallest_parent-> left;
 
    while (smallest -> left != nullptr) {
        smallest_parent = smallest;
        smallest = smallest ->left;

    }
    itr.current_node = smallest;
    //std::cout << "begin" << std::endl;
    return itr;
 }


/** End function for BST
 @return an iterator to the one after the largest TreeNode
 */
template <typename T, typename CMP>
TreeIterator<T,CMP> BinarySearchTree<T,CMP>::end(){
 
    TreeIterator<T,CMP> itr(this);
 /*TreeNode* smallest_parent = root;
 TreeNode* smallest = smallest_parent-> right;
 while (smallest -> right != nullptr) {
 smallest_parent = smallest;
 smallest = smallest ->right;
 }
 itr.current_node = smallest;*/
     itr = nullptr;
     //std::cout << "end" << std::endl;
 
    return itr;
 }


/**  Send the values of the TreeNodes in the given subtree to the given output stream using a preorder traversal
 @param os is the stream to be written to
 */
template <typename T, typename CMP>
void BinarySearchTree<T,CMP>::display(std::ostream& os, TreeNode<T,CMP>* subtree) const{
    if(subtree != nullptr){
        os << subtree->data << std::endl;
        display(os, subtree->left);
        display(os, subtree->right);
        
    }
    return;
}

/** Displays the stream
 @param os is the stream to be dsiplayed
 */
template <typename T, typename CMP>
void BinarySearchTree<T,CMP>::display(std::ostream &os) const{
    display(os, root);
    return;
}

/** Overloaded operator <<
 @param os is the stream to be displayed
 */
template <typename T, typename CMP>
std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T,CMP>& tree){
    tree.display(os);
    return os;
}











template <typename T, typename CMP>
TreeIterator<T,CMP>& TreeIterator<T,CMP>::operator++(){
    

    if(current_node->right != nullptr){
        current_node = current_node->right;
        while (current_node->left != nullptr){
            current_node = current_node -> left;
        }
        return *this;
    }
    
    else if (current_node->right == nullptr){
        if (current_node->parent && current_node->parent->left == current_node){
            current_node = current_node->parent;
            return *this;
        }
        while(current_node->parent && current_node->parent != tree->root && current_node->parent->right == current_node) 
        {
            if(current_node == tree->root) {
                current_node = nullptr;
                return *this;
            }
            current_node = current_node->parent;
        }
        current_node = current_node->parent;

       
    }
     return *this;

}



template <typename T, typename CMP>
TreeIterator<T,CMP> TreeIterator<T,CMP>::operator++(int){
    TreeIterator<T,CMP> itr = *this;
    if(itr.current_node->right != nullptr){
        itr.current_node = itr.current_node->right;
        while (itr.current_node->left != nullptr){
            itr.current_node = itr.current_node -> left;
        }
        return itr;
    }
    
    else if (itr.current_node->right == nullptr){
        if (itr.current_node->parent && itr.current_node->parent->left == itr.current_node){
            itr.current_node = itr.current_node->parent;
            return itr;
        }
        while(itr.current_node->parent && itr.current_node->parent != tree->root && itr.current_node->parent->right == itr.current_node)
        {
            if(itr.current_node == tree->root) {
                itr.current_node = nullptr;
                return itr;
            }
            
            itr.current_node = itr.current_node->parent;
        }
        itr.current_node = itr.current_node->parent;

        
    }
    return itr;
    
    /*if(itr.current_node->right){
     //stack.push(current_node->right);
     itr.current_node = itr.current_node->right;
     if(itr.current_node->left){
     itr.current_node = itr.current_node->left;
     //stack.push(current_node->right->left);
     }
     return itr;
     }
     */
    
    
    /* TreeNode* next = itr.current_node->right;
     if (next != nullptr) {
     itr.current_node = next;
     
     if(next->left){
     next = next->left;
     itr.current_node = next;
     }
     }*/
    
}

template <typename T, typename CMP>
TreeIterator<T,CMP>& TreeIterator<T,CMP>::operator-- (){
    if(current_node->left != nullptr){
        current_node = current_node->left;
        while (current_node->right != nullptr){
            current_node = current_node -> right;
        }
        return *this;
    }
    
    else if (current_node->left == nullptr){
        if (current_node->parent && current_node->parent->right == current_node){
            current_node = current_node->parent;
            return *this;
        }
        while(current_node->parent && current_node->parent != tree->root && current_node->parent->left == current_node) //while
        {
            if(current_node == tree->root) {
                current_node = nullptr;
                return *this;
            }
            
            current_node = current_node->parent;
        }
        current_node = current_node->parent;
    }
    return *this;
    
}

template <typename T, typename CMP>
TreeIterator<T,CMP> TreeIterator<T,CMP>::operator-- (int){
    TreeIterator<T,CMP> itr = *this;
    if(itr.current_node->left != nullptr){
        itr.current_node = itr.current_node->left;
        while (itr.current_node->right != nullptr){
            itr.current_node = itr.current_node -> right;
        }
        return itr;
    }
    
    else if (itr.current_node->left == nullptr){
        if (itr.current_node->parent && itr.current_node->parent->right == itr.current_node){
            itr.current_node = itr.current_node->parent;
            return itr;
        }
        while(itr.current_node->parent && itr.current_node->parent != tree->root && itr.current_node->parent->left == itr.current_node) //while
        {
            if(itr.current_node == tree->root) {
                itr.current_node = nullptr;
                return itr;
            }
            
            itr.current_node = itr.current_node->parent;
        }
        itr.current_node = itr.current_node->parent;
    }
    return itr;
}

template <typename T, typename CMP>
T& TreeIterator<T,CMP>::operator* () const{
    return current_node->data;
    
}










