function T = trajToTorque(M, f_inv_dim)

N = size(M, 1);
T = M;

for i = 1:N-1
    T(i, 5) = f_inv_dim([T(i, 1), T(i, 3), T(i+1, 1), T(i+1,3)]');
end

end