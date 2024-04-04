#ifndef SECRETARY_HPP
# define SECRETARY_HPP

# include "Enums.hpp"
# include "Staff.hpp"

class Form;

// this class represents the Factory producing concrete Commands

class Secretary : public Staff {
    public:
        Secretary(std::string &p_name) : Staff(p_name) {}

    public:
        static Form* createForm(FormType p_formType);
        void archiveForm();
};

#endif