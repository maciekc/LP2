%%
%bez obserwatora
close all 

t = 0.001;
T = 25000;
load('LQ0.mat')

LQ18 = SD1.signals(2).values(1:T,:);
timelq = SD1.time(1:T);

load('LQI0.mat')

LQI18 = SD1.signals(2).values(1:T,:);
timelqi = SD1.time(1:T);

ref = ones(1,T)*0;

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

%%
% z obserwatorem

T = 25000;

load('LQ_z0_obserwator.mat')
LQ18 = SD1.signals(2).values(1:T,1);
timelq = SD1.time(1:T);

load('LQI_z0_obserwator.mat')
LQI18 = SD1.signals(2).values(1:T,1);
timelqi = SD1.time(1:T);

ref = ones(1,T)*0;

figure(2)
plot(timelq, ref, 'r')
hold on 
grid on
plot(timelq, LQ18, 'b')
plot(timelqi, LQI18, 'g')
xlabel('czas [s]')
ylabel('po³o¿enie k¹towe [^0]')
legend('wart. zad.','LQ', 'LQI')


j_LQI18obs = sum((LQI18(1:20000) - 10).^2*t);
j_LQ18obs = sum((LQ18(1:20000) - 10).^2*t);
