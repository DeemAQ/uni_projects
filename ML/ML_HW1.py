#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""


@author: emanalbilali
"""


# Deem Alqudaimi
# 439201062


import numpy as np
import pandas as pd
from matplotlib import pyplot as plt


# Difference function, to calculate the difference between the hypothesis and output (error)
def difference(X, y, theta):
    y_hat = np.dot(X, theta)
    return y_hat - y


# MSE cost function
def calculateCost(X, y, theta):
    m = len(y)
    error = difference(X, y, theta)

    return (1 / 2 * m) * np.sum(error ** 2)


# gradient descent function
def gradientDescent(X, y, theta):
    # set the learning rate
    alpha = 0.0005
    # set the number of steps taken by gradient descent
    iterations = 4000
    m = len(y)
    cost = 0

    for i in range(iterations):
        cost = calculateCost(X, y, theta)
        theta0 = theta[0] - (alpha * (1 / m) * np.sum(difference(X, y, theta)))
        theta1 = theta[1] - (alpha * (1 / m) * np.sum(np.dot(difference(X, y, theta), X)))
        theta[0] = theta0
        theta[1] = theta1

    return theta, cost


# ************************ regression script************************
# dataset loading
# training dataset
train_data = pd.read_csv("train.csv")
# removing Nan if any in dataset
train_data = train_data.dropna()

# **************** loading the data in numpy matrix ***********
X = train_data.iloc[:, 0].values
y = train_data.iloc[:, 1].values

# **************** plotting the dataset *********************
plt.scatter(X, y, marker='x')
plt.title(" training dataset ")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()

# **************** Gradient descent **********************

ones = [1 for i in range(len(y))]
X = np.column_stack((ones, X))

# func gradient
theta, cost = gradientDescent(X, y, np.array([0.0, 0.0]))
print('theta:', theta)
print('cost:', cost)

# ****************** plot the model ***********************
t = np.dot(X, theta)
plt.scatter(X[:, 1], y, marker='x')
plt.plot(X[:, 1], t, color='red')
plt.show()

# ****************** prediction ***************************
p1 = t = np.dot([1, 56], theta)
print('The predicted value for p1 is ', p1)
