class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max_sum = 0;
        int len = cardPoints.size();

        int lsum = 0, rsum = 0;
        int rindex = len-1;

        if(k==len)
        {
            for (int i=0; i<k; i++)
            max_sum += cardPoints[i];
            return max_sum;
        }
        else
        {
            for (int i=0; i<k; i++)
            {
                lsum += cardPoints[i];
                max_sum = lsum;
            }

            for (int i=k-1; i>=0; i--)
            {
                lsum = lsum - cardPoints[i];
                rsum = rsum + cardPoints[rindex];
                rindex = rindex - 1;

                if(max_sum < (lsum + rsum))
                {
                    max_sum = lsum + rsum;
                }
            }

        }
        return max_sum;
    }
};