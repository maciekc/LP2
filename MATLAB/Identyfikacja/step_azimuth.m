function error = step_azimuth(param, signals)
fs=1e3;
t_vect=(0:(length(signals)-1))/fs;

[t,x]=ode45(@(t,x) ([x(2);-param(1)*x(2)+param(2)]),t_vect,[0;0]);
error=signals(:,2)-x(:,1);

end

