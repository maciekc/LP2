close all 

T = 30000;
load('LQpi-9.mat')

LQ9 = SD1.signals(2).values(1:T,:);
timelq = SD1.time(1:T);

load('LQpi-9_por3.mat')
LQ9por = SD1.signals(2).values(1:T,1);
timelqi = SD1.time(1:T);

ref = ones(1,T)*20;

figure(1)
plot(timelq, ref, 'r')
hold on 
grid on
plot(timelq, LQ9, 'b')
plot(timelqi, LQ9por, 'g')
xlabel('czas [s]')
ylabel('po³o¿enie k¹towe [^0]')
legend('wart. zad.','u_0 dla 0^0', 'u_0 dla 20^0')

j_LQ9 = sum((LQ9(1:20000) - 20).^2*t);
j_LQ9por = sum((LQ9por(1:20000) - 20).^2*t);