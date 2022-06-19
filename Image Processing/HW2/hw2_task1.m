% read the image and convert it to double
clc;
close all;
clear all;


og_img = imread('97.jpg');
[rows, columns] = size(og_img);
four_trans = fft2(im2double(og_img));


% filter design:
D0_lp = 20; % cutoff for lowpass filter
D0_hp = 10; % cutoff for highpass filter
n = 2; % order
u = 0:(rows-1);
idx = find(u > rows/2);
u(idx) = u(idx) - rows;

v = 0:(columns-1);
idy = find(v > columns/2);
v(idy) = v(idy) - columns;

[V, U] = meshgrid(v, u);

% Euclidean distance:
D = sqrt(U.^2 + V.^2);
H_lp = 1./(1 + (D./D0_lp).^(2*n)); % filtering mask for lowpass
H_hp = 1./(1 + (D0_hp./D).^(2*n));

% lowpass:
G_lp = H_lp.*four_trans;
lowpass_img = real(ifft2(double(G_lp)));

% highpass:
G_hp = H_hp.*four_trans;
highpass_img = real(ifft2(double(G_hp)));

FT = fftshift(four_trans);
FT = log(FT);

% figures:
tiledlayout(2, 2);
nexttile
imshow(og_img, []), title('original image');
nexttile
imshow(FT, []), title('Fourier Transformation');
nexttile
imshow(lowpass_img, []), title('lowpass filter');
nexttile
imshow(highpass_img, []), title('highpass filter');