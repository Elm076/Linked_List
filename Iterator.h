//
// Created by fotop on 12/10/2023.
//

#ifndef PR1_CD_ITERATOR_H
#define PR1_CD_ITERATOR_H

#include "Node.h"

template <class T> class Node;

template <class T>
class Iterator {
 private:
    Node<T>* node;
    friend class Linked_list<T>;
public:
    Iterator(Node<T>* _node) : node(_node) {}

    bool end() { return  node == nullptr; }

    void next() { node = node->next; }

    T& data () { return node->data; }

    T& operator*() { return node->data; }
};


#endif //PR1_CD_ITERATOR_H
