clc;
clear all;
close all;

og_img = imread('two_cats.jpg');
[rows, cols] = size(og_img);
subplot(2, 2, 1), imshow(og_img), title("original image");

PQ = paddedsize([rows, cols]);
FT_img = fft2(double(og_img), PQ(1), PQ(2));


h = fspecial('sobel');
FT_h = fft2(double(h), PQ(1), PQ(2));
f_img_h = FT_h.*FT_img;
ffi_h = ifft2(f_img_h);
h_edge = ffi_h(2:rows+1, 2:cols+1); % horizontal edge
subplot(2, 2, 2), imshow(h_edge, []), title("horizontal edge");


v = fspecial('sobel')';
FT_v = fft2(double(v), PQ(1), PQ(2));
f_img_v = FT_v.*FT_img;
ffi_v = ifft2(f_img_v); 
v_edge = ffi_v(2:rows+1, 2:cols+1); % vertical edge
subplot(2, 2, 3), imshow(v_edge, []), title("vertical edge");


result = h_edge + v_edge;
subplot(2, 2, 4), imshow(result, []), title("result");


