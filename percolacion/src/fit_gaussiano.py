# para fitear con una gaussiana

import numpy
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt


# Define model function to be used to fit to the data above:
def gauss(x, A, mu, sigma):
    return A*numpy.exp(-(x-mu)**2/(2.*sigma**2))

# p0 is the initial guess for the fitting coefficients (A, mu and sigma above)
p0 = [1., 0., 1.]

coeff, var_matrix = curve_fit(gauss, x, y, p0=p0)

# Get the fitted curve
fit = gauss(x, coeff)

plt.plot(x, y, label='Test data')
plt.plot(x, fit, label='Fitted data')

# Finally, lets get the fitting parameters, i.e. the mean and standard deviation:
print 'Fitted mean = ', coeff[1]
print 'Fitted standard deviation = ', coeff[2]

plt.show()
