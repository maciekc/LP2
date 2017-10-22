close all
clear all

pwm = [0.63 0.51 0.37 0.23 0 -0.35 -0.565 -0.85];
v = [7.1 6.3 5.2 3.75 0 -5.15 -7.05 -8.7];
masa = [0 15 30 45 60 75 90 105]; 
moment = -masa.*0.001*0.26*9.81;
moment = moment - moment(5);
x = -10:0.01:8;

wsp = polyfit(v, moment, 5);
y = polyval(wsp, x);
figure(1)
plot(v,moment, '*')
xlabel('Prêkoœæ [RPM]')
ylabel('Moment si³y [Nm]')
grid on
hold on 
plot(x, y, 'g')
legend('pomiary', 'aproksymacja')
print('../../sprawozdanie/fig/char_statyczna', '-depsc')

%%
vp = [-8.6 -7.3 -5.7 -3.6 3.58 5.7 7.2 8.3];
napiecie = [-1.41 -1.2 -0.933 -0.59 0.585 0.936 1.175 1.383];

figure(2)
plot(vp, napiecie, 'g*')
ylabel('Napiêcie [V]')
wsp2 = polyfit(vp,napiecie , 1);
hold on
grid on
plot(vp, polyval(wsp2, vp), 'r')
xlabel('Odczyt z ADC')
% title('Skalowanie prêdkoœci')
print('../../sprawozdanie/fig/skal_predkosci', '-depsc')
%%
pred = [-3158 -2890 -2680 -2460 -2270 -2030 -1770 -1470 -1120 -670 0 670 1100 1440 1730 1990 2220 2420 2560 2720 2860];
PWM = -1:0.1:1;
figure(3)
plot(pred, PWM, '*')
grid on
xlabel('Prêkdoœæ [RPM]')
ylabel('Wsp. PWM')
print('../../sprawozdanie/fig/PWM_predkosci', '-depsc')