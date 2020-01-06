from matplotlib import pyplot as plt 
from matplotlib import style 
import numpy as np

style.use('ggplot')

N,BST,AVL = np.loadtxt('compare_and_plot.txt',unpack=True,delimiter = ';')

plt.plot(N,BST,'r')
plt.plot(N,AVL,'b')

plt.title('BST vs AVL Tree Comparison')
plt.xscale('log')
plt.yscale('log')
plt.ylabel('Comparisons')
plt.xlabel('N')

plt.show()

