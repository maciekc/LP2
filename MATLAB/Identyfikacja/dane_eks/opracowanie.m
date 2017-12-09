close all

load('LQI_follow.mat')
lqi_f = SD1.signals(2).values(1:50000,:);
time = SD1.time(1:50000);

load('LQ_follow.mat')
lq_f = SD1.signals(2).values(1:50000,:);
% figure(2)
% plot(time, lq_f)
% grid on

figure(1)
plot(time, lqi_f(:,1), time, lq_f);
grid on
hold on 
% plot(time, lqi_f(:,2), 'b')
% plot(time, lq_f(:,2), 'g')
xlabel('czas [s]')
ylabel('po³o¿enie k¹towe [^0]')
legend('LQI', 'LQ', 'wart zad.')
