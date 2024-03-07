function xp = FCU(t,x)
    global A B U;
    xp = A * x + B * U;
end

