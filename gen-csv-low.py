import numpy as np
from numpy import asarray, savetxt
rows = 2
cols = 1000
np.set_printoptions(suppress=True)
data_arr = np.random.randint(low=1, high=100, size=(rows, cols))
savetxt('ldata.csv', data_arr,fmt='%d' ,delimiter=',')
