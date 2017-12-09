close all

T = 20000;
t = 0.001;

load('LQ_z0_obserwator.mat')
LQ18 = SD1.signals(2).values(1:T,1);
timelq = SD1.time(1:T);

load('LQI_z0_obserwator.mat')
LQI18 = SD1.signals(2).values(1:T,1);
timelqi = SD1.time(1:T);

load('pid0.mat')
pid = SD1.signals(2).values(1:T,:);


ref = ones(1,T)*0;

figure(2)
plot(timelq, ref, 'r')
hold on 
grid on
plot(timelq, pid,'m')
plot(timelq, LQ18, 'b')
plot(timelqi, LQI18, 'g')
xlabel('czas [s]')
ylabel('po�o�enie k�towe [^0]')
legend('wart. zad.','PID','LQ', 'LQI')

j_LQI18 = sum((LQI18(1:20000)).^2*t);
j_LQ18 = sum((LQ18(1:20000)).^2*t);
j_pid = sum((pid(1:20000).^2*t))