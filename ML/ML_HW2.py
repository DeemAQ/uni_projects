#  Made by Deem_Alqud, 2021.


import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.preprocessing import MinMaxScaler


def hypothesis(X, theta):
    return np.dot(X, theta.T)


def costFunction(X, y, theta):
    """
    :param X: Vector, each row is a training examples. each column is a feature. m x n
    :param y: Array, real output. m x 1 dimension
    :param theta: Array, weights. 1 x n
    :return: Cost
    """

    m = len(y_output)
    y_hat = hypothesis(X, theta)
    error = y_hat - y
    J = np.sum(error ** 2) / (2 * m)
    return J


def gradientDescent(X, y, theta, alpha):
    """
    :param X: Vector, each row is a training examples. each column is a feature. m x n
    :param y: Array, real output. m x 1 dimension
    :param theta: Array, weights. 1 x n
    :param alpha: Float, learning rate
    :return: Cost array and theta
    """

    m = len(y_output)
    cost_array = np.zeros(iterations)
    for i in range(iterations):
        cost_array[i] = costFunction(X, y, theta)
        error = hypothesis(X, theta) - y
        sigma = (alpha * np.dot(error.T, X)) / m
        theta = theta - sigma

    return cost_array, theta


def plotCostIteration(i, J_theta, alpha):
    plt.plot(range(i), J_theta, color='red')
    plt.title("Cost vs. Iteration, for alpha = %f" % alpha)
    plt.ylabel("J(theta)")
    plt.xlabel("Iterations")
    plt.show()


# Reading CV file
data = pd.read_csv('Admission_Predict_Ver1.1.csv')

# Number of features n
n = len(data.columns) - 1

X_input = data.values[:, 1:n]
y_output = data.values[:, n:]

# Adding a column of 1s
X_input = np.column_stack((np.ones(len(y_output)), X_input))

# Theta at the beginning is 0s
theta_init = np.zeros([1, n])

# Learning rates to be experimented with
learning_rates = [0.00001, 0.001, 0.1]

iterations = 1000

# Normalize features
min_max = MinMaxScaler()
X_norm = min_max.fit_transform(X_input, y_output)

for a in learning_rates:
    cost, _theta = gradientDescent(X_input, y_output, theta_init, a)
    cost_norm, theta_norm = gradientDescent(X_norm, y_output, theta_init, a)

    print('learning rate: %f\n' % a)
    print('\ntheta', _theta)
    print('\ntheta norm', theta_norm)

    plotCostIteration(iterations, cost, a)
    plotCostIteration(iterations, cost_norm, a)

    print('_' * 20)
