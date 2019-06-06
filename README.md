# ppeng_code
> Get into Leetcode~

## **problems 5: longestPalindromeSubstring**

* 当前解法：中心扩展法，回文字符串两侧互为镜像可以从中心展开
    * 一共有$2n-1$个中心点，需要考虑字符串长度的奇偶性
    * 时间复杂度$O\left(n^{2}\right)$, 空间复杂度$O\left(1\right)$