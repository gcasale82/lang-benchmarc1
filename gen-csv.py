import numpy as np
from numpy import asarray, savetxt
rows = 2
cols = 1000 * 1000 * 100
np.set_printoptions(suppress=True)
data_arr = np.random.randint(low=1, high=100, size=(rows, cols))
savetxt('data.csv', data_arr,fmt='%d' ,delimiter=',')
