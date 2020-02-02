from matplotlib import pyplot as plt 
from matplotlib import style 
import numpy as np

style.use('ggplot')

N,BST,AVL = np.loadtxt('compare_and_plot.txt',unpack=True,delimiter = ';')

plt.plot(N,BST,label='BST')
plt.scatter(N,BST,marker='.', color='r')
plt.plot(N,AVL,label='AVL')
plt.scatter(N,AVL,marker='.', color='b')

plt.title('Tree Comparison\nBST vs AVL')
plt.xscale('log')
plt.yscale('log')
plt.ylabel('Comparisons')
plt.xlabel('N')
plt.legend()

plt.show()

