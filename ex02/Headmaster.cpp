# include "Headmaster.hpp"
# include "Form.hpp"

void Headmaster::receiveForm(Form* p_form) {
    this->addItem(p_form);
}

// overriding the signForm function inherited from Staff
void Headmaster::sign(Form *p_form) {
    if (p_form == NULL) {
        return ;
    }

    if (this->hasItem(p_form) == false) {
        return ;
    }

    p_form->execute();
    this->removeItem(p_form);
}
