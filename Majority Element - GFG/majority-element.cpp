//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        
        // using Moore's voting algorithm
        
        int c = 0;
        int el = arr[0];
        for(int i=0;i<size;i++) {
            if(el==arr[i]) {
                c++;
            }
            else{
                c--;
                if(c==0) {
                    el = arr[i];
                    c = 1;
                }
            }
        }
        
        c = 0;
        for(int i=0;i<size;i++) {
            if(el==arr[i]) c++;
        }
        
        return c > size/2 ? el : -1;
        
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends