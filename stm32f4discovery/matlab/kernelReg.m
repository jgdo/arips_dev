function [y, v] = kernelReg(x, K, X,  Y, hp)
% computes prediction and k given x, K, Y

dim = size(Y, 2);
N = size(X, 1);
k = zeros(N, 2);

 L = hp.L;
sw = hp.sw;
sf = hp.sf;

for i = 1: N 
  for d = 1:dim
    k(i, d) = kernelFunc(x, X(i,:), L(d, :), sf(d), sw(d), 0);
 end
end

y = zeros(1, dim);
v = zeros(1, dim);

for d = 1:dim
  y(d) = k(: ,d)' * (K{d} \ Y(:,d)); % mean
  v(d) = kernelFunc(x,x, L(d, :), sf(d), sw(d), 0) - k(:, d)' * (K{d} \k(:, d)); % variance
end

end