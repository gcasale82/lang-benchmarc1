#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

int formula(int x, int y) {
    return x + y * y + 2;
}

int main() {
    clock_t start, end;
    double total_time;

    start = clock();

    std::ifstream datafile("data.csv");
    if (!datafile) {
        std::cout << "Error opening data file." << std::endl;
        return 1;
    }

    std::string Xs, Ys;
    std::getline(datafile, Xs);
    std::getline(datafile, Ys);

    datafile.close();

    std::istringstream XsStream(Xs);
    std::istringstream YsStream(Ys);

    std::vector<int> X, Y, Z;

    std::string token;
    while (std::getline(XsStream, token, ',')) {
        X.push_back(std::stoi(token));
    }

    while (std::getline(YsStream, token, ',')) {
        Y.push_back(std::stoi(token));
    }

    for (size_t j = 0; j < X.size(); j++) {
        Z.push_back(formula(X[j], Y[j]));
    }

    int total = 0;
    int limit = (X.size() < 100) ? X.size() : 100;
    for (int j = 0; j < limit; j++) {
        total += Z[j];
    }

    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    std::cout << "Total is " << total << " and execution time is " << total_time << " seconds" << std::endl;

    return 0;
}

