#include <iostream>
#include <cassert>
#include "bst.hpp"

using namespace std;

bool test_insert(){
        // setup
        BST b;

        // execution
        b.insert(10); // empty case
        b.insert(2); // non-empty case left
        b.insert(12); // non-empty case right
        b.insert(5); //right on left subbranch
        b.insert(7); //right on right left subbranch

        //validation
        Node* root = b.get_root();
        assert(root != nullptr);
        assert(root->data == 10);
        assert(root->right->data == 12);
        assert(root->left->data == 2);
        assert(root->left->right->data == 5);
        assert(root->left->left == nullptr);
    assert(root->right->right == nullptr);
    assert(root->left->right->left == nullptr);
        assert(root->left->right->right->data == 7);
    assert(root->left->right->right->right == nullptr);
    assert(root->left->right->right->left == nullptr);

        return true;

        //cleanup
}

bool test_search(){
        //set up
        BST b;
        b.insert(10);
        b.insert(2);
        b.insert(12);
        b.insert(5);
        b.insert(7);

        //execution
        bool search1 = b.search(2); // search for value in tree
        bool search2 = b.search(7); // search in end of tree
        bool search3 = b.search(4); // search for value not in tree
        bool search4 = b.search(10);
        bool search5 = b.search(12);
        bool search6 = b.search(5);

        //validation
        assert(search1 == true);
        assert(search2 == true);
        assert(search3 == false);
        assert(search4 == true);
        assert(search5 == true);
        assert(search6 == true);

        return true;

        //cleanup


}

void test_in_order_traversal(){
        // setup
        BST b;
        b.insert(10);
        b.insert(5);
        b.insert(15);
        b.insert(2);
        b.insert(7);
        b.insert(12);
        b.insert(17);

        b.in_order_traversal();
}

void test_pre_order_traversal(){
        BST b;
        b.insert(10);
        b.insert(5);
        b.insert(15);
        b.insert(2);
        b.insert(7);
        b.insert(12);
        b.insert(17);

        b.pre_order_traversal();
        cout << "" << endl;
}

void test_post_order_traversal(){
        BST b;
        b.insert(10);
        b.insert(5);
        b.insert(15);
        b.insert(2);
        b.insert(7);
        b.insert(12);
        b.insert(17);

        b.post_order_traversal();

        cout << "" << endl;

}

bool test_find_min(){
        return true;
}

int main(){
        cout << "Insert test: " << (test_insert() ? "Passed" : "Failed") << endl;
        cout << "Search test: " << (test_search() ? "Passed" : "Failed") << endl;
    test_in_order_traversal();
        cout << "2 5 7 10 12 15 17" << endl;
        //cout << test_pre_order_traversal << endl;
        //cout << test_post_order_traversal << endl;
                        return 0;
}