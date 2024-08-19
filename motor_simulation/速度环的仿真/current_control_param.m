J = 0.00027;
B = 0.0004924;
R = 0.055;
L = 0.00007;

Torque_Load = 0.05;
Torque_motor = 1;

Wc = 600;
Ikp = Wc * L;
Iki =Ikp * R /L;
Wkp = J *20000;
Wki = 20000*Wkp/100;

