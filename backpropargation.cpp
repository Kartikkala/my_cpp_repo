#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

//---------------------------------------------------------
// Utility functions: Sigmoid and its derivative
//---------------------------------------------------------
double sigmoid(double x) {
    // Sigmoid activation function: squashes input into range (0,1)
    return 1.0 / (1.0 + exp(-x));
}

double sigmoidDerivative(double x) {
    // Derivative of the sigmoid function using the value of x before activation.
    double s = sigmoid(x);
    return s * (1 - s);
}

//---------------------------------------------------------
// Class: Neuron
//---------------------------------------------------------
/*
    The Neuron class represents a single neuron in the network.
    Each neuron holds a vector of weights (one for each input)
    and a bias term. The forward method computes the weighted sum of
    inputs, adds the bias, and applies the sigmoid activation function.
*/
class Neuron {
public:
    vector<double> weights;
    double bias;

    // Constructor: initialize weights and bias for a neuron with 'numInputs' inputs
    Neuron(int numInputs) {
        // Random initialization of weights and bias in the range [-1, 1]
        for (int i = 0; i < numInputs; i++) {
            weights.push_back(((double) rand() / RAND_MAX) * 2 - 1);
        }
        bias = ((double) rand() / RAND_MAX) * 2 - 1;
    }

    // Forward pass: compute the neuron's output for given inputs
    // 'weightedSum' is returned by reference to use it later in backpropagation
    double forward(const vector<double>& inputs, double &weightedSum) {
        weightedSum = bias;
        for (size_t i = 0; i < inputs.size(); i++) {
            weightedSum += weights[i] * inputs[i];
        }
        return sigmoid(weightedSum);
    }
};

//---------------------------------------------------------
// Class: NeuralNetwork
//---------------------------------------------------------
/*
    The NeuralNetwork class encapsulates a simple network architecture.
    In this example, it has:
      - One hidden layer (a vector of Neuron objects)
      - One output neuron (which takes inputs from the hidden layer)
    It provides methods for a forward pass and for training on a single example.
*/
class NeuralNetwork {
public:
    vector<Neuron> hiddenLayer; // Hidden layer neurons
    Neuron outputNeuron;        // Output neuron

    // Constructor: create a network with one hidden layer having 'numHidden' neurons.
    // 'numInputs' is the number of inputs to each hidden neuron.
    NeuralNetwork(int numInputs, int numHidden)
        : outputNeuron(numHidden) // Output neuron takes as many inputs as there are hidden neurons.
    {
        // Create hidden layer neurons
        for (int i = 0; i < numHidden; i++) {
            hiddenLayer.push_back(Neuron(numInputs));
        }
    }

    // Forward pass: compute the output of the network for given input values.
    // It also returns the hidden layer outputs and the weighted sums needed for backpropagation.
    double forward(const vector<double>& inputs,
                   vector<double>& hiddenOutputs,
                   vector<double>& hiddenWeightedSums,
                   double &outputWeightedSum)
    {
        hiddenOutputs.clear();
        hiddenWeightedSums.clear();
        // Process each neuron in the hidden layer
        for (auto &neuron : hiddenLayer) {
            double weightedSum;
            double out = neuron.forward(inputs, weightedSum);
            hiddenOutputs.push_back(out);
            hiddenWeightedSums.push_back(weightedSum);
        }
        // The output neuron processes the hidden layer outputs
        return outputNeuron.forward(hiddenOutputs, outputWeightedSum);
    }

    // Train the network on one training example using gradient descent and backpropagation.
    void train(const vector<double>& inputs, double target, double learningRate) {
        // Forward pass: get network's prediction and store intermediate values.
        vector<double> hiddenOutputs;
        vector<double> hiddenWeightedSums;
        double outputWeightedSum;
        double output = forward(inputs, hiddenOutputs, hiddenWeightedSums, outputWeightedSum);

        // Calculate error derivative at the output neuron (using squared error loss)
        double error = output - target;
        double dOutput = error * sigmoidDerivative(outputWeightedSum);

        // Update weights and bias for the output neuron
        for (size_t i = 0; i < outputNeuron.weights.size(); i++) {
            double grad = dOutput * hiddenOutputs[i]; // gradient for each weight
            outputNeuron.weights[i] -= learningRate * grad;
        }
        outputNeuron.bias -= learningRate * dOutput;

        // Backpropagate the error to the hidden neurons and update their weights and biases
        for (size_t i = 0; i < hiddenLayer.size(); i++) {
            // Calculate how much each hidden neuron contributed to the error.
            double dHidden = dOutput * outputNeuron.weights[i] * sigmoidDerivative(hiddenWeightedSums[i]);
            // Update each weight of the hidden neuron
            for (size_t j = 0; j < hiddenLayer[i].weights.size(); j++) {
                double grad = dHidden * inputs[j];
                hiddenLayer[i].weights[j] -= learningRate * grad;
            }
            hiddenLayer[i].bias -= learningRate * dHidden;
        }
    }
};

//---------------------------------------------------------
// Main function
//---------------------------------------------------------
/*
    The main function creates an instance of the NeuralNetwork,
    trains it using randomly generated input data, and then tests
    the trained network on several inputs. The target function used
    for training is a simple function: target = sigmoid(2 * x)
    where x is the input.
*/
int main() {
    // Seed the random number generator
    srand(time(0));

    // Create a neural network:
    // - 1 input neuron
    // - Hidden layer with 2 neurons
    // - 1 output neuron (automatically set based on hidden layer size)
    NeuralNetwork nn(1, 2);

    // Training parameters
    const int epochs = 10000;
    double learningRate = 0.1;

    // Train the network using random inputs from -1 to 1
    for (int i = 0; i < epochs; i++) {
        double x = ((double) rand() / RAND_MAX) * 2 - 1; // Random x in range [-1, 1]
        vector<double> input = {x};
        // Define target output: for demonstration, we use sigmoid(2*x)
        double target = sigmoid(2 * x);
        nn.train(input, target, learningRate);
    }

    // Test the trained network by printing outputs for several inputs
    cout << "Trained network outputs:" << endl;
    for (double x = -1.0; x <= 1.0; x += 0.5) {
        vector<double> input = {x};
        vector<double> hiddenOutputs;
        vector<double> hiddenWeightedSums;
        double outputWeightedSum;
        double output = nn.forward(input, hiddenOutputs, hiddenWeightedSums, outputWeightedSum);
        cout << "Input: " << x << " -> Output: " << output << endl;
    }

    return 0;
}
