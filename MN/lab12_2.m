global A B U

n=2;

k=input('coeficient de elasticitate -> ');
m=input('masa corpului -> ');
r=input('coeficient de frecare -> ');

A=[0 1;-k/m -r/m];
B=[0 ; 1/m ];

omega=sqrt(k/m);
Tn=2*pi/omega;

amortizare=r/(2*omega)/m;

U=input(' intrare în sistem -> ');

x=zeros(1,n);

for i=1:n
   i;
   x(1,i)=input(' -> ');
end


Hobs=input('citire durat? simulare -> ');

t0=0;
Tstart=t0;
Tstop=Tstart+Hobs;

amortizare

[ Tout, Xout ] = ode23 ( 'FCU' , [Tstart, Tstop], x);

Np=length(Tout);
fprintf("=> numar elemente solutie = %g",Np);

plot(Tout,Xout(:,1),'--');
hold on;
plot(Tout,Xout(:,2),'--');

