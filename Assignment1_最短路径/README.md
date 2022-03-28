# 实现BFS,Dijkstra, A*寻路算法

### 1.要求

根据网页:<a href="./Assignment request/pathfinding thing.html">requst</a> 的提示实现BFS,Dijkstra, A*寻路算法

![](H:\2109\DATA STRUCTURES\Assignment1_最短路径\img\1.png)

## 2.实现

#### 1.创建coord类

首先构造坐标系使点有x,y两个属性，并重写equals方法使得后续易于判断结点是否是终点

#### 2.创建Node类

赋予结点更多的属性，构建类似于链表的指针域的东西，方便最后回溯路径时用队列找上一个结点。

​    G表示起点到当前结点的cost，H表示当前结点到目的结点的估计代价

  并重写compareTo函数，方便open队列（储存周围所以可以走的结点）的结点的cost比较

#### 3.创建MapInfo类

生成整个地图的类，并得知相关数据

#### 4.Astar算法实现

在地图上未走过的结点为0，障碍物为1，走过的路径为2

​    并用ArrayList（）存储走过的路径，PriorityQueue（）存储所有可以走的点

知道地图的相关数据，并在openList添加起始点，并通过moveNodeshan使当前点选择下一个节点

绘制路径的函数：通过closelist和parent找到上一个结点，将其中的值都改为2

通过两次重写函数把附近的点都加进openlist，第一次使用较为上层的方式写现结点的周围8个点， 第二个则为底层的算出结点的G和H，将G增加的值加入openlist（含是重点的特殊情况）（G越大，表明离起点越远，离终点靠近）

以下是上述函数进行比较还需的底层函数

![](H:\2109\DATA STRUCTURES\Assignment1_最短路径\img\2.png)

#### 5.Dijkstra算法

相比于Astar算法，Dijkstra算法无启发式即其G和H的计算方式不同，修改相关代码即可

G = 已经走过的cost， H = 下一步花费的cost

H的值计算方式也不太相同

结果：

![](H:\2109\DATA STRUCTURES\Assignment1_最短路径\img\3.png)

#### 6.Bfs算法

Bfs的openlist与前两者不同其没有cost的比较，而秉承着先进先出的队列思想

所以用不着PriorityQueue（）进行排序



#### 7.解释

1.因为三个算法计算距离的方式不同，所以Astar的总代价为欧几里得距离，而Dijkstra和Bfs算法用的是曼哈顿距离

 

2.用以上算法实现和网页上的路径不太一样，但总距离是一样的，个人感觉是队列排序时无法完全模拟网页结果所致

空间复杂度和时间复杂度

因为算法中的循环和储存空间都与整个地图的边长由着直接关系，所以把其边长设为n

则空间复杂度为O（n^2）（主要引导的是openlist），时间复杂度为也为O（n^2）