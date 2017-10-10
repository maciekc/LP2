save('Pitch_-45.mat','A_P_angles');
fs=1e3;
figure;
n=size(A_P_angles,1);
t=(1:n)/fs;
plot(t,A_P_angles(:,1),t,A_P_angles(:,2));
title('Encoders characteristic');
grid on;
legend('Azimuth','Pitch');