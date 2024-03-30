#ifndef SINGLETON_HPP
# define SINGLETON_HPP

# include <vector>

template<class T>
class Singleton {
    private:
        std::vector<T *> items;

    // making it impossible to instantiate objects from outside the class definition
    // to adhere to the Singleton design pattern
    private:
        Singleton();
        Singleton(const Singleton &);
        Singleton &operator=(const Singleton &);

    private:

    public:
        // returns the only and only instance in all the program
        static Singleton<T> *get_instance() {
            static Singleton<T> *instance;

            return (instance);
        }

        void additem(T *p_item) {
            for (std::vector<T *>::const_iterator item = this->items.begin(); item != this->items.end(); item++) {
                if (p_item == *item) {
                    return ; // already there
                }
            }

            this->items.push_back(p_item);
        }

        void removeitem(T *p_item) {
            for (std::vector<T *>::const_iterator item = this->items.begin(); item != this->items.end(); item++) {
                if (p_item == *item) {
                    this->items.erase(item);
                    return ;
                }
            }
        }
};

#endif