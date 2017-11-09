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

%% Moment si�y no�nej od pr�dko�ci �mig�a
pwm = [0.63 0.51 0.37 0.23 0 -0.35 -0.565 -0.85];
v = [7.1 6.3 5.2 3.75 0 -5.15 -7.05 -8.7];
masa = [0 15 30 45 60 75 90 105]; 
moment = -masa.*0.001*0.26*9.81;
moment = moment - moment(5);

wsp_M_V = polyfit(v, moment, 5);
poly_V = -10:0.01:8;
poly_M = polyval(wsp_M_V, poly_V);
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
wsp_U_V=polyfit(pred,PWM,5);
poly_PWM = polyval(wsp_U_V, poly_V);
figure(2);
plot(pred, PWM, '*', poly_V, poly_PWM, 'g');
grid on;
xlabel('Pr�kdo�� [RPS]');
ylabel('Wsp. PWM');
legend('Pomiary','Aproksymacja');

%% Przeliczenie pr�dko�ci
vp = [-8.6 -7.3 -5.7 -3.6 3.58 5.7 7.2 8.3];
napiecie = [-1.41 -1.2 -0.933 -0.59 0.585 0.936 1.175 1.383];
wsp_V = polyfit(vp,napiecie , 1);

%% Dobranie parametr�w modelu uk�adu silnik DC - �mig�o
load('Pitch_char_U_V.mat');
Iz = 1e-4;
Pitch_char(:,2)=1000/0.52*polyval(wsp_V,Pitch_char(:,2));
options = optimoptions(@lsqnonlin,'Display','iter');
cel=@(param) step_smiglo(param, wsp_U_V, Pitch_char);
Iz = lsqnonlin(cel, Iz, 0,[],options);

t_vect=(0:(length(Pitch_char)-1))/fs;
[t,w]=ode45(@(t,w) (Pitch_char(floor(t*fs)+1,1)-polyval(wsp_U_V,w/60))/Iz,t_vect,0);
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
load('kat_-02.mat');
load('pred_-02.mat');
signals=[v,k];
wsp_M_h = ones(1,5);
f_h=2e-6;
decision=[f_h wsp_M_h];
options = optimoptions(@lsqnonlin,'Display','iter');
cel=@(param) step_azimuth(param, signals);
decision = lsqnonlin(cel, decision, [0.01;-1e3;-1e3;-1e3;-1e3;-1e3],[],options);

t_vect=(0:(length(signals)-1))/fs;
[t,x]=ode45(@(t,x) ([x(2);-decision(1)*x(2)+polyval(decision(2:end),signals(floor(t*fs)+1,1)/60)]),t_vect,[0;0]);
figure(6);
plot(t_vect, signals(:,2), 'b', t, x(:,2), 'r');
grid on;
xlabel('Czas [s]');
ylabel('Po�o�enie k�towe [RPS]');
legend('Pomiary','Aproksymacja');