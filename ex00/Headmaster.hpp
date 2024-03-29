#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include "Staff.hpp"

class Headmaster : public Staff {
    private:
        std::vector<Form*> _formToValidate;
        
    public:
        void receiveForm(Form* p_form);
};

#endif