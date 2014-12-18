function X = do_kalman(Z, x0, P0, A, Q, H, R)

X = Z;
x = x0;
P = P0;

lines = size(Z, 1);
dim = size(P0);

for i = 1:lines
    x = A * x;
    P = A * P * A' + Q;
    K = P * H' * inv(H * P * H' + R);
    
    z = Z(i, :)';
    x = x + K * (z - H*x);
    P = (eye(dim) - K * H) * P;
    
    X(i, :) = x';
end

plot(1:lines, Z(:, 1), 'r')
hold on
plot(1:lines, X(:, 1), 'b')
legend('Z', 'X')

end