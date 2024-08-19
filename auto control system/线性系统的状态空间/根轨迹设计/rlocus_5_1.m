
num = 1; % 分子多项式系数
den = [1,1,0];     % 分母多项式系数
sys = tf(num, den)
rlocus(sys)