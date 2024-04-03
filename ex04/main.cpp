# include "Headmaster.hpp"
# include "Professor.hpp"
# include "Student.hpp"
# include "Secretary.hpp"
# include "singletons.hpp"

void test1() {
    
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
