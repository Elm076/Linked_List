#pragma once
#include <algorithm>
#include <stdexcept>
#include <iostream>

template<class T>
class Dynamic_container
{	
	private:
		T* pointer_list = nullptr;
		unsigned int size = 0;
		unsigned int used_size = 0;
        unsigned int last_index = 0;
		void copy_elements();
	
	public:
		Dynamic_container();
	
		explicit Dynamic_container(unsigned int _size);
	
		Dynamic_container(const Dynamic_container& origin);

		Dynamic_container(const Dynamic_container& origin, unsigned int initial_position, unsigned int elements_copied);

		Dynamic_container& operator=(const Dynamic_container& origin);

		void add(const T& data, unsigned int position = UINT_MAX);

		void set(const T& data, unsigned int position);

		T& get(unsigned int position);

        T& operator[](unsigned int i);

		void order_container();

		void reverse_order_container();

		unsigned int used_tam();

		~Dynamic_container();

};

 static unsigned int next_power2(unsigned int num) {
     unsigned int result = 2;
     while (result <= num) {
         result = result * 2;
     }
     return result;
}


/**
* Default constructor. It creates a new object
* @brief	Default Constructor
* @return	New object with 1 position available
*/

template<class T>
Dynamic_container<T>::Dynamic_container() {
	size = 1;
	used_size = 0;
	pointer_list = new T[size];
}

/**
* Constructor that creates the object with a max size
* @brief	Constructor
* @param	log_size Length of the vector that contains pointer_list
* @return	New object with length log_size
*/

template<class T>
Dynamic_container<T>::Dynamic_container(unsigned int _used_size) {
	this->size = next_power2(_used_size);
	this->used_size = 0;
	pointer_list = new T[this->size];
}

/**
* Copy constructor that copies the origin object
* @brief Copy Constructor
* @param origin Object that will be copied
* @return New object copied from origin
*/

//PROBAR ESTO
template<class T>
Dynamic_container<T>::Dynamic_container(const Dynamic_container& origin) {
	this->size = origin.size;
	this->used_size = origin.used_size;
	this->pointer_list = origin.pointer_list;
	for (unsigned int i = 0; i < this->size; i++) {
		//this->pointer_list[i] = origin.pointer_list[i];
		*(this->pointer_list + i) = *(origin.pointer_list + i);
	}
}
/**
* Copy Constructor that copies partially the origin object
* @brief	Partial Copy Constructor
* @param	origin Object that is gonna be copied
* @param	initial_position Position of origin where it will start copying
* @param	elements_copied Number of elements it will copy from origin
* @return	Object copied given the correct params
*/

//PROBAR ESTO
template<class T>
Dynamic_container<T>::Dynamic_container(const Dynamic_container& origin, unsigned int initial_position, unsigned int elements_copied) {
	this->pointer_list = origin.pointer_list;
	this->size = next_power2(elements_copied);
	this->used_size = elements_copied;
	for (unsigned int i = 0; i < this->size; i++) {
		//this->pointer_list[i] = origin.pointer_list[i] + initial_position;
		*(this->pointer_list + i) = *(origin.pointer_list + initial_position + i);
	}
}

/**
* Copy the origin object on destiny object
* @brief	operator =
* @param	origin Object origin that is gonna be copied
* @return	The copied object
*/

//PROBAR ESTO
template<class T>
Dynamic_container<T>& Dynamic_container<T>::operator=(const Dynamic_container& origin) {
	if(this != &origin)
        if (origin.pointer_list) {
	    	this->size = origin.size;
	    	this->used_size = origin.used_size;
	    	this->pointer_list = origin.pointer_list;
	    	for (unsigned int i = 0; i < this->size; i++) {
	    		//this->pointer_list[i] = origin.pointer_list[i];
	    		*(this->pointer_list + i) = *(origin.pointer_list + i);
	    	}
	    	return *this;
	    }
}

/**
 * @brief Method that gives the tam used (NOT TEH REAL ONE) in the container
 * @return The num of elements that contains the container
 */
template<class T>
unsigned int Dynamic_container<T>::used_tam() {
	return used_size;
}

template<class T>
void Dynamic_container<T>::copy_elements() {
    unsigned int new_size = next_power2(this->size);
    T* aux_pointer_list = new T[new_size];
	for (unsigned int i = 0; i < this->used_size; i++) {
		//aux_container.pointer_list[i] = this->pointer_list[i];
		aux_pointer_list[i] = this->pointer_list[i];
	}

	delete[] pointer_list;
    this->size = new_size;
	this->pointer_list = aux_pointer_list;
}

/**
 * @brief Method to add an object in the end of used positions of the container
 * @param data T& object
 */
template<class T>
void Dynamic_container<T>::add(const T& data, unsigned int position) {
	if (used_size == size) {
        copy_elements();
	}
    if(position == UINT_MAX){
        //this->pointer_list[this->used_size] = data
        *(pointer_list + last_index) = data;
        used_size += 1;
        last_index += 1;
    }
    else{
            for (unsigned i = used_size - 1; i >= position; i--) {
                pointer_list[i+1] = pointer_list[i];
            }
        pointer_list[position] = data;
    }


}

/**
 * @brief Method to set an object to the container
 * @param data T& object
 * @param position index of the object inside the structure
 */
template<class T>
void Dynamic_container<T>::set(const T& data, unsigned int position) {
	if (position > this->size) {
		throw std::out_of_range("The given position exceed the max tam of the container");
	}
	else {
		//this->pointer_list[position] = data;
		*(this->pointer_list + position) = data;
	}
}

/**
 * @brief Method to get an existing object in the container given his position
 * @param position index of the object inside the structure
 * @return The object indexed by the given position
 */
template<class T>
T& Dynamic_container<T>::get(unsigned int position) {
	if (position >= this->size) {
		throw std::out_of_range("The given position exceed the max tam of the container");
	}
	else {
		//return this->pointer_list[position];
		return *(this->pointer_list + position);
	}
}

/**
 * @brief Operator to achieve a object contained in the structure
 * @param position index of the object inside the structure
 * @return The object indexed by the given position
 */
template<class T>
T& Dynamic_container<T>::operator[](unsigned int position) {
    if (position >= this->size) {
        throw std::out_of_range("The given position exceed the max tam of the container");
    }
    else {
        //return this->pointer_list[position];
        return *(this->pointer_list + position);
    }
}

/**
 * @brief Method to order the container from the minor to the greatest object
 */
template<class T>
void Dynamic_container<T>::order_container() {
	std::sort(this->pointer_list, this->pointer_list + this->used_size);
}

/**
 * @brief Method to order the container from the greatest to the minor object
 */
template<class T>
void Dynamic_container<T>::reverse_order_container() {
	std::sort(this->pointer_list, this->pointer_list + this->used_size, [](T& a, const T& b) {
		return a > b;
		});
}


/**
 * @brief Destructor of the class Dynamic_container
 */
template<class T>
Dynamic_container<T>::~Dynamic_container() {
	delete[] pointer_list;
}
