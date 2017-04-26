# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
p1 = np.zeros(99)
ns1 = np.zeros(99)
s1 = np.zeros(99)
for i in range(99):
    p1[i] = datosdist_nscsv[5941+15*i, 1]
    ns1[i] = datosdist_nscsv[5941+15*i, 3]
    s1[i] = datosdist_nscsv[5941+15*i, 2]

tau = 1.64
f1 = ns1/(s1**(-tau))
pc = 0.57
z1 = (s1**(0.39))*(p1-pc)


p2 = np.zeros(99)
ns2 = np.zeros(99)
s2 = np.zeros(99)
for i in range(99):
    p2[i] = datosdist_nscsv[5942+15*i, 1]
    ns2[i] = datosdist_nscsv[5942+15*i, 3]
    s2[i] = datosdist_nscsv[5942+15*i, 2]


f2 = ns2/(s2**(-tau))

z2 = (s2**(0.39))*(p2-pc)