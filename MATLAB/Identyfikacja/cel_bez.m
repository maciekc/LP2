function wsk = cel_bez( params )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    
   global data T kat1  
   offset = 28.13;
   Tk = 20;
   psi = params(1);
   K = params(2);
   T = params(3);
   opt = simset('SrcWorkspace','Current');
   sim('model_bez',Tk,opt);

    wsk = kat1(1:Tk*1000+1) - odp;
end
