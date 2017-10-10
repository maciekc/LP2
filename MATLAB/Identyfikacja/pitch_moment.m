close all
clear all
v = [7.1 6.3 5.2 3.75 0 -5.15 -7.05 -8.7];
masa = [0 15 30 45 60 75 90 105]; 
moment = masa.*0.001*0.23*9.81;
x = -10:0.01:8;

wsp = polyfit(v, moment, 3);
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