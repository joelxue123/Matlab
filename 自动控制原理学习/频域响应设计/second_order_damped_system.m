w0 =1;
damped =1;

s = tf('s');
sysD= 1 /( (s/w0)^2 + 2*damped*(s/w0) +1 )

damped =0.5;
sysD2= 1 /( (s/w0)^2 + 2*damped*(s/w0) +1 )

damped =0.1;
sysD3= 1 /( (s/w0)^2 + 2*damped*(s/w0) +1 )


damped =0.05;
sysD4= 1 /( (s/w0)^2 + 2*damped*(s/w0) +1 )


bode(sysD,sysD2,sysD3,sysD4)