EPS=1.e-7;
rel=1;

n=input('m= ');%linii
m=input('n= ');%coloane

a=zeros(n,m);

if rel==1
    for i=1:n
        a(i,:)=input(' ');
    end
    rel=input('\nai introdus eronat? 1/0 ');
end
rel =1;

[u,s,v] = svd(a)
sv = diag(s); 
clear s; 

p=0;
tau=max(n,m)*sv(1)*EPS;
L=min(n,m);
z=zeros(L,1);
for i=1:L
   if sv(i)>=tau
       p=p+1;
       z(i)=1/sv(i);
   else
       sv(i)=0;
   end
end
p_matlab=rank(a);

fprintf("\n rang calculat matrice a: %g",p);
fprintf("\n rang calculat func?ie rank: %g", p_matlab);
format long e;
fprintf("\n valori singulare corectate: vector");
sv
fprintf("\n caracterizare matrice a: ");
if p~=L
   fprintf("deficienta de rang");
else
    fprintf("de rang complet");
end

b=zeros(n,1);
fprintf("\n");
if rel
    for i=1:n
        b(i)=input(' ');
    end
    rel=input('\nai introdus eronat? 1/0 ');
end
s1=diag(z(1:p));
x1=v(:,1:p)*s1*u(:,1:p)'*b;
s=diag(z);
x=v(:,1:L)*s*u(:,1:L)'*b;
x
x1
% x_matlab=pinv(a)*b;
% r=b-a*x;
% r_matlab=b-a*x_matlab;
% nrez=norm(r,2);
% nrez_matlab=norm(r_matlab,2);
% 
% fprintf("\n solu?ii calculate prin algoritm:\n");
% fprintf("x=%g, r=%g, nrez=%g\n",x,r,nrez);
% fprintf("\n solu?ii calculate apelând func?ii MATLAB:\n");
% fprintf("x_matlab=%g, r_matlab=%g, nrez_matlab=%g\n",x_matlab, r_matlab, nrez_matlab);

