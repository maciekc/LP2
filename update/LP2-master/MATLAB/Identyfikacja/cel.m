function wsk = cel( params )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    
   global data T
   K = params(1) * 0.4;
   Tm = params(2);
   t = 0:0.001:T;
   [y ,t] = step(tf(K, [Tm 1]), t);
   
   y_ref = data(100:(T*1000+100),2);
   wsk = 1e3 * (y - y_ref);
end

