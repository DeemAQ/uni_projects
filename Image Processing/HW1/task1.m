% load the image
og_img = imread('mickey.jpg');
[rows, columns, no_color_channels] = size(og_img);

if no_color_channels > 1
    gray_image = rgb2gray(og_img);
else
    gray_image = og_img;
end

% flips the rows, making an upside down image
flipped_img = flipdim(gray_image, 1);

tiledlayout(1, 2);
nexttile
imshow(og_img);
nexttile
imshow(flipped_img);