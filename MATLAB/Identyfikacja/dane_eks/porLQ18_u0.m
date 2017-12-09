close all 

T = 25000;
load('LQpi-18.mat')

LQ9 = SD1.signals(2).values(1:T,:);
timelq = SD1.time(1:T);

load('LQpi-9_por2.mat')
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