#ifndef SECRETARY_HPP
# define SECRETARY_HPP

# include "Form.hpp"
# include "Staff.hpp"

class Secretary : public Staff {
    private:

    public:
        Form* createForm(FormType p_formType) {
            
        }
        void archiveForm();
};

#endif