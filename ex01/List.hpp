#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <vector>

template<class T>
class List {
    private:
        std::vector<T *> items;

    private:
        List(const List &);
        List &operator=(const List &);

    public:
        List() {}
        ~List() {}

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

        size_t size() const {
            return (this->items.size());
        }
};

#endif