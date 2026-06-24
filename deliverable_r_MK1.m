clc;
close all;

%% Load Hm_FRD
load('Hm_frd_deliverable_P.mat');   

%% Discrete Controller
Cz = discretized_system.Cz_tustin;

%% Set sampling time to be the same
Ts = Cz.Ts;
Hm_frd.Ts = Ts;

%% Open-loop measured plant with discrete controller
L = Cz * Hm_frd;

%% Stability margins
figure;
margin(L);
grid on;
title('Deliverable R: measured open-loop stability margins');

[Gm, Pm, Wcg, Wcp] = margin(L);

fc = Wcp/(2*pi);

if isinf(Gm)
    GM_dB = Inf;
else
    GM_dB = 20*log10(Gm);
end

%% Store results
delR = struct();

delR.Ts = Ts;
delR.fs_Hz = 1/Ts;
delR.Hm_frd = Hm_frd;
delR.Cz = Cz;
delR.L = L;

delR.gain_margin = Gm;
delR.gain_margin_dB = GM_dB;
delR.phase_margin_deg = Pm;
delR.gain_crossing_rad_s = Wcp;
delR.gain_crossing_Hz = fc;
delR.phase_crossing_rad_s = Wcg;
delR.phase_crossing_Hz = Wcg/(2*pi);

save('deliverable_R_results.mat','delR');

%% Print summary
fprintf('\n=== Deliverable R: measured open-loop margins ===\n');
fprintf('Sample time Ts          = %.6g s\n', Ts);
fprintf('Sampling frequency      = %.3f Hz\n', 1/Ts);
fprintf('Crossover frequency     = %.3f Hz\n', fc);
fprintf('Phase margin            = %.2f deg\n', Pm);

if isinf(GM_dB)
    fprintf('Gain margin             = Inf dB\n');
else
    fprintf('Gain margin             = %.2f dB\n', GM_dB);
end

fprintf('Saved file: deliverable_R_results.mat\n');