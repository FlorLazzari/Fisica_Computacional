#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 27 18:26:40 2017

@author: martin
"""

import numpy as np
import matplotlib.pyplot as plt


# tener el archivo de datos en el mismo directorio!!
datos_fuerza = np.loadtxt("datos fuerza_posta.csv", delimiter = ',', skiprows=1)

#p = np.arange(0.01, 1.01, 0.01)
p_f = np.arange(0.1, 1.01, 0.01)
L = np.array([4,8,16,32,64,128])
fuerza = np.zeros((6,91))

for i in range(6):
    for j in range(91):
        fuerza[i,j] = datos_fuerza[91*(i)+j,2]

plt.figure()
for i in range(6):
    plt.plot(p_f, fuerza[i,:], label = 'L= {:d}'.format(L[i]))
plt.grid(True)
plt.xlabel('Probabilidad de ocupacion', fontsize=15)
plt.ylabel('Fuerza del cluster percolante', fontsize=15)
plt.title('Intensidad del cluster percolante $P(p)$', fontsize=20)
plt.xticks(np.arange(0, 1.1, 0.1), fontsize=12)
plt.yticks(np.arange(0, 1.1, 0.1), fontsize=12)
plt.legend(fontsize=18)
plt.show()
