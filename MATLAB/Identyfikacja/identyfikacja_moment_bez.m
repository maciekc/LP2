offset = -28.13;
figure(1)

global kat1
kat1 = kat(4964:end)-offset;
% plot((0:(length(kat1))-1)/1000, kat1)
% % kat0 = kat0(486:end);
% figure(2)
% plot((0:(length(kat0))-1)/1000, kat0)

psi = 0.02;
K = 1;
T = 4;
%%
% figure(3)
% plot((0:(length(kat))-1)/1000, kat)


%----------------------------------------------------
X0 = [psi K,T];
%     psi K T     
options = optimoptions(@lsqnonlin,'Display','iter');
par = lsqnonlin(@cel_bez, X0, [0,0,0],[],options);

psi = par(1);
K = par(2);
T = par(3);
sim('model_bez',20)

%%
figure(100)
plot((0:20000)/1000, kat1(1:20001))
hold on
plot((0:20000)/1000, odp)

%%
close all
offset = 28.13;
psi = 0.0135;
K = 1;
T = 0.45;
sim('model_bez',20)
figure(1)
plot((0:20000)/1000, odp,'b')
hold on
offset = 27.13;
psi = 0.0125;
K = 1;
T = 0.4495;
sim('model_bez',20)
plot((0:20000)/1000, odp,'r')
grid on
legend('model','obiekt')
xlabel('czas [s]')
ylabel('po³o¿enie [^0]')