close all;
clearvars;
%% Laboratorium Problemowe 2 - Helikopter
fs=1e3;

%% Co trzeba zrobi�:
% 1. Wyznaczy� k�t alpha_0.
% 2. Zapisa� drgania wahad�a fizycznego.
% 3. Wyznaczy� dok��dniej moment niewywa�enia.
% 4. Funkcj� optymalizacyjn� znale�� t�umienie i moment bezw�adno�ci.
% 5. Wyznaczy� parametry z odpowiedzi skokowej pr�dko�ci �mig�a.

% Do napisania w MATLAB-ie:
% 1. Doda� przeliczenie z ADC na pr�dko�� obrotow�.
% 2. Dopasowywania wielomianu do punkt�w pomiarowych.
% 3. Dobieranie paramter�w funkcj� lsqnonlin.

%% Przeliczenie pr�dko�ci
vp = [-8.6 -7.3 -5.7 -3.6 3.58 5.7 7.2 8.3];
napiecie = [-1.41 -1.2 -0.933 -0.59 0.585 0.936 1.175 1.383];
wsp_V = polyfit(vp, napiecie, 1);

%% Moment si�y no�nej od pr�dko�ci �mig�a
pwm = [0.63 0.51 0.37 0.23 0 -0.35 -0.565 -0.85];
v = polyval(wsp_V,[7.1 6.3 5.2 3.75 0 -5.15 -7.05 -8.7])*1000/0.52;
masa = [0 15 30 45 60 75 90 105];
moment = -masa.*0.001*0.26*9.81;
a=moment(pwm==0);
moment = moment - moment(5);

wsp_M_V = polyfit(v/60, moment, 5);
poly_V = -3e3:3e3;
poly_M = polyval(wsp_M_V, poly_V/60);
figure(1);
plot(v, moment, '*', poly_V, poly_M, 'g');
xlabel('Pr�ko�� [RPM]');
ylabel('Moment si�y [Nm]');
grid on;
legend('Pomiary', 'Aproksymacja');

%% Opory ruchu od pr�dko�ci obrotowej �mig�a
pred = [-3158 -2890 -2680 -2460 -2270 -2030 -1770 -1470 -1120 -670 0 670 1100 1440 1730 1990 2220 2420 2560 2720 2860]/60;
PWM = -1:0.1:1;

poly_V = linspace(pred(1),pred(end),1e3);
wsp_U_V = polyfit(pred,PWM,5);
poly_PWM = polyval(wsp_U_V, poly_V);
figure(2);
plot(pred, PWM, '*', poly_V, poly_PWM, 'g');
grid on;
xlabel('Pr�kdo�� [RPS]');
ylabel('Wsp. PWM');
legend('Pomiary','Aproksymacja');

%% Dobranie parametr�w modelu uk�adu silnik DC - �mig�o
load('Pitch_char_U_V.mat');
I_v = 1e-4;
Pitch_char(:,2)=1000/0.52*polyval(wsp_V,Pitch_char(:,2));
options = optimoptions(@lsqnonlin,'Display','iter');
cel=@(param) step_smiglo(param, wsp_U_V, Pitch_char);
I_v = lsqnonlin(cel, I_v, 0,[],options);

t_vect=(0:(length(Pitch_char)-1))/fs;
[t,w]=ode45(@(t,w) (Pitch_char(floor(t*fs)+1,1)-polyval(wsp_U_V,w/60))/I_v,t_vect,0);
figure(3);
plot(t_vect, Pitch_char(:,2), 'b', t, w, 'r');
grid on;
xlabel('Czas [s]');
ylabel('Pr�dko�� k�towa [RPS]');
legend('Pomiary','Aproksymacja');

%% Co trzeba zrobi�:
% 1. Wyznaczy� zale�no�� sterowania od pr�dko�ci obrotowej dla wirnika
% bocznego.
% 2. Zapisa� odpowiedzi skokowe pr�dko�ci silnika bocznego i dobra� moment
% bezw�adno�ci.
% 3. Zapisanie odpowiedzi po�o�enia k�towego w celu identyfikacji
% parametr�w.

% Do napisania w MATLAB-ie:
% 1. Zrobi� model w Simulink na podstawie r�wna� r�niczkowych.

%% Opory ruchu od pr�dko�ci obrotowej �mig�a bocznego
pred_az = [-3010 -2730 -2520 -2270 -2020 -1740 -1450 -1130 -790 -415 0 420 800 1150 1460 1750 2010 2270 2500 2700 2900]/60;
PWM_az = -1:0.1:1;

poly_V_az = linspace(pred_az(1),pred_az(end),1e3);
wsp_U_V_az = polyfit(pred_az,PWM_az,5);
poly_PWM_az = polyval(wsp_U_V_az, poly_V_az);
figure(4);
plot(pred_az, PWM_az, '*', poly_V_az, poly_PWM_az, 'g');
grid on;
xlabel('Pr�kdo�� [RPS]');
ylabel('Wsp. PWM');
legend('Pomiary','Aproksymacja');

%% Dobranie parametr�w modelu uk�adu silnik DC - �mig�o boczne
load('Azimuth_char_U_V.mat');
Ih = 1e-4;
Azimuth_char(:,2)=1000/0.52*polyval(wsp_V,Azimuth_char(:,2));
options = optimoptions(@lsqnonlin,'Display','iter');
cel=@(param) step_smiglo(param, wsp_U_V_az, Azimuth_char);
Ih = lsqnonlin(cel, Ih, 0,[],options);

t_vect=(0:(length(Azimuth_char)-1))/fs;
[t,w]=ode45(@(t,w) (Azimuth_char(floor(t*fs)+1,1)-polyval(wsp_U_V_az,w/60))/Ih,t_vect,0);
figure(5);
plot(t_vect, Azimuth_char(:,2), 'b', t, w, 'r');
grid on;
xlabel('Czas [s]');
ylabel('Pr�dko�� k�towa [RPS]');
legend('Pomiary','Aproksymacja');

%% Moment si�y no�nej od pr�dko�ci �mig�a bocznego
load('kat_02.mat');
load('pred_02.mat');
signals = [v,k];
poly_rank = 2;
wsp_M_H = ones(1,poly_rank)*1e-3;
f_h = 1e-4;
decision=[f_h wsp_M_H];
options = optimoptions(@lsqnonlin,'Display','iter');
cel=@(param) step_azimuth(param, signals);
decision = lsqnonlin(cel, decision, [0;-1e3*(ones(poly_rank,1))],[],options);
f_h = decision(1);
wsp_M_H = decision(2:end);

t_vect = (0:(length(signals)-1))/fs;
[t,x] = ode45(@(t,x) ([x(2);-decision(1)*x(2)+polyval(decision(2:end),signals(floor(t*fs)+1,1)/60)]),t_vect,[0;0]);
figure(6);
plot(t_vect, signals(:,2), 'b', t, x(:,1), 'r');
grid on;
xlabel('Czas [s]');
ylabel('Po�o�enie k�towe [RPS]');
legend('Pomiary','Aproksymacja');

%% Moment si�y no�nej od pr�dko�ci �mig�a bocznego - total
% signals = cell(0);
% load('kat_02.mat');
% load('pred_02.mat');
% signals{1} = [v,k];
% load('kat_04.mat');
% load('pred_04.mat');
% signals{2} = [v,k];
% load('kat_06.mat');
% load('pred_06.mat');
% signals{3} = [v,k];
% load('kat_-02.mat');
% load('pred_-02.mat');
% signals{4} = [v,k];
% load('kat_-04.mat');
% load('pred_-04.mat');
% signals{5} = [v,k];
% load('kat_-06.mat');
% load('pred_-06.mat');
% signals{6}=[v,k];
% poly_rank = 7;
% wsp_M_h = ones(1,poly_rank)*1e-3;
% f_h = 1e-4;
% decision=[f_h wsp_M_h];
% options = optimoptions(@lsqnonlin,'Display','iter');
% cel=@(param) step_azimuth_total(param, signals);
% decision = lsqnonlin(cel, decision, [0;-1e3*(ones(poly_rank,1))],[],options);

%% Moment bezw�adno�ci dla osi poziomej
alpha_0 = -28.13*pi/180;
load('kat_bezwladnosc.mat');
signals = SD1.signals(2).values(7580:end)*pi/180;
J_v = 1;
f_v = 0.1;
parameters = [J_v f_v alpha_0];
options = optimoptions(@lsqnonlin,'Display','iter');
cel=@(param) step_inertial(param, a, signals);
parameters = lsqnonlin(cel, parameters, [0;0;-30*pi/180],[],options);

J_v = parameters(1);
f_v = parameters(2);
alpha_0 = parameters(3);

t_vect=(0:(length(signals)-1))/fs;
[t,x]=ode45(@(t,x) ([x(2);a/J_v*sin(x(1)-alpha_0)-f_v/J_v*x(2)]),t_vect,[signals(1);0]);
figure(7);
plot(t_vect, signals, 'b', t, x(:,1), 'r');
grid on;
xlabel('Czas [s]');
ylabel('Po�o�enie k�towe');
legend('Pomiary','Aproksymacja');

%% Wyliczenie punktu r�wnowagi
lin_alpha_v = 0;
lin_velocity_v = 0;
lin_w_v = roots(wsp_M_V+[zeros(1,length(wsp_M_V)-1) a*sin(lin_alpha_v-alpha_0)]);
lin_w_v = lin_w_v(lin_w_v>-50 & lin_w_v<50 & imag(lin_w_v)==0);
lin_u_v = polyval(wsp_U_V, lin_w_v);

%% Linearyzacja w punkcie r�wnowagi
lin_M_V_diff = polyder(wsp_M_V);
lin_U_V_diff = polyder(wsp_U_V);
lin_A = [0 1 0;...
    a*cos(lin_alpha_v-alpha_0) -f_v/J_v polyval(lin_M_V_diff, lin_w_v);...
    0 0 -polyval(lin_U_V_diff, lin_w_v)/J_v];
lin_B = [0; 0; 1/J_v];
lin_C = eye(3);
lin_D = zeros(3,1);

%% Regulator LQ dla osi poziomej
Q = [1 0 0;0 0 0;0 0 0];
R = 0.01;
N = zeros(3,1);
K_lqr = lqr(lin_A, lin_B, Q, R, N);