# -*- coding: utf-8 -*-
"""

This is a temporary script file.
"""
import numpy as np
import matplotlib.pyplot as plt

datos_ns = np.loadtxt("datos dist_ns_posta.csv", delimiter = ',', skiprows=1)

pc = 0.58
tau = 1.71
sigma = 0.39

p = np.zeros((14,99))
ns = np.zeros((14,99))
s = np.zeros((14,99))

f = np.zeros((14,99))
z = np.zeros((14,99))
ns_c = np.zeros((14))

for i in range(14):
    # ns_c[i] = datos_ns[6811+i, 3]
    ns_c[i] = datos_ns[6796+i, 3]

p = np.arange(0.01,1,0.01)
s = np.arange(1,15)

plt.figure()
for i in range(14):
    for j in range(99):
        ns[i,j] = datos_ns[5941+i+15*j, 3]
        f[i,j] = ns[i,j]/ns_c[i]
        z[i,j] = (s[i]**(sigma))*(p[j]-pc)
    plt.plot(z[i,:], f[i,:], label = "s = {}".format(s[i]))
    plt.grid(True)
    plt.xlabel(r'$s^{\sigma} \epsilon$',fontsize = 15)
    plt.ylabel(r'$f(z)$',fontsize = 15)
    plt.title('Funcion de Scaling') #falta la tilde
    plt.legend(fontsize=18, loc='best')


################################################################################

plt.figure()
for i in range(14):
    for j in range(99):
        ns[i,j] = datos_ns[5941+i+15*j, 3]
        f[i,j] = ns[i,j]/(s[i]**(-tau))
        z[i,j] = (s[i]**(sigma))*(p[j]-pc)
    plt.plot(z[i,:], f[i,:], label = "s = {}".format(s[i]))
    plt.grid(True)
    plt.xlabel(r'$s^{\sigma} \epsilon$',fontsize = 15)
    plt.ylabel(r'$f(z)$',fontsize = 15)
    plt.title('Funcion de Scaling') #falta la tilde
    plt.legend(fontsize=18, loc='best')


plt.show()
