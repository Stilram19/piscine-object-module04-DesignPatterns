#ifndef STUDENT_LIST_HPP
# define STUDENT_LIST_HPP

class Student;

# include "Singleton.hpp"

class StudentList : Singleton<Student> {

};

#endif