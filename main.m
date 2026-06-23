clear; clc; close all 

% SPACAR Path 
addpath('spacar');
addpath('spacar\spalight-1.38');

% Load parameters 
params = parameters(); 

% Load reference 
ref = reference(params.spec.driving_speed_nom_mps, params.spec.weeding_time_s, params.spec.return_time_s, 1e-4);

% Nominal plant sizing - Deliverable b 
nominal_plant_sizing = nominal_plant_sizing(params, ref);

% Store nominal plant sizes in params structure under mech
params.mech.r_arm_m       = nominal_plant_sizing.r_arm_m;
params.mech.J_kgm2        = nominal_plant_sizing.J_kgm2;
params.mech.k_Nm_per_rad  = nominal_plant_sizing.k_Nm_per_rad;
params.mech.d_Nms_per_rad = nominal_plant_sizing.d_Nms_per_rad;

% Define Laplace variable s
s_var = tf('s');

% Nominal Continuous plant: Voltage to Mirror Angle 
P_nom = (params.mech.r_arm_m * params.actuator.Kf_N_per_A / params.actuator.R25_ohm) / ...
    (params.mech.J_kgm2 * s_var^2 + params.mech.d_Nms_per_rad * s_var + params.mech.k_Nm_per_rad);

% Controller design 
controller_design = controller_design(params, nominal_plant_sizing, ref);

% Simulation output
spacar_sim_out = simulation(params, nominal_plant_sizing, controller_design);

% Discretization 
discretized_system = discretisation(params, controller_design, spacar_sim_out);

% Simulink parameters 
ts = 5e-4;
r_sensor = 0.052;