function [node, pub] = ros() 

node = rosmatlab.node('MathNode', 'localhost', 11311);
pub = node.addPublisher('/trajectory', 'trajectory_msgs/JointTrajectory');

end
