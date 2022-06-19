clc;
close all;

og_img = imread('coins.png');
og_img = im2gray(og_img);

% display grayscale image
subplot(2, 1, 1);
imshow(og_img);
title('grayscale image');

% threshold the image
threshold_val = 100;
binary_img = og_img > threshold_val; % chooses bright areas only

% fill holes
binary_img = imfill(binary_img, 'holes');
[labeled_img, ~] = bwlabel(binary_img); % label each circle to take measurements of it

% give the circles random colours
coloured_labels = label2rgb (labeled_img, 'hsv', 'k', 'shuffle');
subplot(2, 1, 2);
imshow(coloured_labels);
title('coloured labels');

% get all properties
props = regionprops(labeled_img, og_img, 'all');
num_circles = numel(props);

boundaries = bwboundaries(binary_img);
num_boundaries = size(boundaries, 1); % count the number of boundaries

hold on;
for k = 1 : num_boundaries
	this_boundary = boundaries{k};
	x = this_boundary(:,2);
	y = this_boundary(:,1);
	plot(x, y, 'w-', 'LineWidth', 2);
end
hold off;

all_centroids = vertcat(props.Centroid);
centroidsX = all_centroids(:, 1);
centroidsY = all_centroids(:, 2);

% circles are numbered top to bottom, left to right
subplot(2, 1, 2);
for k = 1 : num_circles
	% place the number
	text(centroidsX(k), centroidsY(k), num2str(k), 'FontSize', 15, 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
end
