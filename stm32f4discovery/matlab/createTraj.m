function [M, times] = createTraj(start, stop, time_f, steps)
    A = [1, 0, 0, 0, 0, 0; ...
     0, 1, 0, 0, 0, 0; ...
     0, 0, 2, 0, 0, 0; ...
     1, time_f, time_f^2, time_f^3, time_f^4, time_f^5; ...
     0, 1, 2*time_f, 3*time_f^2, 4*time_f^3, 5*time_f^4; ...
     0, 0, 2, 6*time_f, 12*time_f^2, 20*time_f^3];
 
spline_state_start = [start, 0, 0, stop, 0, 0]';
spline_a = A \ spline_state_start;

function q_t = spline_q_des(t) 
    q_t = [spline_a(1) + spline_a(2)*t + spline_a(3)*t^2 + spline_a(4)*t^3 + spline_a(5)*t^4 + spline_a(6)*t^5, ... %  q
        spline_a(2) + spline_a(3)*2*t + spline_a(4)*3*t^2 + spline_a(5)*4*t^3 + spline_a(6)*5*t^4, ... % qd
        spline_a(3)*2 + spline_a(4)*6*t + spline_a(5)*12*t^2 + spline_a(6)*20*t^3];
end

M = zeros(steps, 6);
times = zeros(steps, 1);

dt = time_f / (steps-1);

for i = 1:steps
    t = (i-1) * dt;
    times(i) = t;
    
    q_des_t = spline_q_des(t); % desired state at current time
    
    q_desired = [q_des_t(1),0]; % desired state of second joint is always 0
    qd_desired = [q_des_t(2),0];
    qdd_desired = [q_des_t(3),0];
    
    M(i, :) = [q_desired, qd_desired, qdd_desired];
end

end
