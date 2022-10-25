//
// Created by dsash on 24.10.2022.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <locale>
#include <utility>
#include <vector>
#include "Neuron.h"

Neuron::Neuron(int size, std::vector<double> input, std::vector<double> weights, bool factivationFunc) : {
    size = n;
    input = in;
    weights = w;
    activationFunc = f;
}
Neuron::~Neuron() = default;

double Neuron::calculate()
    {
        for (int i = 0; i < input.size(); ++i) {
            output+=input[i]*weights[i];
        }
        output+=weights[weights.size()-1];
        if (activationFunc) return output;
        else return sigmoid(output);
    }

double Neuron::sigmoid(double x)
{
    return 1/(1+exp(-x));
}