#ifndef STAFF_HPP
# define STAFF_HPP

class Form;

# include "Person.hpp"

class Staff : virtual public Person {
    private:

    public:
        Staff(std::string &p_name) : Person(p_name) {}
        void sign(Form *p_form) {
            (void)p_form;
            // this function is overriden in the Headmaster class
            // it would be better if the function exists only in the Headmaster class
            // at this point I see no other staff has the authority to sign a form
            // but it may not be the case latter
        }
};

#endif