#gen array and save in hdf5 file format
import numpy as np
import h5py as h5
rows = 2
cols = 1000
data_arr = np.random.randint(low=1, high=100, size=(rows, cols))

# Create a HDF5 file
with h5.File('ldata.h5', 'w') as f:
    # Write the numpy array to the HDF5 file
    f.create_dataset('data', data=data_arr)
