function error_total = step_azimuth_total(param, signals_ceil)
fs=1e3;

error_total=[];
for i=1:numel(signals_ceil)
    signals=signals_ceil{i};
    t_vect=(0:(length(signals)-1))/fs;

    [t,x]=ode45(@(t,x) ([x(2);-param(1)*x(2)+polyval(param(2:end),signals(floor(t*fs)+1,1)/60)]),t_vect,[0;0]);
    error=signals(:,2)-x(:,1);
    error_total=[error_total;error];
end

end

