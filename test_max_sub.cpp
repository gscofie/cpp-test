#include <iostream>
#include <vector>

/**
 * 算法复杂度为 O(1*N*N*N)
 */
int maxSubSum1 (const std::vector<int> & a) {
  int maxSum = 0 ;
  for (int i=0; i<a.size(); ++i ) {
    for (int j=i; j< a.size(); ++j) {
      int thisSum = 0;
      for (int k=i; k<=j; ++k) {
        thisSum += a[k];
        //std::cout << "i=" << i << " j=" << j << " k=" << k << " thissum = " << thisSum << " maxSum=" << maxSum<< std::endl;
      }
      if (thisSum > maxSum) {
        maxSum = thisSum;
      }
    }
  }
  return maxSum;
}

/**
 * 算法复杂度为 O(N*N)
 */
int maxSubSum2(const std::vector<int> & a) {
  int maxSum = 0;
  for (int i=0; i<a.size(); i++) {
    int thisSum = 0;
    for (int j=i;j<a.size(); j++) {
      thisSum += a[j];
      if (thisSum > maxSum) {
       maxSum = thisSum;
      }
    } 
  }
  return maxSum;
}

int max3(int a,int b,int c) {
    return (a>b?a:b)>c?(a>b?a:b):c;
}

int maxSumRecord(const std::vector<int> & a, int left, int right) {
  if (left == right) {
    if (a[left] > 0) {
      return a[left];
    }
    else {
      return 0;
    }
  }
  int center = (left + right) / 2;
  int leftMaxRec  = maxSumRecord(a, 0, center );
  int rightMaxRec = maxSumRecord(a, center + 1, right);

  int maxBorderLeft = 0, leftBorderSum = 0;
  for (int i = center; i >= left; --i) {
    leftBorderSum += a[i];
    if (leftBorderSum > maxBorderLeft) 
       maxBorderLeft = leftBorderSum;
  }

  int maxBorderRight = 0, rightBorderSum = 0;
  for (int j = center+1; j <= right; ++j) {
    rightBorderSum += a[j]; 
    if (rightBorderSum > maxBorderRight)
       maxBorderRight = rightBorderSum; 
  }

  //std::cout<< "leftMax:" << leftMaxRec << ",rightMax:" << rightMaxRec 
   // << ", borderMax:" << (maxBorderRight + maxBorderLeft) << std::endl; 

  return max3(leftMaxRec, rightMaxRec, maxBorderRight + maxBorderLeft);
}

/**
 * 算法复杂度为 O(NlogN)
 */
int maxSubSum3 (const std::vector<int> &a) {
  return maxSumRecord(a, 0, a.size()-1);
}

/**
 * 算法复杂度为O(N)
 */
int maxSubSum4 (const std::vector<int> &a) {
  int thisSum = 0, maxSum = 0; 
  for (int j=0; j<a.size(); j++) {
    thisSum += a[j] ;
    if (thisSum > maxSum) {
      maxSum = thisSum; 
    } else if (thisSum < 0) {
      thisSum = 0;
    }
  }
  return maxSum;
}


int main() {
  std::vector<int> a ;
  a.push_back(0);
  a.push_back(9);
  a.push_back(-11);
  a.push_back(-1);
  a.push_back(8);
  a.push_back(2);
  a.push_back(-11);
  a.push_back(9);
  a.push_back(-6);
  a.push_back(-7);
  a.push_back(8);
  a.push_back(-11);
  a.push_back(9);

  std::cout <<"max sum1 = "  << maxSubSum1(a) << std::endl;
  std::cout <<"max sum2 = "  << maxSubSum2(a) << std::endl;
  std::cout <<"max sum3 = "  << maxSubSum3(a) << std::endl;
  std::cout <<"max sum4 = "  << maxSubSum4(a) << std::endl;
  return 0;
}
//联机算法（maxSubSum4）： on-line algorithm
//1. 只对数据进行一次顺序的扫描
//2. 在任意时刻对问题都可给出正确的答案
//3. 仅需要常量空间，并以线性时间运行的联机算法几乎是完美的
