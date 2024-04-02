#ifndef LIST_HPP
# define LIST_HPP

# include <vector>
# include <algorithm>
# include <iostream>

template<class T>
class List {
    protected:
        std::vector<T *> items;

    private:
        List(const List &);
        List &operator=(const List &);

    public:
        List() {}
        virtual ~List() {}

    public:
        void addItem(T *p_item) {
            for (typename std::vector<T *>::iterator item = this->items.begin(); item != this->items.end(); item++) {
                if (p_item == *item) {
                    return ; // already there
                }
            }

            this->items.push_back(p_item);
        }

        void removeItem(T *p_item) {
            for (typename std::vector<T *>::iterator item = this->items.begin(); item != this->items.end(); item++) {
                if (p_item == *item) {
                    this->items.erase(item);
                    return ;
                }
            }
        }

        T* findItemIf(bool (*fun)(T *)) {
            typename std::vector<T *>::iterator item = std::find_if(this->items.begin(), this->items.end(), fun);

            if (item != this->items.end()) {
                return (*item);
            }
            return (NULL);
        }

        size_t size() const {
            return (this->items.size());
        }
};

#endif