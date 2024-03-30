# include "Course.hpp"

void Course::subscribe(Student* p_student) {
	// to ensure that we don't have useless repititions in the list
    for (std::vector<Student*>::const_iterator student = this->_students.begin(); student != this->_students.end(); student++) {
        if (*student == p_student) {
            return ;
        }
    }
    this->_students.push_back(p_student);
}
