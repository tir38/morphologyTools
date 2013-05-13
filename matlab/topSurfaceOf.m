function [output] = topSurfaceOf(inputUmbra, resolution)
% Jason Atwood
% 4/18/2012
%
% computes top surface of 3D umbra (of 2D surface)

% get input umbra dimensionality
dimensions = size(inputUmbra);
[~, dimensionality] = size(dimensions);

% check dimensionality
if ~((dimensionality == 2) || (dimensionality == 3)) % 2D umbra may just be 3D umbra with one level
    fprintf('ERROR: can not handle umbras that are not 3D\n')
    return
end

output = zeros(dimensions(1), dimensions(2));

% sum "down" each column of the umbra
for (i = 1:dimensions(1))
    for (j = 1: dimensions(2))

        output(i,j) = sum(inputUmbra(i,j,:)>0.1)  * resolution;  % counts number of cells w/ value greater than 0.1 threashold
    end
end
