/*
* Problem : Best Time to Buy and Sell Stock (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* i��° ���� �ֽ� �ݾ� prices[]�� �־��� ��,
* �ż� �ݾװ� �ŵ� �ݾ� ������ �ִ��� ��ȯ�ϴ� �Լ�
* �ż��� �ŵ����� ���� �̷������ ��
* 
* 1. �ܼ� Ž�� O(n^2)
* for(int i = 0...) {for(for j = i+1...) //}
* 
* 2. �ּұݾ�, �ִ����� ���� O(n)
*/

#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        //�ּұݾװ� �ִ������� ������ ���� ����
        int minPrice = 1e4;
        int maxProfit = 0;
        //prices�� ��� �ݾ��� ��ȸ
        for (int i = 0; i < prices.size(); i++)
        {
            //���� �ݾ��� �ּ� �ݾ׺��� ������ �ּұݾ� ����
            if (prices[i] < minPrice)
                minPrice = prices[i];
            //���� �ݾװ� �ּ� �ݾ��� ������ �ִ����׺��� ũ�ٸ� �ִ����� ����
            else if (prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};