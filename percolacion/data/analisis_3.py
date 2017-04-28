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
plt.xlabel(r'Tamano de la red $L$')
plt.ylabel('Masa del cluster percolante')
plt.title('Masa del cluster percolante en funcion del tamano')
plt.legend()
plt.show()

log_L = np.log(L)
log_M = np.log(M)

plt.figure()
plt.scatter(log_L,log_M, color='b', label='Datos')
plt.grid(True)
plt.xlabel(r'Tamano de la red $log(L)$')
plt.ylabel(r'Masa del cluster percolante $log(M)$')
plt.title('Masa del cluster percolante en funcion del tamano (escala log-log)')
plt.legend()



D = np.polyfit(log_L, log_M,1)[0]
b = np.polyfit(log_L, log_M,1)[1]
plt.plot(log_L, D*log_L + b, color='r', label='Ajuste con b = {} y D = {}'.format(b,D))
plt.legend()

f = lambda x, m, b: m*x
D = curve_fit(f, log_L, log_M)[0][0]
plt.plot(log_L, D*log_L , color='g', label='Ajuste con b = 0 y D = {}'.format(D))
plt.legend()
plt.show()
