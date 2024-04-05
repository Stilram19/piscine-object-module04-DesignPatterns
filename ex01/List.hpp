#ifndef LIST_HPP
# define LIST_HPP

# include <vector>
# include <iostream>

template<class T>
class List {
    private:
        bool isHeapAllocated; // are the items allocated in the heap (using new)?

    protected:
        std::vector<T *> items;

    private:
        List(const List &);
        List &operator=(const List &);

    public:
        List(bool isHeapAllocated) : isHeapAllocated(isHeapAllocated) {}
        ~List();

    public:
        bool hasItem(T *p_item) {
            if (p_item == NULL) {
                return (false);
            }

            for (typename std::vector<T *>::const_iterator item = this->items.begin(); item != this->items.end(); item++) {
                if (*item == p_item) {
                    return (true);
                }
            }
            return (false);
        }

        void addItem(T *p_item) {
            if (this->hasItem(p_item) == true) {
                return ;// already in the list
            }

            this->items.push_back(p_item);
        }

        void removeItem(T *p_item) {
            for (typename std::vector<T *>::iterator item = this->items.begin(); item != this->items.end(); item++) {
                if (p_item == *item) {
                    if (this->isHeapAllocated == true) {
                        delete *item;
                    }
                    this->items.erase(item);
                    return ;
                }
            }
        }

        size_t size() const {
            return (this->items.size());
        }
};

# include "List.tpp"

#endif