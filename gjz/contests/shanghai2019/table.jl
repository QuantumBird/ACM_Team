function check(n)
    digit_sum = 0
    tmp = n
    while tmp > 0
        digit_sum += tmp % 10
        tmp = div(tmp, 10)
    end
    tmp = n
    digit_mult = 1
    while tmp > 0
        digit_mult *= tmp % 10
        tmp = div(tmp, 10)
    end
    if digit_sum == digit_mult
        return true
    end
    false
end

function find_table(n)
    ans = []
    for i = 10^n:(10^(n + 1) - 1)
        if check(i)
            push!(ans, i)
        end
    end
    length(ans), ans
end

function display_table(n)
    ans = 0
    for i = 10^n:(10^(n + 1) - 1)
        if check(i)
            println(i)
            ans += 1
        end
    end
    ans
end

println(display_table(8))

