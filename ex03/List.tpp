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

#endif
