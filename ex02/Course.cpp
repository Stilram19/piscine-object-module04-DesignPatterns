# include "Course.hpp"
# include "Student.hpp"
# include "Professor.hpp"

const std::string &Course::get_name() { return (this->_name); }

void Course::assign(Professor* p_professor) {
    this->_responsable = p_professor;
}

void Course::subscribe(Student* p_student) {
    this->addItem(p_student);
}

void Course::close() {
    if (this->_responsable != NULL) {
        this->_responsable = NULL;
    }

    // anouncing the end of the course for all subscribed students
    std::vector<Student *>::iterator student = this->items.begin();

    while (student != this->items.end()) {
        (*student)->graduate(this);
        student = this->items.erase(student);
    }
}
