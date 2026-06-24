load('Hm_frd_deliverable_P_smooth.mat');

Hm_frd_smooth.Ts = discretized_system.Cz_retuned.Ts;

L_smooth = discretized_system.Cz_retuned * Hm_frd_smooth;

figure;
margin(L_smooth);
grid on;

[Gm, Pm, Wcg, Wcp] = margin(L_smooth);
fprintf('PM = %.2f deg at %.2f Hz\n', Pm, Wcp/(2*pi));
fprintf('GM = %.2f dB\n', 20*log10(Gm));