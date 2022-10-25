//
// Created by dsash on 24.10.2022.
//
#pragma once

#include <vector>

class Neuron {
private:
    int size{};
    double output = 0;
    std::vector<double> input;
    std::vector<double> weights;
    bool activationFunc{};

    static double sigmoid(double x);

public:
    Neuron(int n, std::vector<double> in, std::vector<double> w, bool f);

    ~Neuron();

    double calculate();
};

