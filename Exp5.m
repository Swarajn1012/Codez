m = 0; 
sd = 1;
x = -6:0.1:6; 
y = normpdf(x,m,sd); 
figure(1)
subplot(2,3,1)
plot(x,y) 
axis([-6 6 0 1]); 
title('CASE-1: mean=0, std dev=1');
xlabel('x values----->');
ylabel('PDF----->');
grid on;

m = 1; 
sd = 1; 
x = -6:0.1:6;
y = normpdf(x,m,sd);
figure(2) 
subplot(2,3,1) 
plot(x,y)
axis([-6 6 0 1]); 
title('CASE-2: mean=1, std dev=1');
xlabel('x values----->');
ylabel('PDF----->');
grid on;

m = -1;
sd = 1;
x = -6:0.1:6; 
y = normpdf(x,m,sd); 
figure(3) 
subplot(2,3,1) 
plot(x,y) 
axis([-6 6 0 1]); 
title('CASE-3: mean=-1, std dev=1');
xlabel('x values----->');
ylabel('PDF----->');
grid on;