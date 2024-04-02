# include <iostream>

int main() {
    try {

    }
    catch (const std::out_of_range &e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    }
    return (0);
}
