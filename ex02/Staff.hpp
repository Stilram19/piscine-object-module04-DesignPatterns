#ifndef STAFF_HPP
# define STAFF_HPP

class Form;

# include "Person.hpp"

class Staff : public Person {
    private:

    public:
        Staff(std::string &p_name) : Person(p_name) {}
        void sign(Form *p_form) {
            if (p_form == NULL) {
                return ;
            }
        }
};

#endif