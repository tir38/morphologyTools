function [output] = umbraOf(inputMap, resolution, paddingHeight)
% Jason Atwood
% 4/18/2012
%
% computes umbra of 2D input map (aka 'image')
%
% paddingHeight is absolute height (in units, not cells)

global verbose;

% get input map dimensionality
dimensions = size(inputMap);
dimensionality = size(dimensions);
maxHeightOfMap = max(max(inputMap));
maxHeightInCells = ceil(maxHeightOfMap /resolution); % convert height to number of cells (round up)

% NOT have a "zero" layer

% check dimensionality
if dimensionality ~= 2
    fprintf('ERROR: can not handle maps that are not 2D\n')
    return
end

% I might need to pad output "above" maxHeight with zeros.
if (exist('paddingHeight'))
    paddingHeightInCells = ceil(paddingHeight/resolution);
    
    if paddingHeightInCells < maxHeightInCells
        fprintf('ERROR: you are trying to pad below the actual height of the map')
        return
    else
        maxHeightInCells = paddingHeightInCells;
    end
end

% initialize output 3D matrix, fill with zeros
output = zeros([dimensions(1), dimensions(2), maxHeightInCells]);

% iterate through each element of inputMap and "fill in" all cells under it
for i = 1:dimensions(1)
    for j = 1: dimensions(2)
        
        heightInCells = ceil(inputMap(i,j) /resolution); % convert height to number of cells (round up)
        if heightInCells > 0
        
            for k = 1:heightInCells
                output(i,j,k) = 1;

                % add cell to plot
                if verbose == 1
                    corner = [i, j, k];
                    addBlock(corner, resolution, maxHeightInCells);
                    hold on; % must hold after addBlock for next plot
                    view(110,75); % set viewpoint, so that looks close to a imshow of the initial image
                end
            end
        end
    end
end
