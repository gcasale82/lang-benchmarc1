# Computation using hdf5 file format
import numpy as np
import h5py
from time import time

start = time()
hf = h5py.File('data.h5', 'r')
data_arr = np.array(hf["data"][:])
Z = data_arr[0] + data_arr[1]**2 + 2

total = np.sum(Z[:100])
end = time()
total_time = end - start

print(f"Total is {total} and execution time is {total_time} seconds ")