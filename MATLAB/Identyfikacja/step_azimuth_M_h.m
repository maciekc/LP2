function error = step_azimuth_M_h(param, f_h, signals)
fs=1e3;
t_vect=(0:(length(signals)-1))/fs;

[t,x]=ode45(@(t,x) ([x(2);-f_h*x(2)+polyval(param,signals(floor(t*fs)+1,1))]),t_vect,[0;0]);
error=signals(:,2)-x(:,1);

end

