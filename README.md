# happen-code
> Get into Leetcode~

## Code List
1. [动态规划](#动态规划)
    * [problem5-longestPalindromeSubstring](#problem5-longestPalindromeSubstring)
    * [problem53-Maxsubarray](#problem53-Maxsubarray)
    * [problem62-UniquePaths](#problem62-UniquePaths)
    * [problem63-UniquePathsWithObstacles](#problem63-UniquePathsWithObstacles)
    * [problem64-MinPathSum](#problem64-MinPathSum)
    * [problem70-ClimbStairs](#problem70-ClimbStairs)
    * [problem32-LongestValidParentheses](#problem32-LongestValidParentheses)
    * [problem10-IsMatch](#problem10-IsMatch)
    * [problem72-MinDistance](#problem72-MinDistance)
2. [深度优先搜索](#深度优先搜索)
    * [problem98-isValidBST](#problem98-isValidBST)
    * [problem99-recoverTree](#problem99-recoverTree)
    * [problem100-isSameTree](#problem100-isSameTree)
    * [problem101-isSymmetric](#problem101-isSymmetric)
    * [problem104-maxDepth](#problem104-maxDepth)
    * [problem105-buildTree](#problem105-buildTree)
    * [problem106-buildTree_1](#problem106-buildTree_1)
    * [problem107-levelOrderBottom](#problem107-levelOrderBottom)
    * [problem108-sortedarraytoBST](#problem108-sortedarraytoBST)
    * [problem109-sortedlisttoBST](#problem109-sortedlisttoBST)
    * [problem110-isBalanced](#problem110-isBalanced)
    * [problem111-minDepth](#problem111-minDepth)
    * [problem112-hasPathSum](#problem112-hasPathSum)
    * [problem113-PathSum](#problem113-PathSum)
    * [problem114-flatten](#problem114-flatten)
    * [problem116-Connect](#problem116-Connect)


## 动态规划
> 动态规划（英语：Dynamic programming，简称 DP）是一种在数学、管理科学、计算机科学、经济学和生物信息学中使用的，通过把原问题分解为相对简单的子问题的方式求解复杂问题的方法。动态规划常常适用于有重叠子问题和最优子结构性质的问题，动态规划方法所耗时间往往远少于朴素解法。动态规划背后的基本思想非常简单。大致上，若要解一个给定问题，我们需要解其不同部分（即子问题），再根据子问题的解以得出原问题的解。通常许多子问题非常相似，为此动态规划法试图仅仅解决每个子问题一次，从而减少计算量：一旦某个给定子问题的解已经算出，则将其记忆化存储，以便下次需要同一个子问题解之时直接查表。这种做法在重复子问题的数目关于输入的规模呈指数增长时特别有用。

### problem5-longestPalindromeSubstring
> 动态规划， 此处没有用动态规划解决

* 当前解法: 中心扩展法，回文字符串两侧互为镜像可以从中心展开
  * 一共有$2n-1$个中心点，需要考虑字符串长度的奇偶性
  * 时间复杂度 $O\left(n^{2}\right)$ , 空间复杂度 $O\left(1\right)$

### problem53-Maxsubarray
> 动态规划
* DP算法的主要解题步骤，通过把原问题分解为相对简单的子问题的方式来求解复杂问题的方法，DP使用于有重叠子问题和最优子结构性质的问题
  * 确定问题具有最优子结构性质
  * 构造最优值的递归关系表达式
  * 最优值的算法描述
  * 构造最优解
* 当前解法: 动态规划算法，定义一个最优解数组 $\mathrm{dp}[\mathrm{i}]$ 来记录截止到当前元素的最大子序列和
  * 确定问题具有最优子结构性质: 以下标$i$作为结尾的子序列最大和可以通过$i-1$的子序列最大和以及$array[i]$的值来判断;
  * 构造最优值的递归关系表达式: $\mathrm{dp}[i]=\max (\mathrm{dp}[\mathrm{i}-1]+ nums[i], nums[i])$, 并修改当前子序列的head的指向；
  * 最优值算法描述&&构造最优解: 根据数组前三项总结出以当前项为尾节点的子序列的最大序列和，同时需要记录子序列头结点的位置; 计算出dp数组所有的最大子序列和然后遍历一遍求出最优解，同时还可以返回子序列的position;

### problem62-UniquePaths
> 动态规划
* 当前解法: 动态规划算法，定义一个最优解数组paths来记录到达当前坐标$(i,j)$的路径数目
  * 确定问题具有最优子结构性质: 在这个题目的场景中到达坐标$(i,j)$的路径数可以通过它上和左边的坐标点路径数来确定；
  * 构造最优值的递归关系表达式: $paths[i][j]=paths[i-1][j]+paths[i][j-1]$
  * 最优值算法描述: 从坐标 $(0,0)$ 开始依次遍历每一个坐标并计算其路径数，需要注意的是由于只能向右和向下移动，导致在上边界和左边界的路径数目受到限制产生边界条件需要单独计算；
  * 构造最优解: 当整个地图的坐标点都被遍历一遍后，到达各坐标点的路径数也确定了，取 $paths[n-1][m-1]$ 即为到达标记处的路径数

### problem63-UniquePathsWithObstacles
> 动态规划，在62题路径问题的基础上引入路障增加难度
* 当前解法: 动态规划算法，定义一个最优解数组paths来记录到达当前坐标$(i,j)$的路径数目，解法基本思路同62题
  * 确定问题具有最优子结构性质: 在这个题目的场景中到达坐标$(i,j)$的路径数可以通过它上和左边的坐标点路径数来确定；
  * 构造最优值的递归关系表达式: $paths[i][j]=(obstacleGrid[i][j]==0)?(paths[i-1][j]+paths[i][j-1]):0$
  * 最优值算法描述: 大体思路和62相似，但是引入了路障map，在计算 $(i,j)$ 的路径数时需要加入是否有路障的判断，该点有路障则到达该点的路径数为0；
  * 构造最优解: 遍历整个map后，paths存储为能到达的每个点的最优路径数，更加实际返回坐标获取最优解；

### problem64-MinPathSum
> 动态规划，在之前求解路径的基础上给每条路径加上了权重，求权重最小的路径
* 当前解法: 动态规划算法，定义dp数组来存储到达当前点 $(i,j)$ 的最小路径和，解法和前两题相同
  * 构造最优值的递归关系表达式: $dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + grid[i][j]$

### problem70-ClimbStairs
> 动态规划，之前的场景都是在二维的map，这次换成一维的path，集体思路还是相似
* 当前解法：动态规划算法，定义dp数组存储到达层 $i$ 的方法数，$dp[n-1]$ 即达到顶层的方法数
  * 构造最优值的递归关系表达式：$dp[i]=dp[i-1] + dp[i-2] (i >= 2)$

### problem32-LongestValidParentheses
> 动态规划, 不过目前题目的解法没有用到动态规划
* 当前解法: 类似于遍历方法，定义数组dp来存储以$i$起始的有效括号长度，用$(length, end + 1)$表示有效括号长度以及该子串结尾的下一个位置，在没有有效括号的情况下才会依次遍历字符串
  * 确定每一对数的值: 输入子串的$offset: pos$以及对应的$string$: substr，通过设置$checkpoint$来记录当前的组成的括号是否有效；
  * $checkpoint$计算规则: $checkpoint = (char == '(') ? checkpoint + 1 : checkpoint - 1$
  * 有效长度更新规则: 当$checkpoint == 0$时，对有效长度进行更新， 始终存最长的值，由于左括号必须先出现所以当$checkpoint < 0 $时即结束本次括号匹配；
  * 如果以$i$起始找到有效字符串，那么之后的括号匹配以$i+length$起始，否则以$i+1$起始
* 动态规划解法: 

### problem10-IsMatch
> 动态规划，参考了别人python代码动态规划解法的思路(难度较大，不是很好理解部分递归关系表达式)
* 当前解法：动态规划解法，定义数组 $dp[i][j]$ 表text string从i到末尾，pattern从j到末尾，此时两个字符串是否匹配
  - 确定问题具有最优子结构性质: $dp[i][j]$ 的值可以通过字符 $i,j,j+1$ 以及 状态$dp[i+1][j+1], dp[i][j+2],dp[i+1][j]$综合判断(理解起来可能比较复杂...)
  - 构造最优值的递归关系表达式:
    - 判断当前状态 $dp[i][j]$ 假设text和pattern的当前字符为x，y，pattern的当前字符的下一个字符为z，则text可以表示为text_sub = xS, pattern可以表示为pattern_sub = yzP;
    - $x == y || p[j] == "."$ 时候，$dp[i][j] = dp[i+1][j+1]$，这一步还是比较好理解的
    - $p[j+1] == *$且$s[i] != p[j]$的时候$dp[i][j] = dp[i][j+2]$，$z == *$ 但是$x!=y$，由于\*可以表示0~n个前面的字符，此时如果表示0个字符则需要$dp[i][j+2]$的状态来确定;
    - $p[j+1] == '*'$且$s[i] == p[j]$的时候$dp[i][j] = dp[i+1][j]$，因为$z == *$的时候z可以表示多个y，这个分支判断的是字符x重复的情况；
  - 最优值算法描述: 本题动态规划可以由底至顶计算也可以由顶至底计算，主分支通过x，y，z的值进行分割；
  - 构造最优解：最后$dp[0][0]$ 存储的状态就是p是否能匹配为s

### problem72-MinDistance
> 给定word1和word2，计算从word1到word2的最小编辑距离

* 默认条件: 可以对单词进行插入、删除、替换三种操作

## 深度优先搜索
> 深度优先搜索算法（英语：Depth-First-Search，DFS）是一种用于遍历或搜索树或图的算法。沿着树的深度遍历树的节点，尽可能深的搜索树的分支。当节点v的所在边都己被探寻过，搜索将回溯到发现节点v的那条边的起始节点。这一过程一直进行到已发现从源节点可达的所有节点为止。如果还存在未被发现的节点，则选择其中一个作为源节点并重复以上过程，整个进程反复进行直到所有节点都被访问为止。属于盲目搜索。深度优先搜索是图论中的经典算法，利用深度优先搜索算法可以产生目标图的相应拓扑排序表，利用拓扑排序表可以方便的解决很多相关的图论问题，如最大路径问题等等。

### problem98-isValidBST
> 判断二叉树是否为有效的二叉搜索树

* 二叉搜索树特征: 节点的左子树只包含小于当前节点的数；节点的右子树只包含大于当前节点的数；所有左子树和右子树自身必须是二叉搜索树
* 当前解法: 中序遍历二叉树，所得序列如果相邻两个节点的值都是升序的则为有效的的二叉搜索树；
  - 将各节点压入栈中，保证节点取出的顺序是中序遍历顺序，对比当前出栈节点val和前一个出栈节点val值；
  - 重点是按照怎么样的顺序将节点压入栈中和出栈(先将各个节点和左子树的左节点压入栈中，然后再压入出栈节点的右子树节点)

### problem99-recoverTree
> 二叉搜索树有两个节点被错误交换，在改变树的结构恢复BST

* 当前解法: 中序遍历二叉树，记录位置错误的两个节点的地址，交换其val，空间复杂度O(n), 待优化
  - 第一个节点出现在第一次出现相邻节点逆序的前序节点，这里需要定义一个`prenode`来记录当前节点的前序节点；
  - 第二个节点出现在最后一次出现相邻节点逆序的当前节点；
  - 遍历整个二叉树后，交换两个节点的val，在不改变树结构的情况下完成BST的恢复；

### problem100-isSameTree
> 判断给定的两个二叉树是否相同

* 当前解法: 深度优先搜索，在二叉树中就是先序遍历，时间复杂度`O(n)`
  - 当两棵树的当前都为`null`返回`true`
  - 当两棵树其中有一个为`null`返回`false`
  - 当两棵树当前节点值不相同时候返回`false`, 想同的话递归处理左子树和右子树

### problem101-isSymmetric
> 判断一个二叉树是否镜像对称

* 当前解法: 递归解法，时间复杂度`O(n)`
  - 镜像递归遍历二叉树，判断当前节点是否相同(实际上遍历了两次输入的二叉树，有重复计算)
* 迭代解法: 思路相仿，镜像地将二叉树的节点插入队列，从队列中连续取出两个节点判断其是否相同

### problem104-maxDepth
> 计算二叉树的最大深度

* 当前解法: 递归解法，时间复杂度`O(n)`
  - 递归遍历二叉树，当前节点的最大深度`depthNow=max(depth_left, depth_right)`

### problem105-buildTree
> 通过二叉树的先序遍历序列和中序遍历序列恢复二叉树

* 当前解法: 深度优先搜索递归解法，时间复杂度`O(n)`，空间复杂度`O(n)`
  - 恢复二叉数节点的顺序按照先序遍历的顺序进
  - 核心思想是利用先序遍历序列当前节点去切分中序遍历序列，找到当前节点在中序遍历序列中的位置，左侧所有节点为左子树节点，右侧所有节点为右子树节点，一次逐层递归

### problem106-buildTree_1
> 通过二叉树的中序遍历序列和后序遍历序列恢复二叉树

* 当前解法: 深度优先搜索递归解法
  - 在后序遍历序列中找到根节点(最后一个节点)
  - 在中序遍历序列中找到根节点的位置`std::find`、`std::distance`，将中序遍历序列分为左子树和右子树
  - 确定左右子树在中序序列中的左右边界
  - 递归构造左子树和右子树

### problem107-levelOrderBottom
> 返回二叉树从左至右从底至顶的层次遍历结果

* 当前解法: 深度优先搜索先序遍历，递归解法
  - levelorder的size小于当前level时，在levelorder中插入新的level
  - levelorder中存在第level层时，直接在该层插入新的元素
  - 逆序levelorder: `std::reverse`

### problem108-sortedarraytoBST
> 根据升序序列生成高度平衡的二叉搜索树

* 当前解法: 递归，根据中序遍历序列恢复二叉树
  - 选取数组中点作为根节点，以此保持二叉树的平衡性；
  - 根据根节点将输入序列分为左右子树；
  - 构建该节点的左右子树；

### problem109-sortedlisttoBST
> 根据升序链表序列生成高度平衡的二叉搜索树

* 当前解法: 是递归构建+快慢指针访问链表
  - 核心是找到链表的中间元素: 快慢指针访问链表，当`fast_ptr`到链表尾部时`slow_ptr`为链表的中间节点；
  - 将链表从中间元素断开, 使用`pre_ptr`来记录`slow_ptr`的前序节点；
  - 将左右两段链表作为头指针传递给递归构建函数构建高度平衡二叉搜索树；

### problem110-isBalanced
> 判断二叉树是否为高度平衡的二叉树

* 当前解法: bottom-top，提前终止递归
  - 递归终止条件为访问越过叶子节点返回高度0，同时空树可作为平衡二叉树；
  - 对于每一个节点其深度为左右子树最大的depth+1；
  - 如果左右子树高度差大于1代表不是平衡树，提前终止递归；

### problem111-minDepth
> 找到二叉树的最小深度，根节点到最近叶子节点的节点数量

* 当前解法: 深度优先搜索，递归遍历所有节点
  - 叶子节点的定义是左右孩子都为null
  - 左右孩子都为null时返回1
  - 当有一个孩子为null时，返回另一个孩子的depth(重点);

### problem112-hasPathSum
> 判断二叉树是否存在路径和等于目标和

* 当前解法: 深度优先搜索
  - 递归内部，sum减去当前节点val；
  - 递归终止，当前节点为叶子节点检测sum是否为0;

### problem113-PathSum
> 找到从根节点到叶子节点路径总和等于给定目标和的所有路径

* 当前解法: 深度优先搜素递归遍历树
  - 将路径上节点上的值压入vector中，并记录与之对应的和，判断是否等于目标和；
  - 遍历到叶子节点且和刚好等于目标和时，将此时的路径压入`vector<vector>`中;
* 优化解法: 节省内存空间
  - 只需要一个vector来存储全局当前的路径和，注意节点访问完后从vector中移除；

### problem114-flatten
> 给定一个二叉树将其展开为链表

* 当前解法: BFS递归遍历
  - BFS顺序将节点放入队列`queue`，取出队列头部节点修改其`right`
  - 当前节点右子树指向下一个节点，左子树置空

### problem116-Connect
> 填充完美二叉树节点的next指针，使其指向下一个右侧节点

* 当前解放：BFS递归遍历
  - BFS遍历节点压入队列中，当节点`idx=2^n - 1`时其next指针为`NULL`，其余都指向下一个右侧节点