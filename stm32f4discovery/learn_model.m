function [A, Q, H, R] = learn_model(X, Z)
  % estimates kalman parameters from training data
  %
  % Inputs:
  %   X:  states as M x d matrix.
  %       M is the number of states, 
  %       d is the number of dimensions
  %   Z:  measurements as M x d matrix. 
  %       M is the number of measurements, 
  %       d is the number of dimensions
  %
  % Outputs:
  %   A:  State transition model
  %   W:  Covariance of process noise
  %   H:  Observation model
  %   Q:  Covariance of measurement noise
  %   
 
  % make each sample in z, x a column vector
  x = X';
  z = Z';
  
  M = size(x, 2);
  A = x(:, 2:end)*x(:, 1:end-1)' * inv(x(:, 1:end-1)*x(:, 1:end-1)');
  
  Q = 1/(M-1) * (x(:, 2:end)*x(:, 2:end)' - A*(x(:, 1:end-1)*x(:, 2:end)'));
  
  H = (z*x')*inv(x*x');
  
  R = 1/M * (z*z' - H*(x*z'));
end