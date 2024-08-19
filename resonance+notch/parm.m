Kt = 0.985;
Jm = 0.0014;
Jl= 0.0028;

Ks = 372;
Kcv = 0.008;

WC = 30000;
KVP = WC * Jm;
KVI = KVP * WC / 1000000;

pu = 6553

diff_p = 1.688*pu/3.3
diff_n = 1.688*pu/3.3

diff_p_p500 = 1.529* pu/3.3
diff_p_n500 = 1.851 * pu/3.3
diff_p_dp500 = diff_p_p500 -diff_p 
diff_p_dn500 = diff_p_n500 -diff_p 
diff_p_d1000 = diff_p_p500 -diff_p_n500 


diff_n_p500 = 1.830 *pu/3.3
diff_n_n500 = 1.480 * pu/3.3
diff_n_dp500 = diff_n_p500 -diff_n 
diff_n_dn500 = diff_n_n500 -diff_n 
diff_n_d1000 = diff_n_p500 -diff_n_n500 


diffpn_p500 = diff_p_p500 - diff_n_p500
diffpn_n500 = diff_p_n500 - diff_n_n500