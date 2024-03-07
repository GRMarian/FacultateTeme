
clear all;
clc;

reluare_5=1;
reluare_4=1;
reluare_3=1;
reluare_2=1;
alta_adaptare == 1

eps=1.0e-7;
max_iter=30;

while reluare_2==1
    n=0;
    while n<2
        n=input('n>=2\nn=');
    end
    
    while reluare_3==1
        a=zeros(n,n);
        
        obs=1;
        while obs
            for i=1:n
                fprintf("introduceti liniea a[%g]=",i);
                a(i,:)=input('');
            end
            
            obs=0;
            for i=1:n
                if(abs(a(i,i))<eps)
                    fprintf('element pe diagonala nul sau foarte mic\nRearanjati si reintroduceti A');
                    obs=1;
                    break;
                end
            end
        end
        while reluare_4==1
            b=zeros(n,1);
            
            for j=1:n
                fprintf("introduceti termenul de pe pozitia b[%g]=",j);
                b(j,1)=input('');
            end
            
            while reluare_5 == 1
                xn=zeros(n,1);
                obs_xn=input('\nvrei xn=0? 0/1->');
                if obs_xn==0
                    for j=1:n
                        fprintf("introduceti termenul de pe pozitia xn[%g]=",j);
                        xn(j,1)=input('');
                    end
                end
                
                nn=diag(diag(a));
                p=nn-a;
                g=inv(nn)*p;
                valp=eig(g);
                ro=max(abs(valp));
                
                fprintf('raza spectrala matrice convergenta, ro=%g',ro);
                
                if ro<1
                    fprintf(' metoda converge !');
                else
                    fprintf(' metoda nu converge !!!');
                end
                
                vnif=1;
                iter=0;
                format long e;
                while alta_adaptare == 1
                    adaptare=input('adaptare JACOBI=1 GAUSS-SEIDEL=0 ->');
                    while((vnif>eps)&&(iter<max_iter))
                        iter=iter+1;
                        %xv=zeros(n,1);
                        xv=xn;
                        if adaptare
                            %adaptare JACOBI
                            for i=1:n
                                sum=0;
                                for j=1:i-1
                                    sum=sum+a(i,j)*xv(j);
                                end
                                for j=i+1:n
                                    sum=sum+a(i,j)*xv(j);
                                end
                                xn(i)=(b(i)-sum)/a(i,i);
                            end
                            %sfarsit adaptare JACOBI
                        else
                            %adaptare GAUSS-SEIDEL
                            for i=1:n
                                sum=0;
                                for j=1:i-1
                                    sum=sum+a(i,j)*xn(j);
                                end
                                for j=i+1:n
                                    sum=sum+a(i,j)*xv(j);
                                end
                                xn(i)=(b(i)-sum)/a(i,i);
                            end
                            %sfarsit adaptere GAUSS-SEIDEL
                            vnif=max(abs(xn-xv));
                            iter
                            xn
                            vnif
                        end
                        fprintf('\n=================================\n');
                        x=a\b;
                        
                        format short
                        iter
                        xn
                        x
                    end
                    alta_adaptare=input('\n alta adaptare 0/1 ->');
                end
                reluare_5=input('\ndac? se dore?te, cu alt? estima?ie ini?ial? a solu?iei 0/1->');
            end
            reluare_4=input('\ndac? se dore?te, cu alt termen liber 0/1->');
        end
        reluare_3=input('\ndac? se dore?te, cu alt sistem de acela?i ordin 0/1->');
    end
    reluare_2=input('\n dac? se dore?te, cu alt sistem, de alt ordin n 0/1->');
end

