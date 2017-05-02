# coding=utf-8

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May  1 23:03:49 2017

@author: martin
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

datos_ns = np.loadtxt("datos dist_ns_L128.csv", delimiter = ',', skiprows=1)

p = np.arange(0.01, 1, 0.01)
s = np.arange(1,15)
ns= np.zeros((14,99))

for i in range(14):
    for j in range(99):
        ns[i,j] = datos_ns[1+15*j+i,3]

plt.figure()
for i in range(1,14):
    plt.plot(p,ns[i,:], label = 's = {}'.format(i+1))
plt.grid(True)
plt.xlabel('Probabilidad de ocupacion $p$', fontsize=15)
plt.ylabel('Densidad de clusters $n_s$', fontsize=15)
plt.title('Densidad de clusters $n_s(p)$', fontsize=20)
plt.legend(loc='best')

#%% p_max para cada s

pc = 0.585
p_max = np.array([0.19, 0.240, 0.28, 0.31, 0.34, 0.35, 0.37, 0.38, 0.38, 0.4, 0.42, 0.42, 0.41, 0.43,])
eps = abs(p_max - pc)
log_s = np.log(s)
log_eps = np.log(eps)

plt.figure()
plt.scatter(log_s, log_eps)
plt.grid(True)
plt.xlabel(r'$Log(s)$', fontsize=15)
plt.ylabel(r'$\varepsilon = |p_{max} - p_c|$', fontsize=15)
plt.title('Ajuste para obtener $\sigma$', fontsize=20)
plt.legend(loc='best')



f = lambda x, m, b: m*x+b
popt, pcov = curve_fit(f, log_s, log_eps)
m = curve_fit(f, log_s, log_eps)[0][0]
b = curve_fit(f, log_s, log_eps)[0][1]
plt.plot(log_s, m*log_s+b, color='r', label='Ajuste con $\sigma$ = {:.3f} y b = {:.3f}'.format(m,b))
plt.legend(loc='best')
plt.show()
