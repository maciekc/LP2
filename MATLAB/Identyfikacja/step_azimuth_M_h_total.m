function error_total = step_azimuth_M_h_total(param, f_h, signals_ceil)
fs=1e3;

error_total=[];
for i=1:numel(signals_ceil)
    signals=signals_ceil{i};
    t_vect=(0:(length(signals)-1))/fs;

    [t,x]=ode45(@(t,x) ([x(2);-f_h*x(2)+polyval(param,signals(floor(t*fs)+1,1))]),t_vect,[0;0]);
    error=signals(:,2)-x(:,1);
    error_total=[error_total;error];
end

end

