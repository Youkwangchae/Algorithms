# import sys
# sys.setrecursionlimit(10**4)

n, k = map(int, input().split())

# n_list= [[1 for col in range(n+1)] for row in range(n+1)]
# for i in range(1, n+1):
#     for j in range(1, i):
#         n_list[i][j] = n_list[i-1][j-1] + n_list[i-1][j]

# for i in n_list :
#     for j in i:
#         print(j,end=" ")
#     print()

div = 1_000_000_007

def divNum(num:int):
    if(num < div):
        return num
    else:
        return num % div
    
def factorial_C(num:int, count:int, start:int):
    if count == 1:
        return num
    else:
        return factorial_C(num*(start-1), count-1, start-1)
    
def factorial_sub(num:int, count:int):
    if count == 1:
        return num
    elif num == count|count == 0:
        return 1    
    a = factorial_sub(num-1, count-1)
    b = factorial_sub(num-1, count)
    print(str(a)+" "+str(b))
    return a+b

def factorial(num:int):
    for i in range(num-1, 1, -1):
        num = (num*i)%div
    return num

def fast_pow(num:int, count:int):
    # if count == 1:
    #     return num
    # elif num == count|count == 0:
    #     return 1
    if count ==0:
        return 1    
    elif count % 2 == 0:
        return (fast_pow(num, count//2)**2)%div
    else:
        return (fast_pow(num, count//2)**2*num)%div


# if(k > n//2):
#     k = n-k

if k==1:
    print(str(n))
elif k==0:
    print("1")
elif n==0:
    print("1")
else:
    # up = factorial_C(n, k, n)
    # down = factorial_C(k, k, k)
    # print(str(divNum(up//down)))
    # print(str(factorial_sub(n, k)))
    # print(str(divNum(n_list[n][k])))

    up = factorial(n)
    down_A = fast_pow(factorial(k), div-2)%div
    down_B = fast_pow(factorial(n-k), div-2)%div
    print(up*down_A*down_B%div)
    