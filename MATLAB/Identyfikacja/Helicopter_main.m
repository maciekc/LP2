close all;
clearvars;
%% Laboratorium Problemowe 2 - Helikopter
fs=1e3;

%% Co trzeba zrobiæ:
% 1. Wyznaczyæ k¹t alpha_0.
% 2. Zapisaæ drgania wahad³a fizycznego.
% 3. Wyznaczyæ dok³¹dniej moment niewywa¿enia.
% 4. Funkcj¹ optymalizacyjn¹ znaleŸæ t³umienie i moment bezw³adnoœci.
% 5. Wyznaczyæ parametry z odpowiedzi skokowej prêdkoœci œmig³a.

% Do napisania w MATLAB-ie:
% 1. Dodaæ przeliczenie z ADC na prêdkoœæ obrotow¹.
% 2. Dopasowywania wielomianu do punktów pomiarowych.
% 3. Dobieranie paramterów funkcj¹ lsqnonlin.

%% Moment si³y noœnej od prêdkoœci œmig³a
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
xlabel('Prêkoœæ [RPM]');
ylabel('Moment si³y [Nm]');
grid on;
legend('Pomiary', 'Aproksymacja');

%% Opory ruchu od prêdkoœci obrotowej œmig³a
pred = [-3158 -2890 -2680 -2460 -2270 -2030 -1770 -1470 -1120 -670 0 670 1100 1440 1730 1990 2220 2420 2560 2720 2860]/60;
PWM = -1:0.1:1;

poly_V = linspace(pred(1),pred(end),1e3);
wsp_U_V=polyfit(pred,PWM,5);
poly_PWM = polyval(wsp_U_V, poly_V);
figure(2);
plot(pred, PWM, '*', poly_V, poly_PWM, 'g');
grid on;
xlabel('Prêkdoœæ [RPS]');
ylabel('Wsp. PWM');
legend('Pomiary','Aproksymacja');

%% Przeliczenie prêdkoœci
vp = [-8.6 -7.3 -5.7 -3.6 3.58 5.7 7.2 8.3];
napiecie = [-1.41 -1.2 -0.933 -0.59 0.585 0.936 1.175 1.383];
wsp_V = polyfit(vp,napiecie , 1);

%% Dobranie parametrów modelu uk³adu silnik DC - œmig³o
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
ylabel('Prêdkoœæ k¹towa [RPS]');
legend('Pomiary','Aproksymacja');

%% Co trzeba zrobiæ:
% 1. Wyznaczyæ zale¿noœæ sterowania od prêdkoœci obrotowej dla wirnika
% bocznego.
% 2. Zapisaæ odpowiedzi skokowe prêdkoœci silnika bocznego i dobraæ moment
% bezw³adnoœci.
% 3. Zapisanie odpowiedzi po³o¿enia k¹towego w celu identyfikacji
% parametrów.

% Do napisania w MATLAB-ie:
% 1. Zrobiæ model w Simulink na podstawie równañ ró¿niczkowych.

%% Opory ruchu od prêdkoœci obrotowej œmig³a bocznego
pred_az = [-3010 -2730 -2520 -2270 -2020 -1740 -1450 -1130 -790 -415 0 420 800 1150 1460 1750 2010 2270 2500 2700 2900]/60;
PWM_az = -1:0.1:1;

poly_V_az = linspace(pred_az(1),pred_az(end),1e3);
wsp_U_V_az = polyfit(pred_az,PWM_az,5);
poly_PWM_az = polyval(wsp_U_V_az, poly_V_az);
figure(4);
plot(pred_az, PWM_az, '*', poly_V_az, poly_PWM_az, 'g');
grid on;
xlabel('Prêkdoœæ [RPS]');
ylabel('Wsp. PWM');
legend('Pomiary','Aproksymacja');

%% Dobranie parametrów modelu uk³adu silnik DC - œmig³o boczne
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
ylabel('Prêdkoœæ k¹towa [RPS]');
legend('Pomiary','Aproksymacja');

%% Moment si³y noœnej od prêdkoœci œmig³a bocznego
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
ylabel('Po³o¿enie k¹towe [RPS]');
legend('Pomiary','Aproksymacja');