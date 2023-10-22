//
// Created by fotop on 12/10/2023.
//

#ifndef PR1_CD_NODE_H
#define PR1_CD_NODE_H

//DECLARATION FORWARD OF THE NEEDED CLASSES

template <class T> class Linked_list;
template <class T> class Iterator;


/*  #################### PRIVATE CLASS OF LINKED LIST ####################
 *  ####################          CLASS NODE          ####################*/

template <class T>
class Node {
private:
    friend class Linked_list<T>;
    friend class Iterator<T>;
    T data;
    Node *next;


    Node() {    T();
                next = nullptr; }

    explicit Node(T& _data, Node* _next = nullptr) :
        data(_data),
        next(_next)
        {}
    ~Node() {   ~T();
                next = 0; }
};

/*  ################ END OF PRIVATE CLASS OF LINKED LIST #################
 *  ####################          CLASS NODE          ####################*/



#endif //PR1_CD_NODE_H
