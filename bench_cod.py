#normal python benchmark
from time import time
start = time()
datafile = open("data.csv" , "r")
d = datafile.read().split("\n")
Xs = d[0]
Ys = d[1]
datafile.close()
X = [int(x) for x in Xs.split(",") ]
Y = [int(y) for y in Ys.split(",") ]

#z = x + y^2 + 2
def formula(x:int , y:int ):
    return x + y**2 + 2
Z = [formula(x,y) for x,y in zip(X,Y)]
total = sum(Z[:100])
end = time()
total_time = end - start
print(f"Total is {total} and execution time is {total_time} seconds ")
