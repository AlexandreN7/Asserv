clear all;

toto=importdata('data.txt')
hold on;
x = linspace(0,2);
plot(toto(:,1))
plot(toto(:,2))
