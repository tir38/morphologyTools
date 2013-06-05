function [] = addBlock(corner, resolution, color)
% Jason Atwood
% 4/18/2012
%
% usage:
% [] = addBlock(corner, resolution, maxHeightInCells)
%
% description:
% Performs several fill3 commands to create a block in the current plot. 
% This method requires that the calling method has already set
% the current figure window.
%
% inputs:
% - corner      : [3 x 1] vector containing bottom, left, front corner dimension
%                   of block to plot
% - resolution  : integer, sets the z resolution of the block
% - color       : [3 x 1] vector containing RGB values to set color of block


%% ========== code ===========
i = corner(1);
j = corner(2);
k = corner(3);

% bottom
x = [i, i+resolution, i+resolution, i];
y = [j, j, j+resolution, j+resolution];
z = [k k k k];
fill3(x,y,z,color);
hold on

% top
x = [i, i+resolution, i+resolution, i];
y = [j, j, j+resolution, j+resolution];
z = [k+resolution, k+resolution, k+resolution, k+resolution];
fill3(x,y,z,color);
hold on

% front
x = [i+resolution, i+resolution, i+resolution, i+resolution];
y = [j, j, j+resolution, j+resolution];
z = [k, k+resolution, k+resolution, k];
fill3(x,y,z,color);
hold on

% back
x = [i, i, i, i];
y = [j, j, j+resolution, j+resolution];
z = [k, k+resolution, k+resolution, k];
fill3(x,y,z,color);
hold on

% left
x = [i, i, i+resolution, i+resolution];
y = [j, j, j, j];
z = [k, k+resolution, k+resolution, k];
fill3(x,y,z,color);
hold on

% right
x = [i, i, i+resolution, i+resolution];
y = [j+resolution, j+resolution, j+resolution, j+resolution];
z = [k, k+resolution, k+resolution, k];
fill3(x,y,z,color);
hold on
