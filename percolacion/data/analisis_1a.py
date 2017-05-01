#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 27 15:33:37 2017

@author: martin
"""
import numpy as np
import matplotlib.pyplot as plt

# tener el archivo de datos en el mismo directorio!!

datos = np.loadtxt("datos 1a_posta.csv", delimiter = ',', skiprows=1)

pc = np.zeros((6,10)) # el primer índice corresponde a L, para cada valor hay
                      # diez mediciones de pc

for i in range(6):
    for j in range(10):
        pc[i,j] = datos[10*(i)+j,1]

pc_prom = np.mean(pc,1) # da el promedio de pc para cada L
pc_stdv = np.std(pc,1)  # da la dispersion de pc para cada L

L = np.array([4,8,16,32,64,128])

print(pc_prom)


plt.plot(L,pc_stdv,'r', label = 'sigma p_c')
plt.xlabel('Tamaño de la red $L$', fontsize = 12)
plt.xticks(fontsize=12)
plt.ylabel('Dispersión', fontsize = 12)
plt.yticks(fontsize=12)
plt.title('Dispersión en los valores de $p_c$ en función del tamaño', fontsize = 15)
plt.grid(True)
plt.show()
fig = plt.figure()
plt.close(fig)


plt.figure()
plt.plot(L, pc_prom, color='b', label = 'p_c', markersize = 20, marker = 'o', linestyle = 'none')
plt.xlabel('Tamaño de la red $L$', fontsize=12)
plt.ylabel('Probabilidad crítica', fontsize=12)
plt.title('Probabilidad crítica $p_c$ en función del tamaño', fontsize=20)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.grid(True)
plt.show()
fig = plt.figure()
plt.close(fig)
