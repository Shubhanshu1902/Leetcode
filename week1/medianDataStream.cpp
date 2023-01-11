#include <bits/stdc++.h>
using namespace std;

/*
Make 2 groups(2 priority queue)

1st priority queue is max heap
2nd priority queue is min heap

if max heap is empty then push data in max heap or if top element of max heap is greater than input,
push input in max heap else push input in min heap.

let 
n = size of max heap
m = size of min heap

if n > m + 1 then put the top element of max heap in min heap
else if m > n the put top element of min heap in max heap

Find MEDIAN
if size of max heap is more, then median is top element of max heap
else if both have same size, then median is avg of top element of max heap and min heap
*/


class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    int count;
    MedianFinder(){}

    void addNum(int num)
    {
        if (maxheap.empty() || maxheap.top() >= num)
            maxheap.push(num);

        else
            minheap.push(num);

        int n = maxheap.size(), m = minheap.size();

        if (n > m + 1)
        {   
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (m > n){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        int n = maxheap.size(), m = minheap.size();
        if (n > m){
            return maxheap.top();
        }
        else if(n < m) return minheap.top();
        else return ((double)maxheap.top()+(double)minheap.top())/2;
    }
};