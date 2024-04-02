#ifndef SECRETARY_HPP
# define SECRETARY_HPP

class Form;

# include "Staff.hpp"
# include "Enums.hpp"

class Secretary : public Staff {
    public:
        Form* createForm(FormType p_formType);
        void archiveForm();
};

#endif