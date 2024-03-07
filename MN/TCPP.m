function [P, L,  U] = TCPP(A)
% TRIANGULARIZARE CU PIVOTARE PARTIALA
    % verificare A patratica
    dim = length(A(:,1));
    EPS = length(A(1,:));
    if dim~=EPS
        fprintf("\n matricea nu este patratica");
        P = 0; L = 0; U = 0;
        return
    end
    % date initiale
    EPS = 1.e-7;
    U = A;
    P = eye(dim);
    L = eye(dim);
    for k = 1:dim-1
        % cautam ceam mai mare valoare pe linia k(pivot)
        pivot = k;
        for i = k+1:dim
            if abs(U(i,k)) > abs(U(pivot,k))
                pivot = i;
            end
        end
        % P_aux permuta pivotul pe principala
        P_aux = eye(dim);
        if pivot ~= k
            aux = P_aux(pivot,:);
            P_aux(pivot,:) = P_aux(k,:);
            P_aux(k,:) = aux;
            P = P_aux * P;
        end
        U = P_aux * U;
        % L_Eye_k -> de pe matrice unitate linie k
        % L_0_k   -> linie zerorizare k (sub k)
        % M_0_K   -> matrice zerorizare coloana k (sub k)
        L_Eye_k = zeros(dim,1);
        L_Eye_k(k) = 1;
        L_0_K = zeros(dim,1);
        for i = k+1:dim
            L_0_K(i) = U(i,k) / U(k,k);
        end
        M_0_K = eye(dim) - L_0_K * L_Eye_k';
        L = M_0_K * P_aux * L; 
        U = M_0_K * U;
        for i = 1:dim
            for j = 1:dim
                if A(i,j) < EPS
                    A(i,j) = 0;
                end
            end
        end
    end
    L=P/L;
end