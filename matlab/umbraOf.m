function [umbra] = umbraOf(image, resolution, verbose, paddingHeight)
% Jason Atwood
% 4/18/2012
%
% usage:
% [umbra] = umbraOf(image, resolution, verbose, paddingHeight)
%
% description:
% Computes the umbra of a image (2D matrix). User can specify height
% resolution (doesn't need to be same resolution as x,y dimesions of the
% image). Can also pad above the largest "peak" with zeros creating an
% umbra with z dimension greater than largest pixel intensity.
% 
% If plotting, this method requires that the calling method has already set
% the current figure window.
%
% inputs:
% - image           : [m x n] matrix of non-negative integers; input image
% - resolution      : integer, sets the z resolution of the umbra
% - verbose         : 0 or 1 determines plotting options: 0 = plotting off; 1 = plotting on 
% - paddingHeight   : non-negative integer, desired max z dimension. For
%                       padding above the umbra with zereos. 
%
% outputs:
% - umbra : [m x n x p] matrix of 0 or 1; 
%               where p = max(paddingHeight, maxHeightOfMap) * resolution
%
% subfuctions:
% addBlock by Jason Atwood

%% ========== code ===========
% get input image dimensionality
dimensions = size(image);
dimensionality = size(dimensions);
maxHeightOfMap = max(max(image));
maxHeightInCells = ceil(maxHeightOfMap /resolution); % convert height to number of cells (round up)

% check dimensionality
if dimensionality ~= 2
    fprintf('ERROR: can not handle maps that are not 2D\n')
    return
end

% pad umbra upto maxHeight with zeros.
if (exist('paddingHeight'))
    paddingHeightInCells = ceil(paddingHeight/resolution);
    
    if paddingHeightInCells < maxHeightInCells
        fprintf('ERROR: you are trying to pad below the actual height of the map')
        return
    else
        maxHeightInCells = paddingHeightInCells;
    end
end

% initialize umbra 3D matrix, fill with zeros
umbra = zeros([dimensions(1), dimensions(2), maxHeightInCells]);

% iterate through each element of image and "fill in" all cells under it
for i = 1:dimensions(1)
    for j = 1: dimensions(2)
        
        heightInCells = ceil(image(i,j) /resolution); % convert height to number of cells (round up)
        if heightInCells > 0
        
            for k = 1:heightInCells
                umbra(i,j,k) = 1;

                % add cell to plot
                if verbose == 1
                    corner = [i, j, k];
                    % set block color
                    heightPercentage = (k+1)/(maxHeightInCells+2);
                    color = [heightPercentage, heightPercentage, heightPercentage]; % greyscal intensity is dependent on height of block
                    addBlock(corner, resolution, color);
                    hold on; % must hold after addBlock for next plot
                    view(110,75); % set viewpoint, so that looks close to a imshow of the initial image
                end
            end
        end
    end
end
