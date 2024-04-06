# include "Headmaster.hpp"
# include "Headmaster.hpp"
# include "Professor.hpp"
# include "Student.hpp"
# include "Secretary.hpp"
# include "singletons.hpp"
# include "Bell.hpp"
# include "observers.hpp"
# include "School.hpp"

// Headmaster requires Professor to attend his class
void test1() {
    std::string headmasterName("Donald");
    std::string Prof1Name("Bob");
    std::string Prof2Name("Bob");
    std::string StudentName1("Bob");
    std::string StudentName2("Bob");
    std::string SecretaryName("Bob");

    School school(headmasterName, SecretaryName);

    Professor prof1(Prof1Name, "Design patterns", school.getHeadmaster());
    Professor prof2(Prof2Name, "Data Structures and Algorithms", school.getHeadmaster());
    Student student1(school.getHeadmaster(), StudentName1);
    Student student2(school.getHeadmaster(), StudentName2);

    school.recruteProfessor(&prof1);
    school.recruteProfessor(&prof2);

    school.recruteStudent(&student1);
    school.recruteStudent(&student2);

    school.runDayRoutine();
}

int main() {
    try {
        test1();
    }
    catch (const std::out_of_range &e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    }
    return (0);
}
