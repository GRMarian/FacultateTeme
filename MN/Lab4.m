while true
    EPS=1.e-10;
    
    n=0;
    while n<2
        n=input('n=');
    end
    
    a=zeros(n,n);
    b=zeros(n,1);
    while true
        fprintf("introdu a\n");
        while true
            for i=1:n
                fprintf('linia %g:',i);
                a(i,:) = input(' ');
            end
            if(input('1-continua 0-reintrodu datele\n'))
                break;
            end
        end
        while true
            fprintf("introdu b\n");
            while true
                for i=1:n
                    fprintf('linia %g:',i);
                    b(i,1) = input(' ');
                end
                if(input('1-continua 0-reintrodu datele\n'))
                    break;
                end
            end
            
            aa=a;
            bb=b;
            
            L=eye(n);
            E=eye(n);
            
            for k=1:n-1
                miu=zeros(n,1);
                if(abs(a(k,k))>EPS)
                    miu(k+1:n)=a(k+1:n,k)/a(k,k);
                    M=E-miu*E(:,k)';
                    Minv=E+miu*E(:,k)';
                    a=M*a;
                    b=M*b;
                    L=L*Minv;
                else
                    fprintf("pivot nul sau foarte mic\nSTOP:algoritm");
                    return;
                end
                k
                fprintf("Matricea de transformare la iteratia curenta:");
                M
                a
                b
            end
            fprintf("Matricea de transformare globala:");
            L
            
            for i=1:n
                if(abs(a(i,i))<EPS)
                    fprintf("matricea prost conditionata\n");
                end
            end
            b(n)=b(n)/a(n,n);
            for i=n-1:-1:1
                sum=a(i,i+1:n)*b(i+1:n);
                b(i)=(b(i)-sum)/a(i,i);
            end
            x=b;
            
            x_bs=aa\bb;
            x_inv=inv(aa)*bb;
            
            r=bb-aa*x;
            nr=norm(r,2);
            r_bs=bb-aa*x_bs;
            nr_bs=norm(r_bs,2);
            r_inv=b - aa*x_inv;
            nr_inv= norm(r_inv,2);
            
            format long e;
            
            nr
            nr_bs
            nr_inv
            if(input('\n0-Reluare program, daca se doreste, cu alt termen liber\n 1-nu\n'))
                break;
            end
            a=aa;
        end
        if(input('\n0-Reluare program, dac? se doreste, cu un sistem de alt ordin, n\n1-nu\n'))
            break;
        end
    end
    if(input('\n0-Reluare program, dac? se doreste, cu alt parametru EPS\n1-nu\n'))
        break;
    end
    EPS=input('\nintroduceti eps =');
end
