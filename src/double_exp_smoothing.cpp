#include <iostream>
#include <fstream>
#include "DoubleExpSmoothing.hpp"

int main(int argc, char *argv[]) {
    double alpha, beta, x0, x1, temp, m;
    std::string line;

    if (argc != 7) {
        std::cout << "Enter : file_name alpha beta x0 x1 m" << std::endl;
        return 0;
    }

    alpha = std::stod(argv[2]);
    beta = std::stod(argv[3]);
    x0 = std::stod(argv[4]);
    x1 = std::stod(argv[5]);
    m = std::stod(argv[6]);

    std::ifstream ifstream(argv[1]);
    std::ofstream ofstream("double_exp_smt.txt");

    if (!ifstream.is_open()) {
        std::cout << "Cannot open file" << std::endl;
        return 0;
    }

    DoubleExpSmoothing expSmoothing(alpha, beta, x0, x1);

    for (int i = 0; i <= m; ++i) {
        ofstream << expSmoothing.forecast(i) << " ";
    }
    ofstream << std::endl;

    while (std::getline(ifstream, line)) {
        try {
            temp = std::stod(line);
        } catch (const std::invalid_argument &ia) {
            std::cerr << "Invalid argument: " << ia.what() << '\n';
            continue;
        }
        expSmoothing.update(temp);
        for (int i = 0; i <= m; ++i) {
            ofstream << expSmoothing.forecast(i) << " ";
        }
        ofstream << std::endl;
    }

    std::cout << "Data written to double_exp_smt.txt" << std::endl;
    std::cout << "Done!" << std::endl;

    ifstream.close();
    ofstream.close();
}