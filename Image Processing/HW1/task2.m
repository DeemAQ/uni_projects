% load the image
og_img = imread('mickey.jpg');
[rows, columns, no_color_channels] = size(og_img);

if no_color_channels > 1
    gray_image = rgb2gray(og_img);
else
    gray_image = og_img;
end

% create a new image
new_img = zeros(size(gray_image));

% loop over all rows and columns
for r = 1: size(gray_image, 1)
    for c = 1: size(gray_image, 2)
        % get the pixel value
        pxl = gray_image(r, c);
        % check if the value is less than 50 or more than 150 and assign new value
        if pxl < 50
            new_pxl = 0;
        elseif pxl > 150
            new_pxl = 255;
        else
            new_pxl = pxl;
        end
        % save new pixel value in the new image
        new_img(r, c) = new_pxl;
    end
end

tiledlayout(1, 2);
nexttile
imshow(gray_image);
nexttile
imshow(new_img);