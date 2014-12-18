function k = kernelFunc(xi, xj, L, sf, sw,kd)

xi = reshape(xi, length(xi), 1);
xj = reshape(xj, length(xj), 1);

if ~exist('kd','var')
  kd=0;
end

if ~exist('sw','var')
  sw=0;
end

S = diag(L);

sigma = 0.7;

k = sf^2 * exp(-1/2 * (xi - xj)' * (S \ (xi - xj))) + kd * sw^2;

end