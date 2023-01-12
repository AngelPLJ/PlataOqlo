from math import cos, exp, pi, sqrt, pow
from scipy.integrate import quad

f = lambda x: (1/((sqrt(2*pi))))*(exp(-.5*(pow(((x)),2))))
    
#peticion de datos
print('Ingrese el limite inferior a:')
a = float(input())
print('Ingrese el limite superior b:')
b = float(input())
print('Ingrese el valor de divisiones:')
divisiones = int(input())
delta = (b-a)/divisiones
suma = 0.0
print(delta)
with open("tablas.txt", "w") as miArchivo:
    miArchivo.write("Valores de la integral normal\n\n")
    for i in range(divisiones):
        res,err = quad(f,a+i*delta,a+(i+1)*delta)
        suma += res
        valor = "{:.3F}".format(a+i*delta)
        miArchivo.write(valor + " " + str(suma) + "  ")
        if i%3 == 2 :
            miArchivo.write("\n")

res, err = quad(f, a, b)

print("El valor por sumatoria de la integral es: {:.8E}".format(suma))

print("El valor numerico de la integral es: {:.8E}"
    .format(res))
