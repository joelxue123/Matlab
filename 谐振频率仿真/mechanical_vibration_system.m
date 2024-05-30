% 定义系统参数
m = 0.02;      % 质量，单位：kg
k = 1000;      % 弹簧常数，单位：N/m
c = 2;    % 阻尼系数，单位：N·s/m

% 调用函数计算阻尼比
zeta =  c / (2 * sqrt(m * k));
vibration_freq = sqrt(k/m ) / (2*pi);

% 显示结果
fprintf('谐振频率f = %f\n', vibration_freq);
fprintf('阻尼比 ζ = %f\n', zeta);