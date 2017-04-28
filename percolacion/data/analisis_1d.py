#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 27 21:50:44 2017

@author: martin
"""
import numpy as np
import matplotlib.pyplot as plt

# tener el archivo de datos en el mismo directorio!!
datos_ns = np.loadtxt("datos dist_ns_posta.csv", delimiter = ',', skiprows=1)

dist = np.zeros((5,3,14)) # el primer indice corresponde a L, el segundo a 
# la probabilidad (podemos tomar tres valores para el rango de pc, en general
# 0.58 0.59 0.6) y el ultimo indice es el n_s para el s correspondiente (tenemos
# s de 1 a 14)

dist_58 = zeros(())

# rango para buscar p_c 
p_4 = np.array([0.54, 0.55, 0.56]) # solo para L=4 
p = np.array([0.58, 0.59, 0.6])    # para los demás L
s = np.arange(1,15)

for l in range(1,4):
    for p_s in range(3):
        for ss in range(14):
            dist[l,p_s,ss] = datos_ns[2341 + 1485*(l-1) + 15*p_s + ss, 3]

plt.loglog(s,dist[1,0,:])