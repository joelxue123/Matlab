% 定义采样频率和信号的基本参数
fs = 1000000; % 采样频率为 1000 Hz
T = 1; % 信号周期为 1 秒
f0 = 5; % 信号频率为 5 Hz
N = 1000; % 信号点数
t = 0:(1/fs):T-(1/fs); % 时间向量

% 生成余弦和正弦信号
cos_signal = cos(2*pi*f0*t);
sin_signal = sin(2*pi*f0*t);

% 对信号进行 FFT
fft_cos = fft(cos_signal);
fft_sin = fft(sin_signal);

% 计算频率轴（只取正频率部分）
n = length(t);
f = (0:n-1)*(fs/n);

% 计算 FFT 的幅度和相位
fft_cos_magnitude = abs(fft_cos)/n;
fft_sin_magnitude = abs(fft_sin)/n;
fft_cos_phase = rad2deg(angle(fft_cos)); % 将相位转换为度
fft_sin_phase = rad2deg(angle(fft_sin)); % 将相位转换为度

% 选择基频处的幅度和相位进行显示
index_f0 = find(f == f0); % 找到基频的索引

% 显示结果
fprintf('Cosine FFT magnitude at %d Hz: %f\n', f0, fft_cos_magnitude(index_f0));
fprintf('Cosine FFT phase at %d Hz (degrees): %f\n', f0, fft_cos_phase(index_f0));
fprintf('Sine FFT magnitude at %d Hz: %f\n', f0, fft_sin_magnitude(index_f0));
fprintf('Sine FFT phase at %d Hz (degrees): %f\n', f0, fft_sin_phase(index_f0));

% 如果需要，可以绘制幅度和相位谱
figure;
subplot(2,1,1);
plot(f, fft_cos_magnitude, 'b', f, fft_sin_magnitude, 'r');
title('Frequency Spectrum Magnitude');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
legend('Cosine', 'Sine');

subplot(2,1,2);
plot(f, fft_cos_phase, 'b', f, fft_sin_phase, 'r');
title('Phase Spectrum (degrees)');
xlabel('Frequency (Hz)');
ylabel('Phase (degrees)');
legend('Cosine', 'Sine');
grid on;