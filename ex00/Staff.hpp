#ifndef STAFF_HPP
# define STAFF_HPP

class Form;

# include "Person.hpp"

class Staff : public Person {
    private:

    public:
        void sign(Form* p_form);
};

#endif