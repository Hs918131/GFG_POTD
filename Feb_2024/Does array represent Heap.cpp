class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
       for(int i=0; i<n; i++) {
            int leftChild = 0, rightChild = 0;
            if(2*i+1 < n) {
                leftChild = arr[2*i+1];
            }
            if(2*i+2 < n) {
                rightChild = arr[2*i+2];
            }
            if(leftChild > arr[i] || rightChild > arr[i]) {
                return false;
            }
        }
        
        return true;
    }
};
