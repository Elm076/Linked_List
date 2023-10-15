//
// Created by fotop on 10/10/2023.
//

#ifndef PR1_CD_LINKED_LIST_H
#define PR1_CD_LINKED_LIST_H

#include "Node.h"

template <class T>
class Linked_list {


private:
    Node<T>* header;
    Node<T>* tail;
    unsigned int size;

public:
    Linked_list();

    Linked_list(const Linked_list& other);

    Linked_list& operator=(const Linked_list& other);

    T& get_header();

    T& get_tail();

    unsigned int list_size();

    Iterator<T> iterator();

    void push_front(T& _data);

    void push_back(T& _data);

    void push_in_forward(Iterator<T>& i, T& _data);

    void push_in_behind(Iterator<T>& i, T& _data);

    void pop_front();

    void pop_back();

    void pop(Iterator<T>& i);

    Linked_list<T> concatenate(const Linked_list<T>& other);

    ~Linked_list();

};

template <class T>
Linked_list<T>::Linked_list() {
    size = 0;
}

template <class T>
Linked_list<T>::Linked_list(const Linked_list<T> &other) {
    //CHECK THIS
    this->header = other.header;
    this->tail = other.tail;
    this->size = other.size;
}

template <class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T> &other) {
    //CHECK THIS
    this->header = other.header;
    this->tail = other.tail;
    this->size = other.size;
}

template <class T>
T& Linked_list<T>::get_header() {
    return header->data;
}

template <class T>
T& Linked_list<T>::get_tail() {
    return tail->data;
}

template <class T>
Iterator<T> Linked_list<T>::iterator() {
    return Iterator<T>(header);
}

template <class T>
void Linked_list<T>::push_front(T &_data) {
    if (tail == nullptr){
        header = new Node<T>(_data);
        tail = header;
    }
    else{
        Node<T>* new_header;
        new_header = new Node<T>(_data,header);
    }
    size++;

}

template <class T>
void Linked_list<T>::push_back(T &_data) {
    if (header == nullptr){
        tail = new Node<T>(_data);
        header = tail;
    }
    else{
        Node<T>* new_tail;
        new_tail = new Node<T>(_data);
        tail->next = new_tail;
        tail = new_tail;
    }
    size++;
}

template <class T>
void Linked_list<T>::push_in_forward(Iterator<T>& i, T &_data) {
    Node<T>* new_node = new Node<T>(_data, i.node);
    if (header == i.node){
        header = new_node;
    }

    if (header != tail){
        Node<T>* previous_node = nullptr;
        previous_node = header;
        while(previous_node->next != i.node){
            previous_node = previous_node->next;
        }
        previous_node->next = new_node;
    }
    size++;
}

template <class T>
void Linked_list<T>::push_in_behind(Iterator<T> &i, T &_data) {
    Node<T>* new_node = new Node<T>(_data, i.node->next);
    i.node->next = new_node;
    if (tail == new_node){
        tail = new_node;
    }
    size++;
}


template <class T>
void Linked_list<T>::pop_front() {
    if (header == nullptr){
        tail = nullptr;
    }
    else{
        Node<T> deleted_node = header;
        header = header->next;
        delete deleted_node;
    }
    size--;
}

template <class T>
void Linked_list<T>::pop_back() {
    Node<T>* iterator = tail;
    if (header != tail){
        iterator = header;
        while (iterator->next != tail){
            iterator = iterator->next;
        }
        delete tail;
        iterator->next = nullptr;
        tail = iterator;
        if (tail == nullptr){
            header = nullptr;
        }
    }
    size--;
}

template <class T>
void Linked_list<T>::pop(Iterator<T> &i) {
    Node<T>* target = header;
    while (target->next != i.node){
        target = target->next;
    }
    target->next = i.node->next;
    delete i.node;

    size--;
}


template <class T>
unsigned int Linked_list<T>::list_size() {
    return size;
}


template <class T>
Linked_list<T> Linked_list<T>::concatenate(const Linked_list<T> &other) {
    Linked_list<T>
}


template <class T>
Linked_list<T>::~Linked_list() {
    Node<T> to_delete = header;
    while(header != tail or size != 0){
        header = header->next;
        delete to_delete;
        to_delete = header;
        size--;
    }
}

#endif //PR1_CD_LINKED_LIST_H
