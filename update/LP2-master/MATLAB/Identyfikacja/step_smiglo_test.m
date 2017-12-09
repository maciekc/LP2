function error = step_smiglo_test(param, poly, signals)
fs=1e3;
t_vect=(0:(length(signals)-1))/fs;

[t,w]=ode45(@(t,w) (signals(floor(t*fs)+1,1)-polyval(poly,w))/param,t_vect,0);
error=signals(:,2)-w;

end