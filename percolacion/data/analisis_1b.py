#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 27 16:54:40 2017

@author: martin
"""

import numpy as np
import matplotlib.pyplot as plt


# tener el archivo de datos en el mismo directorio!!
datos = np.loadtxt("datos 1b_posta.csv", delimiter = ',', skiprows=1)

p = np.arange(0, 1, 0.01)
L = np.array([4,8,16,32,64,128])
F = np.zeros((6,100)) # el primer índice corresponde a L, para cada valor hay 
                      # 100 valores, cada uno correspondiente a una p

for i in range(6):
    for j in range(100):
        F[i,j] = datos[100*(i)+j,2]  

plt.figure()
for i in range(6):
    plt.plot(p,F[i,:], label = 'L= {:d}'.format(L[i]))
plt.grid(True)
plt.xlabel('Probabilidad de ocupacion')
plt.ylabel('Probabilidad de percolacion')
plt.title('Probabilidad de aparicion del cluster percolante $F(p)$')
plt.legend()
