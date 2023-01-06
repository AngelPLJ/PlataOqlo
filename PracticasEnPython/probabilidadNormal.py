from math import cos, exp, pi, sqrt, pow
from scipy.integrate import quad

print('Ingrese el valor de sigma');
sigma = float(input())
print('Ingrese el valor de u');
u = float(input())

f = lambda x: (1/(sigma*(sqrt(2*pi))))*(exp(-.5*(pow(((x-u)/sigma),2))))
    
#peticion de datos
print('Ingrese el limite inferior a:')
a = int(input())
print('Ingrese el limite superior b:')
b = int(input())


res, err = quad(f, a, b)



print("El valor numerico de la integral es: {:f}"
    .format(res))
