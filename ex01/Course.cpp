# include "Course.hpp"
# include "Student.hpp"

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
