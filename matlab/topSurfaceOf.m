function [topSurface] = topSurfaceOf(inputUmbra, resolution)
% Jason Atwood
% 4/18/2012
%
% usage:
% [topSurface] = topSurfaceOf(inputUmbra, resolution)%
%
% description:
% Computes the top surface of an input umbra. User needs to specify the
% resolution used in creating the umbra.
%
% inputs:
% - umbra       : [m x n x p] matrix of non-negative integers; input umbra
% - resolution  : integer, sets the z resolution of the umbra
%
% outputs:
% - topSurface : [m x n] matrix of integers;

%% ========== code ===========
% get input umbra dimensionality
dimensions = size(inputUmbra);
[~, dimensionality] = size(dimensions);

% check dimensionality
if ~((dimensionality == 2) || (dimensionality == 3)) % 2D umbra may just be 3D umbra with one level
    fprintf('ERROR: can not handle umbras that are not 3D\n')
    return
end

topSurface = zeros(dimensions(1), dimensions(2));

% sum "down" each column of the umbra
for (i = 1:dimensions(1))
    for (j = 1: dimensions(2))

        topSurface(i,j) = sum(inputUmbra(i,j,:)>0.1)  * resolution;  % counts number of cells w/ value greater than 0.1 threashold
    end
end
