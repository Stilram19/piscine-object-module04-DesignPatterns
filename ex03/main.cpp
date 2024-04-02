# include "Headmaster.hpp"
# include "Professor.hpp"
# include "Student.hpp"
# include "Secretary.hpp"
# include "singletons.hpp"

// Headmaster requires Professor to attend his class
void test1() {
    std::string headmasterName("Donald");
    std::string Prof1Name("George");
    std::string Prof2Name("Bob");
    std::string SecretaryName("Bob");

    Secretary secretary(SecretaryName);
    Headmaster headmaster(&secretary, headmasterName);
    Professor prof1(Prof1Name, &headmaster);
    Professor prof2(Prof2Name, &headmaster);

    RoomList &roomlist_ref = RoomList::get_instance();
    CourseList &courselist_ref = CourseList::get_instance();

    std::cout << "Initial number of rooms: " << roomlist_ref.size() << std::endl;
    std::cout << "Initial number of courses: " << courselist_ref.size() << std::endl;

    prof1.requestCourseCreation(70, 30, "Design Patterns");
    prof2.requestCourseCreation(70, 30, "Template Programming in c++");

    std::cout << "Number of courses after both professors request course creation: " << courselist_ref.size() << std::endl;

    headmaster.askProfToAttendClass(&prof1);
    headmaster.askProfToAttendClass(&prof2);

    std::cout << "Number of rooms after both professors request class creation: " << courselist_ref.size() << std::endl;
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
