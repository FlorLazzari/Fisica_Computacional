#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May  1 19:16:30 2017

@author: martin
"""

import numpy as np
import matplotlib.pyplot as plt

datos_6 = np.loadtxt("datos dist_ns_L6.csv", delimiter = ',', skiprows=1)
datos_128 = np.loadtxt("datos dist_ns_L128.csv", delimiter = ',', skiprows=1)

p = np.arange(0.01,1,0.01)
m2_4 = np.zeros(99)
m2_128 = np.zeros(99)

for i in range(99):
    for j in range(15):
        m2_4[i] += j**2 * datos_6[15*i+j,3]
        m2_128[i] += j**2 * datos_128[15*i+j,3]
            
plt.figure()
plt.plot(p,m2_4)

plt.figure()
plt.plot(p,m2_128)
#%% L = 128, la "p_c" es 0.38 (lugar 37)

p_menos = abs(p[:37] - 0.38)
p_mas = abs(p[37:] - 0.38)

g_menos = np.diff(m2_128[:38])/0.01        
g_mas = abs(np.diff(m2_128[38:])/0.01)
               
plt.figure()
plt.scatter(p_mas[:37],g_menos,color='b')
plt.scatter(p_mas[:60],g_mas, color= 'r')
               
#%% L = 4                

p_menos_4 = abs(p[:37] - 0.81)
p_mas_4 = abs(p[80:] - 0.81)

g_menos_4 = np.diff(m2_128[:80])/0.01        
g_mas_4 = abs(np.diff(m2_128[80:])/0.01)

plt.figure()
plt.scatter(p_menos_4[:-1],g_menos_4,color ='b')
plt.scatter(p_mas_4[:18],g_mas_4, color = 'r')

               