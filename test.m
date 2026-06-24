clc

load('Hm_frd_deliverable_P_smooth.mat');

Ts = discretized_system.Cz_retuned.Ts;
Hm_frd_smooth.Ts = Ts;

P = Hm_frd_smooth;

% Optimized controller parameters
K      = 28.481;
alpha  = 0.3741;
fc_lead = 326.04;          % Hz
tau_z  = 0.000798091;      % s
tau_p  = 0.000298566;      % s

% Continuous lead controller
C_lead_s = tf([tau_z 1], [tau_p 1]);

% Discretize controller using Tustin
C_lead_z = c2d(C_lead_s, Ts, 'tustin');

% Full controller
C_new = K * C_lead_z;

% Attach controller to plant
L_new = C_new * P;

% Plot margins
figure;
margin(L_new);
grid on;
title('Margin of Retuned Controller Attached to Smooth Plant');

% Compute margins
[Gm, Pm, Wcg, Wcp] = margin(L_new);

fprintf('\nMargins for new controller attached to plant:\n');
fprintf('PM = %.2f deg at %.2f Hz\n', Pm, Wcp/(2*pi));
fprintf('GM = %.2f dB\n', 20*log10(Gm));
fprintf('Gain crossover wc = %.2f rad/s\n', Wcp);
fprintf('Phase crossover wg = %.2f rad/s\n', Wcg);
