#ifndef LIST_TPP
# define LIST_TPP

# include "ListItems.hpp"
# include "List.hpp"

template <class T>
List<T>::~List() {
    if (this->isHeapAllocated == false) {
        return ;
    }

    for (typename std::vector<T *>::const_iterator item = this->items.begin(); item != this->items.end(); item++) {
        delete (*item);
    }
};

template <class T>
List<T>::List(const List<T> &other) {
    *this = other;
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other) {
    for (typename std::vector<T *>::const_iterator item = this->items.begin(); item != this->items.end(); item++) {
        if (this->isHeapAllocated == true) {
            delete (*item);
        }
        this->items.erase(item);
    }

    for (typename std::vector<T *>::const_iterator item = other.items.begin(); item != other.items.end(); item++) {
        if (this->isHeapAllocated == true) {
            this->addItem(new T(**item));
            continue ;
        }
        // shallow copy for lists not interested in memory management
        this->addItem(*item);
    }
}

#endif