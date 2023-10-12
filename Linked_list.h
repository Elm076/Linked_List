//
// Created by fotop on 10/10/2023.
//

#ifndef PR1_CD_LINKED_LIST_H
#define PR1_CD_LINKED_LIST_H

#include "Node.h"

template <class T>
class Linked_list {


/*  #################### PRIVATE CLASS OF LINKED LIST ####################
 *  ####################          CLASS NODE          ####################*/
/*  ################ END OF PRIVATE CLASS OF LINKED LIST #################
 *  ####################          CLASS NODE          ####################*/



private:
    Node header;
    Node tail;
    unsigned int size;

public:
    Linked_list();
    Linked_list(const Linked_list& other);
    Linked_list& operator=(const Linked_list& other);
    T& get_header();
    T& get_tail();

};

template <class T>
Linked_list<T>::Linked_list() {
    size = 0;
}

template <class T>
Linked_list<T>::Linked_list(const Linked_list<T> &other) {
    this->header = other.header;
    this->tail = other.tail;
    this->size = other.size;
}

template <class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T> &other) {
    this->header = other.header;
    this->tail = other.tail;
    this->size = other.size;
}

template <class T>
T& Linked_list<T>::get_header() {
    return header.data;
}

template <class T>
T& Linked_list<T>::get_tail() {
    return tail.data;
}

#endif //PR1_CD_LINKED_LIST_H
