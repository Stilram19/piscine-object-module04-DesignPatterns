# include "Course.hpp"
# include "Student.hpp"
# include "Professor.hpp"

const std::string &Course::get_name() { return (this->_name); }

void Course::assign(Professor* p_professor) {
    this->_responsable = p_professor;
}

void Course::subscribe(Student* p_student) {
    if (p_student == NULL) {
        return ;
    }

    for (std::vector<Student*>::const_iterator student = this->_students.begin(); student != this->_students.end(); student++) {
        if (*student == p_student) {
            return ;
        }
    }
    this->_students.push_back(p_student);
}

void Course::close() {
    // demanding from the responsable to close the course
    if (this->_responsable != NULL) {
        this->_responsable = NULL;
    }

    // anouncing the end of the course for all subscribed students
    std::vector<Student *>::iterator student = this->_students.begin();

    while (student != this->_students.end()) {
        (*student)->graduate(this);
        student = this->_students.erase(student);
    }
}
