import numpy as np
rows = 2
cols = 1000 * 1000 * 100
data_arr = np.random.randint(low=1, high=100, size=(rows, cols))
np.save("data.npy" , data_arr)
