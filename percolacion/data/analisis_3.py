#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 27 19:04:45 2017

@author: martin
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# tener el archivo de datos en el mismo directorio!!
datos_masa = np.loadtxt("datos masa_posta.csv", delimiter = ',', skiprows=1)

L = datos_masa[:,0]
M = datos_masa[:,1]

plt.figure()
plt.plot(L,M)
plt.grid(True)
plt.xlabel('Tamano de la red $L$', fontsize=15)
plt.ylabel('Masa del cluster percolante', fontsize=15)
plt.title('Masa del cluster percolante en funcion del tamano', fontsize=20)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(fontsize=18)
plt.show()

log_L = np.log(L)
log_M = np.log(M)

plt.figure()
plt.scatter(log_L,log_M, marker='o', color='c', label='Datos')
plt.grid(True)
plt.xlabel(r'Tamaño de la red $log(L)$', fontsize=15)
plt.ylabel(r'Masa del cluster percolante $log(M)$', fontsize=15)
plt.title('Masa del cluster percolante en funcion del tamaño (escala log-log)', fontsize=20)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(fontsize=18)



D = np.polyfit(log_L, log_M,1)[0]
b = np.polyfit(log_L, log_M,1)[1]
plt.plot(log_L, D*log_L + b, color='r', label='Ajuste con b = {:.3f} y D = {:.3f}'.format(b,D))
plt.legend(fontsize=18, loc='best')

f = lambda x, m, b: m*x
D = curve_fit(f, log_L, log_M)[0][0]
plt.plot(log_L, D*log_L , color='b', label='Ajuste con b = 0 y D = {:.3f}'.format(D))
plt.legend(fontsize=18, loc='best')
plt.show()
