clc
close all

%% setup
% get user's screen size
screen_size = get(0, 'ScreenSize');
morphologyResolution = 1; 
verbose = 1; % turns on or off plotting of umbra; 

%% create image
imageDimension = 25;
image = zeros(imageDimension, imageDimension);
image(8:18,8:12) = 1;
image(9:13,9:11) = 2;
imageMax = max(max(image));

% plot image
figure(1)
imshow(image, [0, imageMax], 'InitialMagnification', 'fit')
title('image')
hold off


%% compute umbra of image
figure(2) % MUST HAVE CURRENT PLOT SET BEFORE CALLING umbraOf
umbra = umbraOf(image, morphologyResolution, verbose); % compute umbra
hold on

% update plot
xlim([1,imageDimension+1])
ylim([1, imageDimension+1])
title('umbra of image')
grid on
colorbar('off')
hold off


%% compute top surface of umbra
figure(3)
topSurface = topSurfaceOf(umbra, morphologyResolution);

% plot top surface
imshow(topSurface, [0, max(max(topSurface))],  'InitialMagnification', 'fit'); % display image; scale to show entire range
title('top surface of umbra')