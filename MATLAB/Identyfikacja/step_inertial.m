function error = step_inertial(param, a, signals)
fs=1e3;
t_vect=(0:(length(signals)-1))/fs;

[t,x]=ode45(@(t,x) ([x(2);a/param(1)*sin(x(1)-param(3))-param(2)/param(1)*x(2)]),t_vect,[signals(1);0]);
error=signals-x(:,1);

end