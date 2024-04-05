# include "Headmaster.hpp"
# include "Form.hpp"
# include "Professor.hpp"
# include "Student.hpp"
# include "Secretary.hpp"
# include "Bells.hpp"

Headmaster::Headmaster(std::string &p_name, Secretary *secretary) : Person(p_name), Staff(p_name), List<Form>(true), secretary(secretary) {
    Headmaster::bells[BreakRingBell] = new BreakBell();
    Headmaster::bells[LunchRingBell] = new LunchBell();
    Headmaster::bells[GraduationRingBell] = new GraduationBell();
    // adhering to the Open/Closed principle
}

Headmaster::~Headmaster() {
    for (std::map<Event, Bell *>::iterator bell = this->bells.begin(); bell != this->bells.end(); bell++) {
        delete bell->second;
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

void Headmaster::bellRing(Event event) {
    // adhering to the Open/Closed principle
    try {
        Bell *bell = this->bells.at(event);

        bell->ring();
    }
    catch (const std::out_of_range &e) {
        return ;// event not found
    }
}

void Headmaster::subscribeObserverToEvent(BellObserver *observer, Event event) {
    // adhering to the Open/Closed principle
    try {
        Bell *bell = this->bells.at(event);

        bell->addObserver(observer);
    }
    catch (const std::out_of_range &e) {
        return ;// event not found
    }
}

void Headmaster::subscribeToAllEvents(BellObserver *observer) {
    for (std::map<Event, Bell *>::iterator bell = this->bells.begin(); bell != this->bells.end(); bell++) {
        bell->second->addObserver(observer);
    }
}

void Headmaster::removeBellOvserver(BellObserver *observer, Event event) {
    // adhering to the Open/Closed principle
    try {
        Bell *bell = this->bells.at(event);

        bell->removeObserver(observer);
    }
    catch (const std::out_of_range &e) {
        return ;// event not found
    }
}
