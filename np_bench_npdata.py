import numpy as np
from time import time
start = time()
data_arr = np.load('data.npy')
# X = data_arr[0] , y = data_arr[1]
# Z = X + Y**2 + 2
Z = data_arr[0] + data_arr[1]**2 + 2

total = np.sum(Z[:100])
end = time()
total_time = end - start

print(f"Total is {total} and execution time is {total_time} seconds ")