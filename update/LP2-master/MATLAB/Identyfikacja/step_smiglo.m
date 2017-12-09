function error = step_smiglo(param, poly, signals)
fs=1e3;
t_vect=(0:(length(signals)-1))/fs;

[t,w]=ode45(@(t,w) (signals(floor(t*fs)+1,1)-polyval(poly,w/60))/param,t_vect,0);
error=signals(:,2)-w;

end