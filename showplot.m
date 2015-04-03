load rand_1_3.txt -ascii
load rand_2_4.txt -ascii
load xfile.txt -ascii
load yfile.txt -ascii

R1 = rand_1_3;
R2 = rand_2_4;
X = xfile;
Y = yfile;
v = size(Y);
%N+1
N = v(1);
%M+1
M = v(2);

%full grid:
for i=1:N
   plot(X(i,:),Y(i,:),'b')
   hold on
end
for i=1:M
   plot(X(:,i),Y(:,i),'b')
end

%boundary points:
plot(R1(:,1), R1(:,2),'k*', R1(:,3), R1(:,4),'k*')
plot(R2(:,1), R2(:,2),'k*', R2(:,3), R2(:,4),'k*')

str = sprintf('Domain, %i X %i', N, M);
title(str)
axis([-11 6 -1 4]);
