//
// Created by fotop on 12/10/2023.
//

#ifndef PR1_CD_NODE_H
#define PR1_CD_NODE_H

template <class T>
class Node {
private:
    //friend class Iterator;
    //friend class Linked_list;
    T data;

    Node *next;

    Node() { next = nullptr; }

    explicit Node(T& _data, Node* _next = nullptr) :
        data(_data),
        next(_next)
        {}
    };

};


#endif //PR1_CD_NODE_H
