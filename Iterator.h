//
// Created by fotop on 12/10/2023.
//

#ifndef PR1_CD_ITERATOR_H
#define PR1_CD_ITERATOR_H

//FORWARD DECLARATIONS OF THESE CLASS
class Linked_list;
class Node;

class Iterator {
 private:
    Node* node;
    friend class Linked_list;
public:
    Iterator(Node* _node) : node(_node) {}
    bool end() { return  node == nullptr; }
    void next(){
        node = node->next;
    }
};


#endif //PR1_CD_ITERATOR_H
