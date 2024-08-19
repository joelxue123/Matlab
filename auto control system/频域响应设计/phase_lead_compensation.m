s = tf('s');
sysD = (s+1)/(s/10+1);
w = logspace(-1,2);
[mag,phase] = bode(sysD,w)
loglog(w,squeeze(mag)),grid;