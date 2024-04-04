# include "Student.hpp"
# include "Classroom.hpp"

void Student::attendClass(Classroom *p_classroom) {
    (void)p_classroom;
}

void Student::exitClass() {
    this->exit();
}

void Student::graduate(Course* p_course) {
    if (p_course == NULL) {
        return ;
    }

    this->removeItem(p_course);
}

void Student::subscribe(Course *p_course) {
    this->addItem(p_course);
}