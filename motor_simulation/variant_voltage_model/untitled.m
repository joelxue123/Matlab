J = 0.00027;
B = 0.0004924;
R = 0.1;
L = 0.00017;
flux = 0.066666;


W = 1000;
N = 1/L;
D = R/L;
kp = W/N;
ki =  D*W/N;

lambda = 2;

alpha0 =100;

Ts = 0.000050;

Ub  = 24*0.574;
Ib = 10;
Zb = Ub / Ib;
Wb =100;
Fb = Ub/Wb*Wb;
Fsmopos = exp(-R/L*Ts);
Gsmopos = (Ub/Ib)*(1-Fsmopos);
Kslide = 2000/65535;
Kslf = 5000/65535;
E0 = 65535/65535;


