function msg = toTrajectory(M, times, node)

msg = rosmatlab.message('trajectory_msgs/JointTrajectory', node);

header = rosmatlab.message('std_msgs/Header', node);
msg.setHeader(header);

name1 = java.lang.String('shoulder_joint');
name2 = java.lang.String('hand_joint');
names = java.util.ArrayList();
names.add(name1);
names.add(name2);

msg.setJointNames(names);

[num_points, dim] = size(M);

secs = uint32(floor(times));
nsecs = uint32(floor(mod(times,1)*1000000000));

points = java.util.ArrayList();

for i = 1:num_points
    point = rosmatlab.message('trajectory_msgs/JointTrajectoryPoint', node);    
    point.setTimeFromStart(org.ros.message.Duration(secs(i),nsecs(i)));

     point.setPositions(M(i,1:2));
     
     if dim > 2
         point.setVelocities(M(i,3:4));
     else
         point.setVelocities(zeros(1,2));
     end
     
     if dim > 4
         point.setAccelerations(M(i,5:6));
     else
         point.setAccelerations(zeros(1,2));
     end
     
     point.setEffort(zeros(1,2));
    
    points.add(point);
end

msg.setPoints(points);

end