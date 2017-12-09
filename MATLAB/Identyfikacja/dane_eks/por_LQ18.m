close all 

T = 25000;
load('LQpi-18.mat')

LQ18 = SD1.signals(2).values(1:T,:);
timelq = SD1.time(1:T);

load('LQIpi-18.mat')
LQI18 = SD1.signals(2).values(1:T,:);
timelqi = SD1.time(1:T);

ref = ones(1,T)*10;

figure(1)
plot(timelq, ref, 'r')
hold on 
grid on
plot(timelq, LQ18, 'b')
plot(timelqi, LQI18, 'g')
xlabel('czas [s]')
ylabel('po³o¿enie k¹towe [^0]')
legend('wart. zad.','LQ', 'LQI')

j_LQI18 = sum((LQI18(1:20000) - 10).^2*t);
j_LQ18 = sum((LQ18(1:20000) - 10).^2*t);