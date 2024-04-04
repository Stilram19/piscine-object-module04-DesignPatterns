# include "Headmaster.hpp"
# include "Form.hpp"
# include "Professor.hpp"
# include "Student.hpp"
# include "Secretary.hpp"

Headmaster::~Headmaster() {
    for (std::vector<Form *>::const_iterator item = this->items.begin(); item != this->items.end(); item++) {
        delete (*item);
    }
}

void Headmaster::receiveForm(Form* p_form) {
    this->addItem(p_form);
}

// overriding the signForm function inherited from Staff
void Headmaster::sign(Form *p_form) {
    if (p_form == NULL) {
        return ;
    }

    if (this->hasItem(p_form) == false) {
        return ;// no such form   
    }

    p_form->execute();
    this->removeItem(p_form);
}

void Headmaster::askProfToAttendClass(Professor *prof) {
    if (prof == NULL) {
        return ;
    }

    prof->doClass();
}

void Headmaster::commandStudentToAttendClass(Student *student, Classroom *classroom) {
    if (student == NULL) {
        return ;
    }

    student->attendClass(classroom);
}

Form *Headmaster::getNewForm(FormType formtype) {
    if (this->secretary == NULL) {
        return (NULL);//no secretary to create the requested form
    }

    Form *form = this->secretary->createForm(formtype);
    this->receiveForm(form);
    return (form);
}

void Headmaster::doEvent(Event event) {
    if (event == RingBell) {
        this->bell.ring();
    }
}

void Headmaster::addBellObserver(BellObserver *observer) {
    this->bell.addItem(observer);
}

void Headmaster::removeBellOvserver(BellObserver *observer) {
    this->bell.removeItem(observer);
}
