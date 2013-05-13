function [] = addBlock(corner, resolution, maxHeightInCells)
%
% performs several fill3 commands to create a block in the current plot
%
% to test:
% addBlock([0,0,0],1,2) 

i = corner(1);
j = corner(2);
k = corner(3);

% set block color
heightPercentage = (k+1)/(maxHeightInCells+2);
color = [heightPercentage, heightPercentage, heightPercentage]; % greyscal intensity is dependent on height of block

% bottom
x = [i, i+resolution, i+resolution, i];
y = [j, j, j+resolution, j+resolution];
z = [k k k k];
fill3(x,y,z,color);
hold on

%top
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
