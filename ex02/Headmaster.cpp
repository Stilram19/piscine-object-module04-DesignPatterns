# include "Headmaster.hpp"
# include "Form.hpp"

bool Headmaster::hasForm(Form *p_form) {
    if (p_form == NULL) {
        return (false);
    }

    for (std::vector<Form *>::const_iterator form = this->_formToValidate.begin(); form != this->_formToValidate.end(); form++) {
        if (*form == p_form) {
            return (true);
        }
    }
    return (false);
}

void Headmaster::deleteForm(Form *p_form) {
    if (p_form == NULL) {
        return ;
    }

    for (std::vector<Form *>::iterator form = this->_formToValidate.begin(); form != this->_formToValidate.end(); form++) {
        if (*form == p_form) {
            this->_formToValidate.erase(form);
            return ;
        }
    }
}

void Headmaster::receiveForm(Form* p_form) {
    if (p_form == NULL) {
        return ;
    }

    if (this->hasForm(p_form)) {
        return ;// already there
    }

    // add to waiting list
    this->_formToValidate.push_back(p_form);
}

// overriding the signForm function inherited from Staff
void Headmaster::sign(Form *p_form) {
    if (p_form == NULL) {
        return ;
    }

    if (this->hasForm(p_form) == false) {
        return ;// no such form   
    }

    p_form->execute();
    this->deleteForm(p_form);
}
