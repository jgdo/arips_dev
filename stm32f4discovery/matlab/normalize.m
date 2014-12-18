function  [ND, m, v] = normalize(D) 

m = mean(D);
v = std(D);

ND = (D - repmat(m, size(D, 1), 1))./repmat(v, size(D, 1), 1);

end