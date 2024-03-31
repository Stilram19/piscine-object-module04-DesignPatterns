#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include "Staff.hpp"

class Headmaster : public Staff {
    private:
        std::vector<Form*> _formToValidate;

    public:
        Headmaster(std::string &p_name) : Staff(p_name) {}
        ~Headmaster() {
            for (std::vector<Form *>::const_iterator form = this->_formToValidate.begin(); form != this->_formToValidate.end(); form++) {
                delete *form;
            }
        }

    public:
        void receiveForm(Form* p_form) {
            if (p_form == NULL) {
                return ;
            }

            for (std::vector<Form *>::const_iterator form = this->_formToValidate.begin(); form != this->_formToValidate.end(); form++) {
                if (*form == p_form) {
                    return ;// already there
                }
            }

            // add to waiting list
            this->_formToValidate.push_back(p_form);
        }
};

#endif