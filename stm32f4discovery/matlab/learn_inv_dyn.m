function f = learn_inv_dyn(D)

X = [D(1:end-1, 1), D(1:end-1, 3), D(2:end, 1), D(2:end, 3)];
Y = D(1:end-1, 5);

hp.L = exp([5, 5, 5, 5]);

hp.sf = exp([5, 4]);
hp.sw = exp([-2, -2]);

K = kernelMatrix(X, hp);

f = @(x) kernelReg(x, K, X, Y, hp);

end