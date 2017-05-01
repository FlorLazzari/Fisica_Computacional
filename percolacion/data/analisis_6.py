#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May  1 19:16:30 2017

@author: martin
"""

import numpy as np
import matplotlib.pyplot as plt

datos_ns = np.loadtxt("datos dist_ns_posta.csv", delimiter = ',', skiprows=1)

p = np.arange(0.01,1,0.01)
m2_4 = np.zeros(99)
m2_128 = np.zeros(99)

for i in range(99):
    for j in range(15):
        m2_4[i] += j**2 * datos_ns[15*i+j,3]
        m2_128[i] += j**2 * datos_ns[15*i+j,3]
        
        
