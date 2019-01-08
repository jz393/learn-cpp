//  Created by Jane Zhang on 1/7/19.
//  Copyright © 2019 Jane Zhang. All rights reserved.
/*  This is a simple implementation of the gradient 
descent algorithm commonly used in machine learning,
running on a very basic linear regression model.

MODEL:
y = ax + b
error = predicted - actual

GRAD DESCENT:
a_next = a_prev - (ALPHA * error * x)
b_next = b_prev - (ALPHA * error)

ALPHA signifies learning rate
*/

#include <iostream>
using namespace std;

//data
int num_datapoints = 5;
double x[] = {1, 2, 4, 3, 5};
double y[] = {1, 3, 3, 2, 5};

//initialize weights & alpha
double a = 0;
double b = 0;

//architecture of model
double alpha = 0.01;
double num_epochs = 10;


void train() {
    for (int i = 0; i < num_epochs; i++){
        cout << "starting epoch #" << i << endl;
        double avg_loss = 0;

        for (int j = 0; j < num_datapoints; j++) {
            //calculate prediction and error
            double y_hat = a * x[j] + b;//predicted value of y with weights
            double error = y_hat - y[j]; //find the loss
            avg_loss += error;

            //update the weights
            a -= (alpha * error * x[j]);
            b -= (alpha * error);
        
        }
        
        cout << "average loss: " << avg_loss << endl;
    }
}


int main() {
    train();
    cout << "finished training" << endl;
    cout << "value of a: " << a << endl;
    cout << "value of b: " << b << endl;
}