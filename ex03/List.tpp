#ifndef LIST_TPP
# define LIST_TPP

# include "ListItems.hpp"
# include "List.hpp"

template <class T>
List<T>::~List() {
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
        delete (*item);
    }

    for (typename std::vector<T *>::const_iterator item = other.items.begin(); item != other.items.end(); item++) {
        this->addItem(new T(**item));
    }
}

#endif