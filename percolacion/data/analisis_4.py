# -*- coding: utf-8 -*-
"""

This is a temporary script file.
"""
import numpy as np
import matplotlib.pyplot as plt

datos_ns = np.loadtxt("datos dist_ns_posta.csv", delimiter = ',', skiprows=1)

pc = 0.59

p1 = np.zeros(99)
ns1 = np.zeros(99)
s1 = np.zeros(99)
for i in range(99):
    p1[i] = datos_ns[5941+15*i, 1]
    ns1[i] = datos_ns[5941+15*i, 3]
    s1[i] = datos_ns[5941+15*i, 2]

tau = 1.64
f1 = ns1/(0.01678) # es el ns de pc para s=1
z1 = (s1**(0.39))*(p1-pc)

plt.plot(z1, f1)
# plt.show()


p2 = np.zeros(99)
ns2 = np.zeros(99)
s2 = np.zeros(99)
for i in range(99):
    p2[i] = datos_ns[5942+15*i, 1]
    ns2[i] = datos_ns[5942+15*i, 3]
    s2[i] = datos_ns[5942+15*i, 2]


f2 = ns2/(0.00351) # es el ns de pc para s igual a dos

z2 = (s2**(0.39))*(p2-pc)

plt.plot(z2, f2)
# plt.show()

################################################################################

p = np.zeros((14,99))
ns = np.zeros((14,99))
s = np.zeros((14,99))

f = np.zeros((14,99))
z = np.zeros((14,99))
ns_c = np.zeros((14))

for i in range(14):
    ns_c[i] = datos_ns[6811+i, 3]

sigma = 0.39

for i in range(14):
    for j in range(99):
        p[i,j] = datos_ns[5941+i+15*j, 1]
        ns[i,j] = datos_ns[5941+i+15*j, 3]
        # s[i,j] = datos_ns[5941+i+15*j, 2]
        s = np.arange(1,15)
        f[i,j] = ns[i,j]/ns_c[i]
        z[i,j] = (s[i]**(sigma))*(p[i,j]-pc)
    plt.plot(z[i,:], f[i,:], label = "s = {}".format(s[i]))
    plt.grid(True)
    plt.legend(fontsize=18, loc='best')


plt.show()
