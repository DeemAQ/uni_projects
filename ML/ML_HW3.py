#  Copyright (c) 2021, by Deem_Alqud
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
from sklearn.metrics import ConfusionMatrixDisplay


def sigmoidFunction(z):
    # could use expit from scipy library
    g = 1 / (1 + np.exp(-z))
    return g


def computeLRCost(x, y, theta):
    h = sigmoidFunction(np.dot(x, theta.T))
    m = len(y)
    cost = (-1 / m) * np.sum((y * np.log(h)) + ((y - 1) * np.log(1 - h)))
    error = h - y
    grad = (1 / m) * (np.dot(error.T, x))

    return cost, grad


def trainLRModel(x, y):
    theta = np.zeros([1, x.shape[1]])
    alpha = 0.03
    iterations = 6000
    cost_list = np.zeros(iterations)

    for i in range(iterations):
        cost_list[i], grad = computeLRCost(x, y, theta)
        theta = theta - (alpha * grad)

    return theta


# After training the model and getting theta values, x is from the test set
def predictClass(x, theta, threshold):
    y_hat = sigmoidFunction(np.dot(x, theta.T))
    m = len(y_hat)
    y = np.zeros([m, 1])
    for i in range(m):
        if y_hat[i][0] >= threshold:
            y[i][0] = 1

    return y


def testPerformance(y, y_predicted):
    matrix = ConfusionMatrixDisplay.from_predictions(y_true=y, y_pred=y_predicted)
    plt.title("Confusion Matrix")
    plt.xlabel('Predicted Label')
    plt.ylabel('True Label')
    plt.show()

    TP = matrix.confusion_matrix[1][1]
    FN = matrix.confusion_matrix[1][0]

    FP = matrix.confusion_matrix[0][1]
    TN = matrix.confusion_matrix[0][0]

    accuracy = (TP + TN) / (TP + TN + FP + FN)
    recall = TP / (TP + FN)
    precision = TP / (TP + FP)
    f_score = (2 * recall * precision) / (recall + precision)

    return accuracy, recall, precision, f_score


def main():
    data = pd.read_csv('dataset.csv')
    n = len(data.columns) - 1
    X = data.values[:, 1:n]
    y = data.values[:, n:]
    X_train, X_test, y_train, y_test = train_test_split(X, y, train_size=0.75, test_size=0.25)

    theta = trainLRModel(X_train, y_train)

    y_predicted = predictClass(X_test, theta, 0.5)

    accuracy, recall, precision, f_score = testPerformance(y_test, y_predicted)

    print(f'Theta values = {theta}')
    print(f'Performance Measures:\n'
          f'Accuracy = {accuracy}\nRecall = {recall}\nPrecision = {precision}\nF_score = {f_score}')

    return 0


if __name__ == '__main__':
    main()
