# Sedgewick算法

Reference: Sedgewick, Robert; Szymanski, Thomas G.; Yao, Andrew C.-C. (1982), "The complexity of finding cycles in periodic functions", SIAM Journal on Computing, 11 (2): 376–390, doi:10.1137/0211030

Link: https://epubs.siam.org/doi/10.1137/0211030



Sedgewick，Szymanski，Yao提出了一种算法（下面简称Sedgewick算法），可以在使用$M$内存空间的情况下，用最坏情况下$(\lambda+\mu)(1+\frac{c}{\sqrt{M}})$次的函数计算找到环。与[Nivasch算法](https://www.gabrielnivasch.org/fun/cycle-detection相)相比，虽然Sedgewick算法的最坏时间复杂度要高于Nivasch算法的平均复杂度，但是要远低于Nivasch算法的最坏复杂度。由于哈希函数的环可能会非常长，因此我们认为有测试Sedgewick算法的必要性。

设哈希函数为$f(x)$，其迭代$n$次的值为$f^n(x)$。暴力算法会储存所有的$(f^i(x), i)$来检测是否存在环，Sedgewick算法使用了大小上限为$M$的表`TABLE`来存储这些值，插入的的值满足$(f^{kb}(x), kb), k\in \mathbb{Z}$，搜索的区间为$i\in[0,g\cdot b)$，如果搜索到对应的在`TABLE`内的值，那么证明检测到环。`TABLE`肯定无法储存所有的函数值，但是如果检测到它是满的，可以倍增$b$的值让其当前大小减半，这也相当于扩大环长度的搜索范围。这个算法保证可以检测到环并退出，因为如果存在环，那么连续的长度为$b$的搜索区间一定能遇到$f^{kb}(x)$。关于确切的最差情况复杂度证明请参考原论文。

$g$是一个固定参数，通过合理调整它的值，可以优化其理论总运行时间到$O(\sqrt{1/M})$的级别。更确切的说，我们有：
$$
g = \frac{Mt_s}{16t_f}(1+\frac{14}{M})
$$
其中$t_s, t_f$分别为在`TABLE`内搜索和查找值所需时间。`TABLE`的实现可以多种多样，其时间复杂度可以为`O(1)`，`O(\log M)`，甚至可以是线性查找表`O(M)`。在我们的实现中，使用了`std::unordered_map`提供的均摊时间复杂度为`O(1)`的哈希表。这样我们可以直接计算出最优化的$g=\frac{M}{16}(1+\frac{14}{M})$。

检测到存在环后，我们实际上得到的是环的长度$c$。恢复时，首先计算环的最小可能起点$j'$ ，然后在向后寻找最小的$l>j'$，使得$f^l(x)=f^{l+c}(x)$，这样我们就得到了一个碰撞：$f(f^{l-1}(x)) = f(f^{l+c-1}(x))$。这个过程中需要计算$f^{j'}(x)$，为了加速过程，我们可以利用表中已有的信息，寻找$f^{b\lfloor j'/b \rfloor}(x)$，然后再进行$j' \mathrm{mod} b$次函数计算即可求得$f^{j'}(x)$。具体计算方法参见论文和代码实现。

综上，Sedgewick算法可以在使用$M$大小的内存空间的情况下，用$n(1+\Theta(1/\sqrt{M}))$步操作找到一个碰撞，即第一个重复的$f^n(x)$。在我们的实现中，取$M=200000000$，稳定运行占用内存大约有10GB，能在17s内找到6字节的碰撞，500s左右找到7字节碰撞。对于更高字节数的碰撞，由于计算资源和时间问题，还未找到。根据估计，对于9字节碰撞，可以在150小时内完成。