#include <iostream>
#include <fstream>
#include "ExpSmoothing.hpp"

int main(int argc, char *argv[]) {
    double alpha, x0, temp;
    std::string line;

    if (argc != 4) {
        std::cout << "Enter : file_name alpha init_value" << std::endl;
        return 0;
    }

    alpha = std::stod(argv[2]);
    x0 = std::stod(argv[3]);

    std::ifstream ifstream(argv[1]);
    std::ofstream ofstream("exp_smt.txt");

    if (!ifstream.is_open()) {
        std::cout << "Cannot open file" << std::endl;
        return 0;
    }
    ExpSmoothing expSmoothing(alpha, x0);

    ofstream << expSmoothing.get() << std::endl;

    while (std::getline(ifstream, line)) {
        temp = std::stod(line);
        ofstream << expSmoothing.update(temp) << std::endl;
    }

    std::cout << "Done : exp_smt.txt" << std::endl;

    ifstream.close();
    ofstream.close();
}