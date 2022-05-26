class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>arr(n+m);
        int i=0,j=0;
        int k=0;
        while(i<n&&j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                arr[k++]=nums1[i++];
            }else{
                arr[k++]=nums2[j++];
            }
        }
        while(i<n)
        {
            arr[k++]=nums1[i++];
        }
        while(j<m)
        {
            arr[k++]=nums2[j++];
        }
      
        if((n+m)%2)
        {
            return (double)(arr[(n+m)/2]);
        }
        return (double)(arr[(n+m)/2]+arr[(n+m)/2-1])/2.0;
    
    }
};