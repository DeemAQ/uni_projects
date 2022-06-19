clc;
clear all;
close all;

img = imread('halftone.png');
figure, imshow(img), title('original image');

PQ = 2*size(img);
types = ["btw", "gaussian", "ideal"];
a = 200;
b = 133;
width = 100; % try it with 100, 200, 300

nArr = createArrays(49, [PQ(1) PQ(2)]);
o = 1;
for t = 1:length(types)
    for i = 1:9
        for j = 1:5
            if(mod(i, 2) == 0)
                nArr{o} = notch(types(t), 'high', PQ(1), PQ(2), width, a*i, b*((j-1)*2));
            else
                nArr{o} = notch(types(t), 'high', PQ(1), PQ(2), width, a*i, b*((j*2)-1));
            end
            o = o + 1;
        end
    end
    
    nArr{46} = notch(types(t), 'high', PQ(1), PQ(2), width, a*0, b*2);
    nArr{47} = notch(types(t), 'high', PQ(1), PQ(2), width, a*0, b*4);
    nArr{48} = notch(types(t), 'high', PQ(1), PQ(2), width, a*0, b*6);
    nArr{49} = notch(types(t), 'high', PQ(1), PQ(2), width, a*0, b*8);
    
    F = fft2(double(img),PQ(1),PQ(2));
    
    asd = nArr{1};
    for i = 2:49
        asd = asd.*nArr{i};
    end
    F_asd = fftshift(asd);
    S0 = log(1+abs(F_asd));
    
    FS_img = F.*asd;
    F_img = real(ifft2(FS_img)); 
    F_img = F_img(1:size(img,1), 1:size(img,2));
    
    figure, imshow(F_img,[]), title(strcat('notch filtered image -', types(t)));
end