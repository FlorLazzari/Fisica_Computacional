#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May  1 23:03:49 2017

@author: martin
"""

import numpy as np
import matplotlib.pyplot as plt

datos_ns = np.loadtxt("datos dist_ns_L128.csv", delimiter = ',', skiprows=1)

p = np.arange(0.01, 1, 0.01)
s = np.arange(1,15)
ns= np.zeros((14,99))

for i in range(14):
    for j in range(99):
        ns[i,j] = datos_ns[1+15*j+i,3]
        
plt.figure()
for i in range(14):
    plt.plot(p,ns[i,:], label = 's = {}'.format(i+1))        
plt.grid(True)
plt.xlabel('Probabilidad de ocupación $p$', fontsize=15)
plt.ylabel('Densidad de clusters $n_s$', fontsize=15)
plt.title('Densidad de clusters $n_s(p)$', fontsize=20)
plt.legend(loc='best')    
  
#%% p_max para cada s

p_max = np.array([0.19, ])  