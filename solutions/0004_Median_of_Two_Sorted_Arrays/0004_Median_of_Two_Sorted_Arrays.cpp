// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// You may assume nums1 and nums2 cannot be both empty.
//
// Example 1:
//
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
// Example 2:
//
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size()+nums2.size()+1)/2;
        int bMin=0;
        vector<int> *a,*b;
        if(nums1.size()<nums2.size()) {
            a=&nums1;
            b=&nums2;
        } else {
            a=&nums2;
            b=&nums1;
        }
        int bMax=a->size();
        if(bMax==0){
            if(b->size()%2){
                return b->data()[b->size()/2];
            }else{
                return (b->data()[b->size()/2-1]+b->data()[b->size()/2])/2.0;
            }
        }

        double res=0;
        int i;
        int j;
        while(bMax>=bMin)
        {
            i = (bMin + bMax) / 2;
            j = mid - i;
            if((a->data()[i]<b->data()[j-1])&&(bMax!=bMin))
            {
                bMin=i+1;
            } else if((a->data()[i-1]>b->data()[j])&&(bMax!=bMin)) {
                bMax=i-1;
            }
            else{
                int aleft= i;
                int aright = a->size()-i-1;
                int bleft =j;
                int bright =b->size()-j-1;

                int maxleft;

                if (aleft==0){
                    maxleft=b->data()[j-1];
                }else if(bleft==0){
                    maxleft=a->data()[i-1];
                } else{
                    maxleft=max(a->data()[i-1],b->data()[j-1]);
                }

                int minright;
                if(aleft==a->size()){
                    minright=b->data()[j];
                }else if (bleft==b->size()){
                    minright=a->data()[i];
                }else{
                    minright=min(a->data()[i],b->data()[j]);
                }
                if ((a->size()+b->size())%2){
                    if (aleft+bleft>aright+bright){
                        return maxleft;
                    }else{
                        return minright;
                    }
                }
                return (maxleft+minright)/2.0;
            }
        }
        return res;
    }
};

