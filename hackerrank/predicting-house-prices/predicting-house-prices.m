clear; close all; clc;

function J = computeCost(X, y, theta)
	m = length(y);
	J = 1 / (2 * m) * sum((X * theta - y) .^ 2);
end

function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iter)
	m = length(y);
	for iter = 1:num_iter
		thetaChange = alpha * (1 / m) * sum(X' * (X * theta - y));
		theta = theta - thetaChange;
		J_history(iter) = computeCost(X, y, theta);
	end
end

% Reading input
fid = fopen('predicting-house-prices.in', 'r');
F = fscanf(fid, '%d', 1);
N = fscanf(fid, '%d', 1);
A = fscanf(fid, '%f', [F + 1, N]);
A = A';
X = A(:, 1 : F);
y = A(:, F + 1);

T = fscanf(fid, '%d', 1);
P = fscanf(fid, '%f', [F, T]);
P = P';
P = [ones(rows(P), 1), P];

% Add an additional first column of ones to the design matrix
% to take into account the intercept term
X = [ones(rows(X), 1), X];

% Initialize fitting parameters
theta = zeros(F + 1, 1);

% Some gradient descent algorithm settings
iterations = 2000;
alpha = 0.0005;

[theta, J_history] = gradientDescent(X, y, theta, alpha, iterations);

#figure;
#plot((1 : iterations), J_history, 'rx');
#plot(X(:, 2), y, 'rx');
#hold on;
#plot(X(:, 2), X * theta, '-');
#legend('Training data', 'Liniar regression');
#hold off;

ans = P * theta;
disp(ans);
