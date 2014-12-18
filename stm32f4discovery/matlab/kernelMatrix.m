function K = kernelMatrix(X, hp)

% X: each row a dataset
% computes K

N = size(X, 1);
dim = size(hp.L, 1);

for d = 1:dim
 K_ = zeros(N, N);
  for i = 1:N for j = 1:N 
      K_(i, j) = kernelFunc(X(i, :), X(j, :),   hp.L(d, :), hp.sf(d),  hp.sw(d), i==j);
  end
  K{d} = K_;
end

end
