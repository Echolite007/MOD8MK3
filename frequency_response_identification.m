%% Deliverable P - Frequency Response Identification
% Assumes:
% simout.signals.values(:,1) = actuator voltage input [V]
% simout.signals.values(:,2) = measured mirror angle [rad]

close all; clc;

%% Checks
if ~exist('ts','var')
    error('Sample time ts is not defined. Run initialization first.');
end

if ~exist('T','var')
    error('Period time T is not defined. Run initialization first.');
end

if ~exist('simout','var')
    error('Simulation output simout not available. Run the Simulink experiment first.');
end

%% Extract data
t = simout.time;
u = simout.signals.values(:,1);   % input voltage [V]
y = simout.signals.values(:,2);   % output angle [rad]

% Remove first sample
t = t(2:end);
u = u(2:end);
y = y(2:end);

%% Select signal type
% Use same convention as initialization:
% inputType = 0 -> multisine
% inputType = 1 -> chirp
if ~exist('inputType','var')
    warning('inputType not found. Assuming multisine.');
    inputType = 0;
end

%% Basic frequency settings
fs = 1/ts;             % sampling frequency [Hz]
fNyq = fs/2;           % Nyquist frequency [Hz]

%% Process data
if inputType == 0
    %% Multisine processing with period averaging

    N = round(T/ts);               % samples per period
    Nr = floor(length(u)/N);       % number of complete periods

    if Nr < 1
        error('Not enough data for one full period. Increase simulation time Ttot.');
    end

    % Keep only complete periods at the end of the measurement
    u = u(end+1-Nr*N:end);
    y = y(end+1-Nr*N:end);
    t = t(end+1-Nr*N:end);

    ur_all = reshape(u,N,[]);
    yr_all = reshape(y,N,[]);

    % Plot all periods to inspect transient behavior
    figure;
    subplot(2,1,1)
    plot((0:N-1)*ts, ur_all');
    grid on
    xlabel('Time in period [s]');
    ylabel('Voltage [V]');
    title('Input voltage per period');

    subplot(2,1,2)
    plot((0:N-1)*ts, yr_all');
    grid on
    xlabel('Time in period [s]');
    ylabel('Angle [rad]');
    title('Measured angle per period');

    % Choose periods after transients
    % Default: use second half of periods
    chosenPeriods = ceil(Nr/2):Nr;

    ur = mean(ur_all(:,chosenPeriods),2);
    yr = mean(yr_all(:,chosenPeriods),2);

    fResolution = 1/T;
    fgrid = (0:N-1)' * fResolution;

else
    %% Chirp processing without period averaging

    ur = u;
    yr = y;

    N = length(ur);
    fResolution = fs/N;
    fgrid = (0:N-1)' * fResolution;
end

%% FFT
uf = fft(ur);
yf = fft(yr);

%% Use only positive frequencies up to Nyquist
valid = fgrid > 0 & fgrid <= fNyq;

fgrid_pos = fgrid(valid);
uf_pos = uf(valid);
yf_pos = yf(valid);

%% Select excited frequencies
% Threshold removes frequencies where input is almost zero/noise.
threshold = 0.01 * max(abs(uf_pos));
ind = abs(uf_pos) > threshold;

f_meas = fgrid_pos(ind);
Hm = yf_pos(ind) ./ uf_pos(ind);

%% Create FRD object
Hm_frd = frd(Hm, 2*pi*f_meas);

%% Save result
save('Hm_frd_deliverable_P.mat','Hm_frd','f_meas','Hm','ts','T','inputType');

%% Plot FFT magnitudes
figure;
subplot(1,2,1)
loglog(fgrid_pos, abs(uf_pos));
grid on
xlabel('Frequency [Hz]');
ylabel('|U(f)|');
title('FFT of input voltage');

subplot(1,2,2)
loglog(fgrid_pos, abs(yf_pos));
grid on
xlabel('Frequency [Hz]');
ylabel('|Y(f)|');
title('FFT of measured angle');

%% Bode plot of measured frequency response
figure;
opts = bodeoptions;
opts.FreqUnits = 'Hz';
opts.XLim = [min(f_meas) max(f_meas)];
opts.PhaseWrapping = 'off';

bodeplot(Hm_frd,'r.',opts);
grid on
title('Measured frequency response: angle / voltage');

load('simulated_TF.mat')

He = delGHI.sysem;

%% Optional: overlay model if available
% Define your model as He before running this section, for example:
% He = sys_voltage_to_angle;
if exist('He','var') && ~isempty(He)
    hold on
    bodeplot(He,opts);
    legend('Measured FRF','Model');
else
    legend('Measured FRF');
end

%% Print summary
fprintf('\nDeliverable P identification complete.\n');
fprintf('Sample time ts      = %.6g s\n', ts);
fprintf('Sampling frequency  = %.3f Hz\n', fs);
fprintf('Nyquist frequency   = %.3f Hz\n', fNyq);
fprintf('Frequency resolution = %.3f Hz\n', fResolution);
fprintf('Number of FRF points = %d\n', length(f_meas));
fprintf('Saved file: Hm_frd_deliverable_P.mat\n');


