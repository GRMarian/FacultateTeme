global u a;
NpMax=200;

while true
    while true
        a=input('\n introduce a -> ');
        if a~=0
            break;
        end
    end
    while true
        u=input('\n introduce u -> ');
        y0=input('\n introduce y0 -> ');
        while true
            while true
                
                Hint=input('\n introduce pas de integrare -> ');
                Htip=input('\n introduce pas de afi?are -> ');
                Hobs=input('\n introduce durat? de simulare -> ');
                
                Nstep=fix(Hobs/Hint);
                Ntip=fix(Htip/Hint);
                Np=fix(Nstep/Ntip)+1;
                
                if Np <= NpMax
                    break;
                end
            end
            
            t0=0;
            h2=Hint/2;
            h6=Hint/6;
            
            ys=zeros(1,Np);
            timp=zeros(1,Np);
            
            us=ones(1,Np)'*u;
            
            timp(1)=t0;
            ys(1)=y0;
            t=t0;
            y=y0;
            kp=1;
            h=Hint;
            t
            y
            
            for Kstep=1:Nstep
                t=t+Hint;
                r1=FCS(t,y);
                r2=FCS(t+h2,y+h2*r1);
                r3=FCS(t+h2,y+h2*r2);
                r4=FCS(t+h,y+h*r3);
                y=y+h6*(r1+2*r2+2*r3+r4);
                if rem(Kstep,Ntip)==0
                    kp=kp+1;
                    timp(kp)=t;
                    ys(kp)=y;
                    t
                    y
                end
            end
            
            K=u;
            C=y0-K;
            f=@(t) C*exp(-t/a)+K;
            
            plot(timp,us);
            hold on;
            plot(timp,ys,'--');
            hold o;
            plot(timp,f(timp));
            
            if ~input('reluare 5 tastati 0 ->')
                break;
            end
        end
        if ~input('reluare 4 tastati 0 ->')
            break;
        end
    end
    if ~input('reluare 3 tastati 0 ->')
        break;
    end
end




