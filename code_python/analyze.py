import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline

x = np.array([0.049, , 3, 4.5, 6, 7.5, 9, 10])
y = np.array([0, 1.47, 2.96, 4.39, 5.89, 7.40, 8.83, 9.54])

x_smooth = np.linspace(x.min(), x.max(), 200)
y_smooth = make_interp_spline(x, y)(x_smooth)

plt.scatter(x, y)
for i in range(len(x)):
    plt.annotate(f'({x[i]}, {y[i]})', (x[i], y[i]), textcoords="offset points", xytext=(0,-10), ha='center')

plt.plot(x_smooth, y_smooth)
plt.xlabel('U(v)')
plt.ylabel('i(mA)')
plt.show()
