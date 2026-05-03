from math import sqrt

def if_(x,y,z):
    if x:
        return y
    else : 
        return z


def real_sqrt(x):
    if x>0:
        return sqrt(x)
    else :
        return 0
real_sqrt(33)
real_sqrt(22)
print(real_sqrt(33))
print(real_sqrt(22))

def real_sqrt_if (x):
    return if_(x,sqrt(x),0.0)
    

print (real_sqrt_if(100))
