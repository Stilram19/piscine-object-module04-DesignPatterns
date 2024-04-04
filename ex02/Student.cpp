# include "Student.hpp"
# include "Classroom.hpp"

bool Student::is_subscribed(Course *p_course) {
    return (this->hasItem(p_course));
}

void Student::erase_course(Course *p_course) {
    this->removeItem(p_course);
}

void Student::attendClass(Classroom *p_classroom) {
    if (p_classroom == NULL) {
        return ;
    }

    if (this->is_subscribed(p_classroom->current_course())) {
        this->enter(p_classroom);
    }
}

void Student::exitClass() {
    this->exit();
}

void Student::graduate(Course* p_course) {
    if (p_course == NULL) {
        return ;
    }

    this->erase_course(p_course);
}

void Student::subscribe(Course *p_course) {
    this->addItem(p_course);
}
