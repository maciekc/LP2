close all 

T = 20000;
load('LQpi-9.mat')

LQ18 = SD1.signals(2).values(1:T,:);
timelq = SD1.time(1:T);

load('LQIpi-9.mat')
LQI18 = SD1.signals(2).values(1:T,:);
timelqi = SD1.time(1:T);

load('pid09.mat')
pid = SD1.signals(2).values(1:T,:);


ref = ones(1,T)*20;

figure(1)
plot(timelq, ref, 'r')
hold on 
grid on
plot(timelq, pid,'m')
plot(timelq, LQ18, 'b')
plot(timelqi, LQI18, 'g')
xlabel('czas [s]')
ylabel('po³o¿enie k¹towe [^0]')
legend('wart. zad.','PID','LQ', 'LQI')

ref = ones(1,T)*30;
%%
figure(2)
plot(timelq, ref, 'r')
hold on 
grid on
plot(timelq, pid,'b')
xlabel('czas [s]')
ylabel('po³o¿enie k¹towe [^0]')
legend('wart. zad.','PID')
ylim([-30 35])