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
plt.xlabel('Tamaño de la red $L$')
plt.ylabel('Masa del cluster percolante')
plt.title('Masa del cluster percolante en función del tamaño')
plt.legend()

log_L = np.log(L)
log_M = np.log(M)

plt.figure()
plt.plot(log_L,log_M)
plt.grid(True)
plt.xlabel('Tamaño de la red $\log(L)$')
plt.ylabel('Masa del cluster percolante')
plt.title('Masa del cluster percolante en función del tamaño (escala log-log)')
plt.legend()

f = lambda x, m: m*x
D = curve_fit(f, log_L, log_M)[0][0]