close all
save('Azimuth_char_U_V.mat','Azimuth_char');
global data T
data = Azimuth_char; % dane pomiarowe
T = 6; %czas koncowy symulacji
%%
%----------------------------------------------------
%    identyfikacja parametró transmitancji œmig³a
%----------------------------------------------------
X0 = [10 0.3];
%      K   T     
options = optimoptions(@lsqnonlin,'Display','iter');
par = lsqnonlin(@cel, X0, [0,0],[],options)

%%
fs=1e3;
n=size(Azimuth_char,1);
t=(1:n)/fs;
z = zeros(100,1);
[y_model ,tt] = step(tf(par(1)*0.4, [par(2) 1]), t);
% [y_model ,tt] = step(tf(par(1)*0.4, [0.32 1]), t);
y = [z; y_model(1:end-100,1)];
fig = figure;
subplot(211)
title('Charakterystyka œmig³a oœ - Azimuth');
plot(t,Azimuth_char(:,2),'b');
hold on
plot(tt, y, 'r')
legend('obiekt','model')
ylabel('Prêdkoœæ [RPM]');
grid on
axis([0 7 0 5])

subplot(212)
plot(t,Azimuth_char(:,1));
ylabel('Sterowanie [V]')
grid on;
axis([0 7 0 0.45])
% legend('Sterowanie [V]','Prêdkoœæ [RPM]');
xlabel('czas [s]')
print('../../sprawozdanie/fig/Azimuth_iden', '-depsc')