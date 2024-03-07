EPS=1.0e-20;
m=0;%linii
n=1;%coloane

while m<n
    n=input('n=');
    m=input('m=');
end

a=zeros(m,n);
for i=1:m
    fprintf("introduceti liniea a[%g]=",i);
    a(i,:)=input('');
end
aa=a;

u=zeros(m,n);
beta=zeros(n,1);
for k=1:n
    sum=sqrt(a(k:m,k)'*a(k:m,k));
    if( a(k,k)>=0)
        semn=1;
    else
        semn=-1;
    end
    sigma=semn*sum;
    u(k,k) =a(k,k) + sigma;
    u(k+1:m,k)= a(k+1:m,k);
    beta(k) = sigma*u(k,k);
    if ( abs(beta(k)) < EPS )
        fprintf( 'algoritmul va esua: beta < EPS');
    end
    a(k,k) = - sigma ;
    a(k+1:m,k) = zeros(m-k,1);
    for j = k+1:n
        sum= u(k:m,k)' * a(k:m,j);
        tau = sum/beta(k);
        a(k:m,j)= a(k:m,j) - tau*u(k:m,k);
    end
    k
    a
end

flag=0;
i=1;
while((i<=n)&&(flag==0))
    if  ( abs(a(i,i)) < EPS )
        flag=1;
    end
    i=i+1;
end
if(flag==1)
    fprintf('matrice deficienta de rang');
    rang=rank(a);
    rang
end

b=zeros(m,1);
fprintf("introduceti b\n");
for i=1:m
    b(i)=input('');
end
bb=b;

for k=1:n
    sum = u(k:m,k)' * b(k:m);
    taub = sum/beta(k) ;
    b(k:m) =b(k:m) - taub*u(k:m,k);
end
b

x=zeros(n,1);
x(n)= b(n)/a(n,n);
for i=n-1:-1:1
    sum = a(i,i+1:n)*x(i+1:n);
    x(i) = (b(i) - sum)/a(i,i);
end

b(1:n)=zeros(n,1);
for k=n:-1:1
    sum = (u(k:m,k))' * b(k:m);
     taud = sum/beta(k);
     b(k:m) = b(k:m) - taud*u(k:m,k);
end
nr=norm(b,2);

 x_bs = aa\bb;
 r_bs = bb - aa*x_bs;
 nr_bs = norm(r_bs,2);

x
b
nr
x_bs
r_bs
nr_bs
