#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 27 21:50:44 2017

@author: martin
"""
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit


# tener el archivo de datos en el mismo directorio!!
datos_ns = np.loadtxt("datos dist_ns_posta.csv", delimiter = ',', skiprows=1)

dist = np.zeros((5,3,14)) # el primer indice corresponde a L, el segundo a
# la probabilidad (podemos tomar tres valores para el rango de pc, en general
# 0.58 0.59 0.6) y el ultimo indice es el n_s para el s correspondiente (tenemos
# s de 1 a 14)

# rango para buscar p_c
p_4 = np.array([0.54, 0.55, 0.56]) # solo para L=4
p = np.array([0.58, 0.59, 0.6])    # para los demás L
s = np.arange(1,15)
L = np.array([4,8,16,32,64])

for p_s in range(3):
    for ss in range(14):
        dist[0,p_s,ss] = datos_ns[796 + 15*p_s + ss, 3]

for l in range(1,5):
    for p_s in range(3):
        for ss in range(14):
            dist[l,p_s,ss] = datos_ns[2341 + 1485*(l-1) + 15*p_s + ss, 3]

# andan individualmente pero no todas juntas??
# for l in range(5):
#     plt.figure()
#     for i in range(3):
#         plt.loglog(s,dist[l,i,:], label = '$p={:f}$'.format(p[i]))
#         plt.xlabel(r'Tamano del cluster $s$')
#         plt.ylabel(r'Densidad de clusters $n_s$')
#         plt.title('Distribucion de clusters para L={:d}'.format(L[l]))
#         plt.grid(True)
#         plt.legend()
# plt.show()


log_s = np.log(s)
log_ns = np.log(dist)

f = lambda x, m, b: m*x+b

# color = {}
#
# color['0']='b'
# color['1']='g'
# color['2']='r'

color = ['b','g','r']

for l in range(1,5):
    plt.figure()
    for i in range(3):
        plt.xlabel(r'Tamano del cluster $s$')
        plt.scatter(log_s,log_ns[l,i,:],color=color[i], label = '$p={:f}$'.format(p[i]))
        plt.ylabel(r'Densidad de clusters $n_s$')
        plt.title('Distribucion de clusters para L={:d}, escala log-log'.format(L[l]))
        popt, pcov = curve_fit(f, log_s, log_ns[l,i,:])
        m = curve_fit(f, log_s, log_ns[l,i,:])[0][0]
        b = curve_fit(f, log_s, log_ns[l,i,:])[0][1]
        plt.plot(log_s, m*log_s+b, color=color[i], label='Ajuste con $m$ = {:.3f} y $b$ = {:.3f}'.format(m,b))
        plt.legend(loc='best')
        plt.grid(True)
        plt.legend()
plt.show()

plt.figure()
for i in range(3):
    plt.plot(log_s,log_ns[0,i,:], label = '$p={:f}$'.format(p_4[i]))
    plt.xlabel(r'Tamano del cluster $s$')
    plt.ylabel(r'Densidad de clusters $n_s$')
    plt.title('Distribucion de clusters para L={:d}, escala log-log'.format(L[0]))
    plt.grid(True)
    plt.legend()
plt.show()
