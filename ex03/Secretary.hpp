#ifndef SECRETARY_HPP
# define SECRETARY_HPP

# include "Enums.hpp"
# include "Staff.hpp"

class Form;

// this is the concrete Factory class (implementing the Factory ISecretary)

class Secretary : public Staff {
    private:
        // std::vector<Form *> from_archive;

    public:
        Secretary(std::string &p_name) : Staff(p_name) {}

    public:
        static Form* createForm(FormType p_formType);
        void archiveForm();
};

#endif